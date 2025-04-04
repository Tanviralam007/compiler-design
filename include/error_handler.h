#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

class ErrorHandler {
public:
    // Report error with optional line and column numbers
    static void reportError(const std::string &msg, int line = -1, int column = -1) {
        std::string errorMsg;
        if (line != -1 && column != -1) {
            errorMsg = "Error at line " + std::to_string(line) + ", column " + std::to_string(column) + ": " + msg;
        } else {
            errorMsg = "Error: " + msg;
        }
        std::cerr << errorMsg << std::endl;
        logError(errorMsg);
        exit(1);
    }

private:
    // Log error to a file
    static void logError(const std::string &msg) {
        std::ofstream logFile("error.log", std::ios::app);
        if (logFile.is_open()) {
            logFile << msg << std::endl;
            logFile.close();
        }
    }
};

#endif // ERROR_HANDLER_H
