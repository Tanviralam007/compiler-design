#include "../include/lexer.h"
#include <regex>
#include <iostream>

Lexer::Lexer(const std::string &input) {
    this->input = input;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    // regex to capture all relevant tokens
    std::regex tokenRegex("(<add>|</add>|<sub>|</sub>|<mul>|</mul>|<div>|</div>|,|[0-9]+)");
    auto begin = std::sregex_iterator(input.begin(), input.end(), tokenRegex);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it) {
        std::string tokenStr = it->str();
        Token token;
        
        // use it->position() to get the start position of the token
        int pos = it->position();
        int line = 1;
        int column = 1;
        // compute line and column numbers by scanning from the start to pos
        for (int i = 0; i < pos; ++i) {
            if (input[i] == '\n') {
                ++line;
                column = 1;
            } else {
                ++column;
            }
        }
        token.line = line;
        token.column = column;
        
        if (tokenStr == "<add>") {
            token.type = TOKEN_ADD_OPEN;
        } else if (tokenStr == "</add>") {
            token.type = TOKEN_ADD_CLOSE;
        } else if (tokenStr == "<sub>") {
            token.type = TOKEN_SUB_OPEN;
        } else if (tokenStr == "</sub>") {
            token.type = TOKEN_SUB_CLOSE;
        } else if (tokenStr == "<mul>") {
            token.type = TOKEN_MUL_OPEN;
        } else if (tokenStr == "</mul>") {
            token.type = TOKEN_MUL_CLOSE;
        } else if (tokenStr == "<div>") {
            token.type = TOKEN_DIV_OPEN;
        } else if (tokenStr == "</div>") {
            token.type = TOKEN_DIV_CLOSE;
        } else if (tokenStr == ",") {
            token.type = TOKEN_COMMA;
        } else if (std::regex_match(tokenStr, std::regex("[0-9]+"))) {
            token.type = TOKEN_NUMBER;
            token.value = tokenStr;
        } else {
            token.type = TOKEN_UNKNOWN;
        }
        tokens.push_back(token);
    }
    return tokens;
}