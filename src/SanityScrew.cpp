#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <random>
#include <filesystem>
#include <unistd.h>

class CompilerInterpreter {
    std::vector<std::string> code;
    std::default_random_engine generator;
    std::map<std::string, int> variables;
    std::map<std::string, bool> weirdBools;

public:
    CompilerInterpreter(const std::vector<std::string>& sourceCode) : code(sourceCode) {
        std::random_device rd;
        generator.seed(rd());
        srand(time(0));
    }

    void compileAndRun() {
        std::string compiledCode = compile();
        interpret(compiledCode);
    }

private:
    std::string compile() {
        std::string compiledCode;
        for (const auto& line : code) {
            std::string command = extractCommand(line);
            if (command == "SET") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                variables[varName] = value;
            } else if (command == "ADD") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                variables[varName] += value;
            } else if (command == "SUB") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                variables[varName] -= value;
            } else if (command == "PRINT") {
                std::string varName = extractVarName(line);
                compiledCode += "std::cout << \"" + varName + ": \" << variables[\"" + varName + "\"] << std::endl;\n";
            } else if (command == "RAND") {
                std::string varName = extractVarName(line);
                int minVal = extractValue(line);
                int maxVal = extractValue(line);
                compiledCode += "variables[\"" + varName + "\"] = rand() % (" + std::to_string(maxVal - minVal + 1) + ") + " + std::to_string(minVal) + ";\n";
            } else if (command == "DEEPFRY") {
                deepFry();
            } else if (command == "CHOMP") {
                chomp(line);
            } else if (command == "SPAGHETTIFY") {
                spaghettify(line);
            } else if (command == "FLIP") {
                flip(code);
            } else if (command == "REPEAT") {
                repeat(line);
            } else if (command == "VORTEX") {
                vortex();
            } else if (command == "GLITCH") {
                glitch();
            } else if (command == "EXPLOSION") {
                explosion();
            } else if (command == "BOOL") {
                std::string boolName = extractVarName(line);
                bool value = extractBoolValue(line);
                weirdBools[boolName] = value;
            } else if (command == "IFBOOL") {
                ifBool(line);
            } else if (command == "FIND") {
                find(line);
            } else if (command == "SLEEP") {
                sleep(line);
            } else if (command == "WAIT") {
                wait(line);
            } else if (command == "HIDE") {
                hide(line);
            } else if (command == "SHOW") {
                show(line);
            } else if (command == "DELETE") {
                del(line);
            } else if (command == "ECHO") {
                echo(line);
            } else if (command == "SWAP") {
                swapVars(line);
            } else if (command == "REVERSE") {
                reverseCode();
            } else if (command == "SORT") {
                sortCode();
            } else if (command == "CLEAR") {
                clearCode();
            } else if (command == "REPLACE") {
                replace(line);
            } else if (command == "INVERT") {
                invertBool(line);
            }
            // Add more commands here...
        }
        return compiledCode;
    }

    void interpret(const std::string& compiledCode) {
        std::cout << "Compiled Code:\n" << compiledCode << "\n--- Running Compiled Code ---\n";

        system("g++ -o compiled_code compiled_code.cpp");
        std::ifstream infile("compiled_code.cpp");
        std::ofstream outfile("compiled_code.cpp.tmp");
        std::string line;
        while (std::getline(infile, line)) {
            if (line == "// ### Compiled Code ###")
                outfile << compiledCode << "\n";
            else
                outfile << line << "\n";
        }
        infile.close();
        outfile.close();

        system("mv compiled_code.cpp.tmp compiled_code.cpp");
        system("g++ -o compiled_code compiled_code.cpp");
        system("./compiled_code");

        std::cout << "--- End of Compiled Code Execution ---\n";
    }

    std::string extractCommand(const std::string& line) {
        return line.substr(0, line.find(' '));
    }

    int extractValue(const std::string& line) {
        return std::stoi(line.substr(line.find(' ') + 1));
    }

    std::string extractVarName(const std::string& line) {
        return line.substr(line.find(' ') + 1);
    }

    bool extractBoolValue(const std::string& line) {
        return line.find("true") != std::string::npos;
    }

    void deepFry() {
        std::cout << "DEEPFRY: Adding more randomness and chaos!" << std::endl;
        generator.seed(rand()); // Randomize the random number generator
    }

    void chomp(const std::string& line) {
        std::cout << "CHOMP: Removing a random character from the line." << std::endl;
        if (!line.empty()) {
            int pos = rand() % line.size();
            code.push_back(line.substr(0, pos) + line.substr(pos + 1));
        }
    }

    void spaghettify(const std::string& line) {
        std::cout << "SPAGHETTIFY: Transforming the line into spaghetti." << std::endl;
        std::string spaghetti;
        for (char c : line) {
            spaghetti += c;
            spaghetti += " ";
        }
        code.push_back(spaghetti);
    }

    void flip(std::vector<std::string>& code) {
        std::cout << "FLIP: Flipping the entire code upside down!" << std::endl;
        std::reverse(code.begin(), code.end());
    }

    void repeat(const std::string& line) {
        std::cout << "REPEAT: Repeating the line multiple times." << std::endl;
        int times = rand() % 5 + 1;
        for (int i = 0; i < times; ++i) {
            code.push_back(line);
        }
    }

    void vortex() {
        std::cout << "VORTEX: Creating a vortex of chaos!" << std::endl;
        for (int i = 0; i < 10; ++i) {
            int pos1 = rand() % code.size();
            int pos2 = rand() % code.size();
            std::swap(code[pos1], code[pos2]);
        }
    }

    void glitch() {
        std::cout << "GLITCH: Introducing glitches into the code." << std::endl;
        for (auto& line : code) {
            if (rand() % 2) {
                line += " (glitched)";
            }
        }
    }

    void explosion() {
        std::cout << "EXPLOSION: Creating a chaotic explosion!" << std::endl;
        std::vector<std::string> newCode;
        for (const auto& line : code) {
            newCode.push_back(line);
            newCode.push_back("BOOM!");
        }
        code = newCode;
    }

    void ifBool(const std::string& line) {
        std::string boolName = extractVarName(line);
        if (weirdBools.find(boolName) != weirdBools.end() && weirdBools[boolName]) {
            std::cout << "IFBOOL: Bool condition is true!" << std::endl;
        } else {
            std::cout << "IFBOOL: Bool condition is false!" << std::endl;
        }
    }

    void find(const std::string& line) {
        std::string target = extractVarName(line);
        auto it = std::find(code.begin(), code.end(), target);
        if (it != code.end()) {
            std::cout << "FIND: Target found in code!" << std::endl;
        } else {
            std::cout << "FIND: Target not found in code!" << std::endl;
        }
    }

    // Additional commands
    void sleep(const std::string& line) {
        int seconds = extractValue(line);
        std::cout << "SLEEP: Sleeping for " << seconds << " seconds." << std::endl;
        usleep(seconds * 1000000); // Sleep in microseconds
    }

    void wait(const std::string& line) {
        int seconds = extractValue(line);
        std::cout << "WAIT: Waiting for " << seconds << " seconds." << std::endl;
        for (int i = 0; i < seconds; ++i) {
            std::cout << i + 1 << " seconds passed." << std::endl;
            sleep(1); // Wait for 1 second
        }
    }

    void hide(const std::string& line) {
        std::string varName = extractVarName(line);
        variables.erase(varName);
        std::cout << "HIDE: Variable '" << varName << "' removed." << std::endl;
    }

    void show(const std::string& line) {
        std::string varName = extractVarName(line);
        if (variables.find(varName) != variables.end()) {
            std::cout << "SHOW: Variable '" << varName << "' value: " << variables[varName] << std::endl;
        } else {
            std::cout << "SHOW: Variable '" << varName << "' not found." << std::endl;
        }
    }

    void del(const std::string& line) {
        std::string varName = extractVarName(line);
        if (variables.find(varName) != variables.end()) {
            variables.erase(varName);
            std::cout << "DELETE: Variable '" << varName << "' deleted." << std::endl;
        } else {
            std::cout << "DELETE: Variable '" << varName << "' not found." << std::endl;
        }
    }

    void echo(const std::string& line) {
        std::cout << "ECHO: " << line << std::endl;
    }

    void swapVars(const std::string& line) {
        std::string var1 = line.substr(0, line.find(' '));
        std::string var2 = line.substr(line.find(' ') + 1);
        if (variables.find(var1) != variables.end() && variables.find(var2) != variables.end()) {
            std::swap(variables[var1], variables[var2]);
            std::cout << "SWAP: Variables '" << var1 << "' and '" << var2 << "' swapped." << std::endl;
        } else {
            std::cout << "SWAP: One or both variables not found." << std::endl;
        }
    }

    void reverseCode() {
        std::cout << "REVERSE: Reversing the entire code!" << std::endl;
        std::reverse(code.begin(), code.end());
    }

    void sortCode() {
        std::cout << "SORT: Sorting the code alphabetically!" << std::endl;
        std::sort(code.begin(), code.end());
    }

    void clearCode() {
        std::cout << "CLEAR: Clearing the code!" << std::endl;
        code.clear();
    }

    void replace(const std::string& line) {
        std::string target = line.substr(0, line.find(' '));
        std::string replacement = line.substr(line.find(' ') + 1);
        std::replace(code.begin(), code.end(), target, replacement);
        std::cout << "REPLACE: Replacing '" << target << "' with '" << replacement << "'." << std::endl;
    }

    void invertBool(const std::string& line) {
        std::string boolName = extractVarName(line);
        if (weirdBools.find(boolName) != weirdBools.end()) {
            weirdBools[boolName] = !weirdBools[boolName];
            std::cout << "INVERT: Bool '" << boolName << "' inverted." << std::endl;
        } else {
            std::cout << "INVERT: Bool '" << boolName << "' not found." << std::endl;
        }
    }
};

int main(int argc, char *argv[]) {
    if (argc != 3 || std::string(argv[1]) != "-FIFC") {
        std::cerr << "Usage: " << argv[0] << " -FIFC <filename>\n";
        return 1;
    }

    std::ifstream file(argv[2]);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::vector<std::string> code;
    std::string line;
    while (std::getline(file, line)) {
        code.push_back(line);
    }

    CompilerInterpreter ci(code);
    ci.compileAndRun();

    // Copy the executable to SanityScrew1
    std::string executableName = argv[0];
    std::filesystem::path currentPath = std::filesystem::path(executableName).parent_path();
    std::filesystem::path sanityScrew1Path = currentPath / "SanityScrew1";
    std::filesystem::copy_file(executableName, sanityScrew1Path, std::filesystem::copy_options::overwrite_existing);

    // Move SanityScrew1 to /usr/local/bin
    std::filesystem::path destinationPath = "/usr/local/bin/SanityScrew";
    std::filesystem::rename(sanityScrew1Path, destinationPath);

    std::cout << "SanityScrew executable copied to SanityScrew1 and moved to /usr/local/bin/SanityScrew\n";

    return 0;
}
