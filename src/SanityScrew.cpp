#include <iostream>
#include <fstream>
#include <vector>
#include "SSJIT.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file.ss>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open input file " << inputFile << "\n";
        return 1;
    }

    std::vector<std::string> code;
    std::string line;
    while (std::getline(file, line)) {
        code.push_back(line);
    }

    SSJIT::compileAndRun(code);

    return 0;
}
