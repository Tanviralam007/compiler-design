#include "../include/parser.h"
#include "../include/error_handler.h"
#include <cstdlib>
#include <string>

Parser::Parser(const std::vector<Token> &tokens){
    this->tokens = tokens;
    current = 0;
}

bool Parser::match(TokenType type) {
    return (current < tokens.size() && tokens[current].type == type);
}

Token Parser::advance() {
    return tokens[current++];
}

std::vector<Operation> Parser::parse() {
    std::vector<Operation> operations;
    while (current < tokens.size()) {
        Operation currentOp;
        // for each expected token, check if tokens[current] exists; otherwise, use default position values
        auto currentPos = [&]() -> std::pair<int,int> {
            if (current < tokens.size())
                return { tokens[current].line, tokens[current].column };
            else
                return { -1, -1 };
        };

        if (match(TOKEN_ADD_OPEN)) {
            currentOp.op = ADD;
            advance(); // consume <add>
            
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after <add>", pos.first, pos.second);
            }
            currentOp.operand1 = std::stoi(advance().value);
            
            if (!match(TOKEN_COMMA)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a comma after the first operand in <add>", pos.first, pos.second);
            }
            advance(); // consume comma
            
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after the comma in <add>", pos.first, pos.second);
            }
            currentOp.operand2 = std::stoi(advance().value);
            
            if (!match(TOKEN_ADD_CLOSE)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected </add>", pos.first, pos.second);
            }
            advance(); // consume </add>
            operations.push_back(currentOp);
        }
        else if (match(TOKEN_SUB_OPEN)) {
            currentOp.op = SUB;
            advance(); // consume <sub>
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after <sub>", pos.first, pos.second);
            }
            currentOp.operand1 = std::stoi(advance().value);
            
            if (!match(TOKEN_COMMA)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a comma after the first operand in <sub>", pos.first, pos.second);
            }
            advance(); // consume comma
            
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after the comma in <sub>", pos.first, pos.second);
            }
            currentOp.operand2 = std::stoi(advance().value);
            
            if (!match(TOKEN_SUB_CLOSE)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected </sub>", pos.first, pos.second);
            }
            advance(); // consume </sub>
            operations.push_back(currentOp);
        }
        else if (match(TOKEN_MUL_OPEN)) {
            currentOp.op = MUL;
            advance(); // consume <mul>
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after <mul>", pos.first, pos.second);
            }
            currentOp.operand1 = std::stoi(advance().value);
            
            if (!match(TOKEN_COMMA)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a comma after the first operand in <mul>", pos.first, pos.second);
            }
            advance(); // consume comma
            
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after the comma in <mul>", pos.first, pos.second);
            }
            currentOp.operand2 = std::stoi(advance().value);
            
            if (!match(TOKEN_MUL_CLOSE)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected </mul>", pos.first, pos.second);
            }
            advance(); // consume </mul>
            operations.push_back(currentOp);
        }
        else if (match(TOKEN_DIV_OPEN)) {
            currentOp.op = DIV;
            advance(); // consume <div>
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after <div>", pos.first, pos.second);
            }
            currentOp.operand1 = std::stoi(advance().value);
            
            if (!match(TOKEN_COMMA)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a comma after the first operand in <div>", pos.first, pos.second);
            }
            advance(); // consume comma
            
            if (!match(TOKEN_NUMBER)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected a number after the comma in <div>", pos.first, pos.second);
            }
            currentOp.operand2 = std::stoi(advance().value);
            
            if (!match(TOKEN_DIV_CLOSE)) {
                auto pos = currentPos();
                ErrorHandler::reportError("Expected </div>", pos.first, pos.second);
            }
            advance(); // consume </div>
            operations.push_back(currentOp);
        }
        else {
            // skip any unexpected token
            advance();
        }
    }
    return operations;
}
