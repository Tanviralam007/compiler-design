#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/code_generator.h"
#include "../include/error_handler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

// function to read the entire file into a string
std::string readFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        ErrorHandler::reportError("Unable to open " + filename);
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        ErrorHandler::reportError("Usage: <program> <input_file.html>");
    }
    
    std::string inputFile = argv[1];
    std::string inputContent = readFile(inputFile);
    
    // extract the content inside the <body> tag
    std::regex bodyRegex("<body>([\\s\\S]*?)</body>", std::regex::icase);
    std::smatch bodyMatch;
    if (std::regex_search(inputContent, bodyMatch, bodyRegex)) {
        inputContent = bodyMatch[1].str();
    } else {
        ErrorHandler::reportError("No <body> tag found in the input file");
    }
    
    // lexical analysis -> Tokenize the extracted content
    Lexer lexer(inputContent);
    std::vector<Token> tokens = lexer.tokenize();
    
    // parsing -> Build the arithmetic operations from the tokens
    Parser parser(tokens);
    std::vector<Operation> operations = parser.parse();
    
    // code generation -> Produce the output C++ program
    CodeGenerator codeGen(operations);
    std::string generatedCode = codeGen.generate();
    
    // write the generated code to the output.cpp file
    std::ofstream outFile("output.cpp");
    if (!outFile) {
        ErrorHandler::reportError("Unable to create output.cpp");
    }
    outFile << generatedCode;
    outFile.close();
    
    std::cout << "--- generation completed ---" << std::endl;
    return 0;
}