#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>

class SymbolTable {
public:
    void addSymbol(const std::string &name, int value);
    int getSymbol(const std::string &name);
    bool contains(const std::string &name);
private:
    std::unordered_map<std::string, int> table;
};

#endif // SYMBOL_TABLE_H
