#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <random>
#include <fstream>
#include <unistd.h>

class SanityScrew {
    std::map<std::string, int> variables;
    std::vector<std::string> code;
    std::default_random_engine generator;

public:
    SanityScrew(const std::vector<std::string>& sourceCode) : code(sourceCode) {
        std::random_device rd;
        generator.seed(rd());
        srand(time(0));
    }

    void interpret() {
        std::shuffle(code.begin(), code.end(), generator); // Shuffle the code to make order irrelevant

        for (size_t i = 0; i < code.size(); ++i) {
            std::string line = code[i];
            if (line.empty() || line.substr(0, 3) == "--!") continue; // Skip empty lines and comments

            std::string command = extractCommand(line);

            if (command == "COOK") {
                int lineToCook = extractValue(line);
                if (lineToCook < code.size()) {
                    std::string cookedLine = code[lineToCook];
                    cookedLine = cook(cookedLine);
                    code[lineToCook] = cookedLine;
                    std::cout << "Cooked line " << lineToCook << ": " << cookedLine << std::endl;
                }
            } else if (command == "INJECT") {
                int val = extractValue(line);
                std::string varName = getRandomVariableName();
                int purity = rand() % 10 + 1; // Random multiplier for "purity"
                variables[varName] = val * purity;
                std::cout << "Injected " << val << " into " << varName << " with purity " << purity << std::endl;
            } else if (command == "TRIP") {
                std::string varName = extractVarName(line);
                if (variables.find(varName) != variables.end()) {
                    int tripValue = variables[varName] + (rand() % 20 - 10); // Random hallucination effect
                    std::cout << varName << " = " << tripValue << " (hallucinated)" << std::endl;
                } else {
                    std::cout << varName << " is undefined!" << std::endl;
                }
            } else if (command == "DUO") {
                std::cout << "DUO: Complete your language lessons or face the owl!" << std::endl;
                if (rand() % 2) {
                    std::cout << "The Duolingo owl is watching you." << std::endl;
                } else {
                    std::cout << "The Duolingo owl is angry. Finish your lesson NOW!" << std::endl;
                }
            } else if (command == "RICK") {
                std::cout << "RICK: " << getRandomRickAndMortyAction() << std::endl;
            } else if (command == "SPAGHETTI") {
                std::cout << "SPAGHETTI: " << getRandomSpaghettiAction() << std::endl;
            } else if (command == "HEISENBERG") {
                std::cout << "HEISENBERG: Changing state unpredictably." << std::endl;
                std::shuffle(code.begin(), code.end(), generator); // Reshuffle the code
            } else if (command == "EXPLODE") {
                std::cout << "EXPLODE: Modifying code sequence." << std::endl;
                for (auto& line : code) {
                    if (rand() % 2) {
                        line += " EXPLODED";
                    }
                }
            } else if (command == "METHHEAD") {
                std::cout << "METHHEAD: Wild behavior introduced." << std::endl;
                int randomCommand = rand() % 3;
                if (randomCommand == 0) HEISENBERG();
                else if (randomCommand == 1) EXPLODE();
                else if (randomCommand == 2) OVERDOSE();
            } else if (command == "OVERDOSE") {
                std::cout << "OVERDOSE: Program ends abruptly." << std::endl;
                exit(0);
            } else {
                std::cout << "UNKNOWN COMMAND: " << command << std::endl;
            }
        }
    }

private:
    std::string extractCommand(const std::string& line) {
        return line.substr(0, line.find(' '));
    }

    int extractValue(const std::string& line) {
        return std::stoi(line.substr(line.find(' ') + 1));
    }

    std::string extractVarName(const std::string& line) {
        return line.substr(line.find(' ') + 1);
    }

    std::string getRandomVariableName() {
        static std::vector<std::string> names = {"Heisenberg", "Jesse", "Gus", "Saul"};
        return names[rand() % names.size()];
    }

    std::string cook(const std::string& line) {
        // Simulate cooking by reversing the line
        std::string cookedLine = line;
        std::reverse(cookedLine.begin(), cookedLine.end());
        return cookedLine;
    }

    std::string getRandomRickAndMortyAction() {
        static std::vector<std::string> actions = {
            "Wubba lubba dub dub!",
            "Get schwifty!",
            "Pickle Rick!",
            "You gotta get your shit together."
        };
        return actions[rand() % actions.size()];
    }

    std::string getRandomSpaghettiAction() {
        static std::vector<std::string> actions = {
            "Twirl the spaghetti with the Glock-19.",
            "Shoot gummy bears at the spaghetti.",
            "The spaghetti glocks back."
        };
        return actions[rand() % actions.size()];
    }

    void HEISENBERG() {
        std::cout << "HEISENBERG: Internal method, reshuffling code." << std::endl;
        std::shuffle(code.begin(), code.end(), generator);
    }

    void EXPLODE() {
        std::cout << "EXPLODE: Internal method, modifying code." << std::endl;
        for (auto& line : code) {
            if (rand() % 2) {
                line += " EXPLODED";
            }
        }
    }

    void OVERDOSE() {
        std::cout << "OVERDOSE: Internal method, ending program." << std::endl;
        exit(0);
    }
};

void showInstaller() {
    std::cout << "SanityScrew Installer\n";
    std::cout << "=====================\n";
    std::cout << "1. Install\n";
    std::cout << "2. Exit\n";
    std::cout << "Choose an option: ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Installation complete!\n";
    } else {
        std::cout << "Installation aborted.\n";
    }
}

void showHelp() {
    std::cout << "SanityScrew Help\n";
    std::cout << "================\n";
    std::cout << "Usage: SanityScrew [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -IST                  Run the installer\n";
    std::cout << "  -FIFC <file>          Input file for compilation\n";
    std::cout << "  -OFTLD <filename>     Output filename for the compiled executable\n";
    std::cout << "  --HELPMEIMLOSINGSANITY Show this help message\n";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> code;
    std::string inputFile;
    std::string outputFile;

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-IST") {
            showInstaller();
            return 0;
        } else if (arg == "-FIFC") {
            if (i + 1 < argc) {
                inputFile = argv[++i];
            } else {
                std::cerr << "-FIFC requires a file path\n";
                return 1;
            }
        } else if (arg == "-OFTLD") {
            if (i + 1 < argc) {
                outputFile = argv[++i];
            } else {
                std::cerr << "-OFTLD requires a filename\n";
                return 1;
            }
        } else if (arg == "--HELPMEIMLOSINGSANITY") {
            showHelp();
            return 0;
        }
    }

    if (inputFile.empty() || outputFile.empty()) {
        std::cerr << "Both -FIFC and -OFTLD options must be provided\n";
        return 1;
    }

    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        code.push_back(line);
    }

    SanityScrew interpreter(code);
    interpreter.interpret();

    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error opening output file\n";
        return 1;
    }

    for (const auto& line : code) {
        outFile << line << "\n";
    }

    return 0;
}
