#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include "SSJIT.h"

const std::string tmpDir = "/tmp";
const std::string compiledFileName = "compiled_code.cpp";
const std::string compiledBinName = "compiled_code";

bool compileToBinary(const std::vector<std::string>& code) {
    std::string compiledCode;

    for (const auto& line : code) {
        // Translate all SanityScrew commands to C++ code
        if (!line.empty() && line.substr(0, 2) == "SS") {
            std::string command = line.substr(2, line.find(' ')-2); // Extract command
            std::string argument = line.substr(line.find(' ')+1); // Extract argument

            if (command == "PRINT") {
                compiledCode += "std::cout << \"" + argument + "\" << std::endl;\n";
            } else if (command == "INPUT") {
                compiledCode += "std::string input_" + argument + ";\n";
                compiledCode += "std::cout << \"" + argument + ": \";\n";
                compiledCode += "std::getline(std::cin, input_" + argument + ");\n";
            } else if (command == "IF") {
                compiledCode += "if (" + argument + ") {\n";
            } else if (command == "ELSE") {
                compiledCode += "} else {\n";
            } else if (command == "ENDIF") {
                compiledCode += "}\n";
            } else if (command == "WHILE") {
                compiledCode += "while (" + argument + ") {\n";
            } else if (command == "ENDWHILE") {
                compiledCode += "}\n";
            } else if (command == "FOR") {
                std::string iteratorName = argument.substr(0, argument.find(' '));
                std::string loopRange = argument.substr(argument.find(' ')+1);
                compiledCode += "for (int " + iteratorName + " = 0; " + iteratorName + " < " + loopRange + "; ++" + iteratorName + ") {\n";
            } else if (command == "ENDFOR") {
                compiledCode += "}\n";
            } else if (command == "FUNCTION") {
                compiledCode += "void " + argument + "() {\n";
            } else if (command == "ENDFUNCTION") {
                compiledCode += "}\n";
            } else if (command == "RETURN") {
                compiledCode += "return " + argument + ";\n";
            } else if (command == "BREAK") {
                compiledCode += "break;\n";
            } else if (command == "CONTINUE") {
                compiledCode += "continue;\n";
            } else if (command == "COOK") {
                int lineToCook = std::stoi(argument);
                compiledCode += "// COOK command: Reverse a line of code\n";
                compiledCode += "std::string cookedLine = code[" + std::to_string(lineToCook) + "];\n";
                compiledCode += "std::reverse(cookedLine.begin(), cookedLine.end());\n";
                compiledCode += "code[" + std::to_string(lineToCook) + "] = cookedLine;\n";
            } else if (command == "INJECT") {
                std::string varName = argument.substr(0, argument.find(' '));
                std::string value = argument.substr(argument.find(' ')+1);
                compiledCode += "// INJECT command: Inject value into a variable with random purity\n";
                compiledCode += "int purity = rand() % 10 + 1;\n";
                compiledCode += "variables[\"" + varName + "\"] = std::stoi(\"" + value + "\") * purity;\n";
            } else if (command == "TRIP") {
                std::string varName = argument;
                compiledCode += "// TRIP command: Generate hallucinated values for a variable\n";
                compiledCode += "int tripValue = variables[\"" + varName + "\"] + (rand() % 20 - 10);\n";
            } else if (command == "DUO") {
                compiledCode += "// DUO command: An interactive dialogue with the Duolingo owl\n";
                compiledCode += "std::cout << \"DUO: Complete your language lessons or face the owl!\" << std::endl;\n";
                compiledCode += "if (rand() % 2) {\n";
                compiledCode += "    std::cout << \"The Duolingo owl is watching you.\" << std::endl;\n";
                compiledCode += "} else {\n";
                compiledCode += "    std::cout << \"The Duolingo owl is angry. Finish your lesson NOW!\" << std::endl;\n";
                compiledCode += "}\n";
            } else if (command == "RICK") {
                compiledCode += "// RICK command: Random Rick and Morty quotes\n";
                compiledCode += "std::cout << \"RICK: " + SSJIT::getRandomRickAndMortyAction() + "\" << std::endl;\n";
            } else if (command == "SPAGHETTI") {
                compiledCode += "// SPAGHETTI command: Random spaghetti-related actions\n";
                compiledCode += "std::cout << \"SPAGHETTI: " + SSJIT::getRandomSpaghettiAction() + "\" << std::endl;\n";
            } else if (command == "HEISENBERG") {
                compiledCode += "// HEISENBERG command: Change program state unpredictably\n";
                compiledCode += "std::shuffle(code.begin(), code.end(), generator);\n";
            } else if (command == "EXPLODE") {
                compiledCode += "// EXPLODE command: Modify code sequence unpredictably\n";
                compiledCode += "for (auto& line : code) {\n";
                compiledCode += "    if (rand() % 2) {\n";
                compiledCode += "        line += \" EXPLODED\";\n";
                compiledCode += "    }\n";
                compiledCode += "}\n";
            } else if (command == "METHHEAD") {
                compiledCode += "// METHHEAD command: Introduce wild behavior\n";
                compiledCode += "int randomCommand = rand() % 3;\n";
                compiledCode += "if (randomCommand == 0) HEISENBERG();\n";
                compiledCode += "else if (randomCommand == 1) EXPLODE();\n";
                compiledCode += "else if (randomCommand == 2) OVERDOSE();\n";
            } else if (command == "OVERDOSE") {
                compiledCode += "// OVERDOSE command: Abruptly end program execution\n";
                compiledCode += "exit(0);\n";
            } else {
                // Handle unknown SanityScrew commands
                compiledCode += "// Unknown Command: " + line + "\n";
            }
        }
    }

    // Create a temporary directory if it doesn't exist
    if (!std::filesystem::exists(tmpDir)) {
        if (!std::filesystem::create_directory(tmpDir)) {
            std::cerr << "Error: Failed to create temporary directory.\n";
            return false;
        }
    }

    std::ofstream outfile(tmpDir + "/" + compiledFileName);
    outfile << "#include <iostream>\n";
    outfile << "#include <vector>\n";
    outfile << "#include <cstdlib>\n";
    outfile << "#include <ctime>\n";
    outfile << "#include <algorithm>\n";
    outfile << "#include <random>\n";
    outfile << "std::vector<std::string> code;\n";
    outfile << "std::map<std::string, int> variables;\n";
    outfile << "std::default_random_engine generator;\n";
    outfile << "void HEISENBERG() {}\n"; // Placeholder function
    outfile << "void EXPLODE() {}\n"; // Placeholder function
    outfile << "void OVERDOSE() {}\n"; // Placeholder function
    outfile << "int main() {\n";
    outfile << "srand(time(NULL));\n"; // Seed the random number generator
    outfile << compiledCode;
    outfile << "return 0;\n";
    outfile << "}\n";
    outfile.close();

    std::string compileCommand = "g++ -o " + tmpDir + "/" + compiledBinName + " " + tmpDir + "/" + compiledFileName;
    int compileResult = system(compileCommand.c_str());
    if (compileResult == 0) {
        std::cout << "Compilation successful.\n";
        return true;
    } else {
        std::cerr << "Error: Compilation failed.\n";
        return false;
    }
}

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

    if (compileToBinary(code)) {
        // Move the compiled binary to current directory
        std::string moveCommand = "mv " + tmpDir + "/" + compiledBinName + " .";
        int moveResult = system(moveCommand.c_str());
        if (moveResult == 0) {
            std::cout << "Compiled binary moved to current directory.\n";
        } else {
            std::cerr << "Error: Failed to move compiled binary.\n";
        }
    }

    return 0;
}
