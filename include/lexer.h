#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Define token types for our DSL.
enum TokenType {
    TOKEN_ADD_OPEN,
    TOKEN_ADD_CLOSE,
    TOKEN_SUB_OPEN,
    TOKEN_SUB_CLOSE,
    TOKEN_MUL_OPEN,
    TOKEN_MUL_CLOSE,
    TOKEN_DIV_OPEN,
    TOKEN_DIV_CLOSE,
    TOKEN_NUMBER,
    TOKEN_COMMA,
    TOKEN_UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
public:
    Lexer(const std::string &input);
    std::vector<Token> tokenize();
private:
    std::string input;
};

#endif // LEXER_H
