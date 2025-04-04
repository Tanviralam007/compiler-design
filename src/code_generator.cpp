#include "../include/code_generator.h"
#include <sstream>

CodeGenerator::CodeGenerator(const std::vector<Operation>& ops){
    operations = ops;
}

std::string CodeGenerator::generate() {
    std::ostringstream oss;
    oss << "#include <iostream>\n\n";
    oss << "int main() {\n";

    // generate code for each operation
    for (size_t i = 0; i < operations.size(); ++i) {
        std::string opSymbol;
        switch (operations[i].op) {
            case ADD: opSymbol = " + "; break;
            case SUB: opSymbol = " - "; break;
            case MUL: opSymbol = " * "; break;
            case DIV: opSymbol = " / "; break;
        }
        oss << "    int result" << i << " = " 
            << operations[i].operand1 << opSymbol 
            << operations[i].operand2 << ";\n";
    }
    // print out each result
    for (size_t i = 0; i < operations.size(); ++i) {
        oss << "    std::cout << \"Result " << i << ": \" << result" << i 
            << " << std::endl;\n";
    }
    oss << "    return 0;\n";
    oss << "}\n";
    return oss.str();
}
