#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <vector>

enum OperationType { 
    ADD, 
    SUB, 
    MUL, 
    DIV 
};

struct Operation {
    OperationType op;
    int operand1;
    int operand2;
};

class Parser {
public:
    Parser(const std::vector<Token> &tokens);
    std::vector<Operation> parse();
private:
    std::vector<Token> tokens;
    size_t current;
    bool match(TokenType type);
    Token advance();
};

#endif // PARSER_H
