//
// Created by tobe on 5/5/2016.
//

#include "Token.h"

Token::Token(TokenType type, string source_text, int line_num, int pos_in_line) {
    this->type = type;
    this->source_text = source_text;
    this->line_num = line_num;
    this->pos_in_line = pos_in_line;
}

Token::Token() {

}







