//
// Created by tobe on 5/5/2016.
//

#include "ClcLexer.h"

void push_token(Token *root_token, TokenType *current_type, string *current_text, int *line_num, int *pos_in_line) {
    root_token->children.push_back(Token(*current_type, *current_text, *line_num, *pos_in_line));
    *current_text = "";
}

void ClcLexer::lex(Token *root_token, string source_text, CliOptions cli_options, int *line_num, int *pos_in_line,
                   bool *in_string, TokenType until = TokenType::FAILURE) {
    string current_text;
    TokenType current_type = TokenType::NONE;

    for (int i = 0; i < source_text.length(); i++) {
        current_type = TokenType::NONE;
        current_text += source_text[i];
        if (source_text[i] == '\n') {
            (*line_num)++;
            *pos_in_line = 0;
        }

        if (&current_text == nullptr) {

        } else if (!current_text.compare("end")) {
            current_type = TokenType::KEYWORD_END;
            (*pos_in_line) -= 2;
        }
        else if (!current_text.compare("fn")) {
            current_type = TokenType::KEYWORD_FN;
            (*pos_in_line)--;
            Token fn_token = Token(TokenType::KEYWORD_FN, current_text, *line_num, *pos_in_line);
            do {
                lex(&fn_token, source_text, cli_options, line_num, pos_in_line, in_string);
                cout << current_type << endl;
            } while (current_type != TokenType::KEYWORD_END);

            root_token->children.push_back(fn_token);
        } else if (!current_text.compare("ret")) {
            current_type = TokenType::KEYWORD_RET;
            (*pos_in_line) -= 2;
        }

        if (current_type != TokenType::NONE) {
            push_token(root_token, &current_type, &current_text, line_num, pos_in_line);
        }

        // Spaces will indicate a new token, unless we are lexing a quoted string.
        if (isspace(source_text[i]) && !*in_string) {
            current_text = "";
        }

        // Increment position in line
        (*pos_in_line)++;
    }
}

