#include <iostream>
#include <fstream>
#include <sstream>
#include "src/CliOptions.h"
#include "src/lexer/Token.h"
#include "src/lexer/ClcLexer.h"

using namespace std;

int main(int argc, char **argv) {
    CliOptions cli_options = CliOptions(argc, argv);
    ifstream *input_file;
    // The source code to run.
    stringstream ss_source_text;

    // Lexer stuff
    int line_num = 1, pos_in_line = 0;
    bool in_string = false;

    if (cli_options.input_file_name.empty()) {
        cerr << "fatal error: no input file" << endl;
        return 1;
    }
    else if (argc == 1 || cli_options.show_help) {
        return cli_options.PrintHelp();
    } else if (cli_options.show_version) {
        return cli_options.PrintVersion();
    }

    input_file = new ifstream(cli_options.input_file_name.c_str());

    if (!*input_file) {
        cerr << "fatal error: could not open file \"" << cli_options.input_file_name << "\"" << endl;
        cerr << strerror(errno) << endl;
        return errno;
    }

    ss_source_text << input_file->rdbuf();
    Token root(TokenType::ROOT_TOKEN, ss_source_text.str(), line_num, pos_in_line);
    ClcLexer::lex(&root, ss_source_text.str(), cli_options, &line_num, &pos_in_line, &in_string, TokenType::NONE);

    for (int i = 0; i < root.children.size(); i++) {
        Token token = root.children[i];
        cout << token.line_num << ":" << token.pos_in_line << " " << token.source_text << " -> (" << token.children.size() << " children)" << endl;
    }

    return 0;
}