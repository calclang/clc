//
// Created by tobe on 5/5/2016.
//

#ifndef CLC_TOKEN_H
#define CLC_TOKEN_H
#include <iostream>
#include <vector>

using namespace std;

enum TokenType {
    ROOT_TOKEN,
    NONE,

    FAILURE,
    KEYWORD_END,
    KEYWORD_FN,
    KEYWORD_RET,
    ID
};

class Token {
public:
    int line_num;
    int pos_in_line;
    string source_text;
    TokenType type;
    vector<Token> children;

    Token();
    Token(TokenType, string, int, int);
};


#endif //CLC_TOKEN_H
