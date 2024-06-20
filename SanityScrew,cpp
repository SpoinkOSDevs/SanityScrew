#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <random>
#include <fstream>

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

int main() {
    std::vector<std::string> code;
    std::ifstream file("program.ss");
    std::string line;
    while (std::getline(file, line)) {
        code.push_back(line);
    }

    SanityScrew interpreter(code);
    interpreter.interpret();

    return 0;
}
