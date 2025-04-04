#include "../include/symbol_table.h"
#include "../include/error_handler.h"

void SymbolTable::addSymbol(const std::string &name, int value) {
    if (table.find(name) != table.end()) {
        ErrorHandler::reportError("Symbol already exists: " + name);
    }
    table[name] = value;
}

int SymbolTable::getSymbol(const std::string &name) {
    if (table.find(name) == table.end()) {
        ErrorHandler::reportError("Symbol not found: " + name);
    }
    return table[name];
}

bool SymbolTable::contains(const std::string &name) {
    return table.find(name) != table.end();
}
