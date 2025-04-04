#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "parser.h"
#include <string>
#include <vector>

class CodeGenerator {
public:
    CodeGenerator(const std::vector<Operation>& ops);
    std::string generate();
private:
    std::vector<Operation> operations;
};

#endif // CODE_GENERATOR_H
