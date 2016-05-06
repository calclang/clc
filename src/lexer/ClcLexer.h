//
// Created by tobe on 5/5/2016.
//

#ifndef CLC_CLCLEXER_H
#define CLC_CLCLEXER_H

#include <fstream>
#include "Token.h"
#include "../CliOptions.h"

/**
 * Lexes an input stream and generates an AST.
 */
class ClcLexer {
public:
    static void lex(Token*, string, CliOptions, int *, int *, bool *, TokenType);
};


#endif //CLC_CLCLEXER_H
