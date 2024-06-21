#ifndef SSJIT_H
#define SSJIT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <random>
#include <filesystem>
#include <unistd.h>
#include <chrono> // Include chrono for sleep functionality
#include <thread> // Include thread for sleep functionality

class SSJIT {
public:
    static void compileAndRun(const std::vector<std::string>& code) {
        std::string compiledCode = compile(code);
        interpret(compiledCode);
    }

private:
    static std::string compile(const std::vector<std::string>& code) {
        std::string compiledCode;
        for (const auto& line : code) {
            std::string command = extractCommand(line);
            if (command == "SET") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += "int " + varName + " = " + std::to_string(value) + ";\n";
            } else if (command == "ADD") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += varName + " += " + std::to_string(value) + ";\n";
            } else if (command == "SUB") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += varName + " -= " + std::to_string(value) + ";\n";
            } else if (command == "MULT") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += varName + " *= " + std::to_string(value) + ";\n";
            } else if (command == "DIV") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += varName + " /= " + std::to_string(value) + ";\n";
            } else if (command == "MOD") {
                std::string varName = extractVarName(line);
                int value = extractValue(line);
                compiledCode += varName + " %= " + std::to_string(value) + ";\n";
            } else if (command == "PRINT") {
                std::string varName = extractVarName(line);
                compiledCode += "std::cout << \"" + varName + ": \" << " + varName + " << std::endl;\n";
            } else if (command == "RAND") {
                std::string varName = extractVarName(line);
                int minVal = extractValue(line);
                int maxVal = extractValue(line);
                compiledCode += varName + " = rand() % (" + std::to_string(maxVal - minVal + 1) + ") + " + std::to_string(minVal) + ";\n";
            } else if (command == "IF") {
                compiledCode += "if (" + line.substr(3) + ") {\n";
            } else if (command == "ELSE") {
                compiledCode += "} else {\n";
            } else if (command == "ENDIF") {
                compiledCode += "}\n";
            } else if (command == "WHILE") {
                compiledCode += "while (" + line.substr(6) + ") {\n";
            } else if (command == "ENDWHILE") {
                compiledCode += "}\n";
            } else if (command == "INPUT") {
                std::string varName = extractVarName(line);
                compiledCode += "std::cin >> " + varName + ";\n";
            } else if (command == "SLEEP") {
                int seconds = extractValue(line);
                compiledCode += "std::this_thread::sleep_for(std::chrono::seconds(" + std::to_string(seconds) + "));\n";
            } else if (command == "WAIT") {
                int seconds = extractValue(line);
                compiledCode += "std::this_thread::sleep_for(std::chrono::seconds(" + std::to_string(seconds) + "));\n";
            } else if (command == "HIDE") {
                compiledCode += "// Hidden code segment: " + line.substr(5) + "\n";
            } else if (command == "EXIT") {
                compiledCode += "exit(0);\n";
            } else if (command == "COOK") {
                int lineToCook = extractValue(line);
                compiledCode += "code[" + std::to_string(lineToCook) + "] = cook(code[" + std::to_string(lineToCook) + "]);\n";
            } else if (command == "INJECT") {
                int val = extractValue(line);
                std::string varName = getRandomVariableName();
                int purity = rand() % 10 + 1;
                compiledCode += "variables[\"" + varName + "\"] = " + std::to_string(val * purity) + ";\n";
            } else if (command == "TRIP") {
                std::string varName = extractVarName(line);
                compiledCode += "if (variables.find(\"" + varName + "\") != variables.end()) {\n";
                compiledCode += "int tripValue = variables[\"" + varName + "\"] + (rand() % 20 - 10);\n";
                compiledCode += "std::cout << \"" + varName + " = \" << tripValue << \" (hallucinated)\" << std::endl;\n";
                compiledCode += "} else {\n";
                compiledCode += "std::cout << \"" + varName + " is undefined!\" << std::endl;\n";
                compiledCode += "}\n";
            } else if (command == "DUO") {
                compiledCode += "std::cout << \"DUO: Complete your language lessons or face the owl!\" << std::endl;\n";
                compiledCode += "if (rand() % 2) {\n";
                compiledCode += "std::cout << \"The Duolingo owl is watching you.\" << std::endl;\n";
                compiledCode += "} else {\n";
                compiledCode += "std::cout << \"The Duolingo owl is angry. Finish your lesson NOW!\" << std::endl;\n";
                compiledCode += "}\n";
            } else if (command == "RICK") {
                compiledCode += "std::cout << \"RICK: " + getRandomRickAndMortyAction() + "\" << std::endl;\n";
            } else if (command == "SPAGHETTI") {
                compiledCode += "std::cout << \"SPAGHETTI: " + getRandomSpaghettiAction() + "\" << std::endl;\n";
            } else if (command == "HEISENBERG") {
                compiledCode += "std::cout << \"HEISENBERG: Changing state unpredictably.\" << std::endl;\n";
                compiledCode += "std::random_device rd;\n";
                compiledCode += "generator.seed(rd());\n";
                compiledCode += "std::shuffle(code.begin(), code.end(), generator);\n";
            } else if (command == "EXPLODE") {
                compiledCode += "std::cout << \"EXPLODE: Modifying code sequence.\" << std::endl;\n";
                compiledCode += "for (auto& line : code) {\n";
                compiledCode += "if (rand() % 2) {\n";
                compiledCode += "line += \" EXPLODED\";\n";
                compiledCode += "}\n";
                compiledCode += "}\n";
            } else if (command == "METHHEAD") {
                compiledCode += "std::cout << \"METHHEAD: Wild behavior introduced.\" << std::endl;\n";
                compiledCode += "int randomCommand = rand() % 3;\n";
                compiledCode += "if (randomCommand == 0) HEISENBERG();\n";
                compiledCode += "else if (randomCommand == 1) EXPLODE();\n";
                compiledCode += "else if (randomCommand == 2) OVERDOSE();\n";
            } else if (command == "OVERDOSE") {
                compiledCode += "std::cout << \"OVERDOSE: Program ends abruptly.\" << std::endl;\n";
                compiledCode += "exit(0);\n";
            } else if (command == "DANCE") {
                compiledCode += "std::cout << \"DANCE: Dance like nobody's watching!\" << std::endl;\n";
            } else if (command == "SHUFFLE") {
                compiledCode += "std::cout << \"SHUFFLE: Shuffle the deck!\" << std::endl;\n";
                compiledCode += "std::random_shuffle(deck.begin(), deck.end());\n";
            } else if (command == "TEA") {
                compiledCode += "std::cout << \"TEA: Make a cup of tea.\" << std::endl;\n";
            } else if (command == "KETTLE") {
                compiledCode += "std::cout << \"KETTLE: Boil the kettle.\" << std::endl;\n";
            } else if (command == "CAR") {
                compiledCode += "std::cout << \"CAR: Drive a car.\" << std::endl;\n";
            } else if (command == "WALK") {
                compiledCode += "std::cout << \"WALK: Take a walk.\" << std::endl;\n";
            } else if (command == "WRITE") {
                compiledCode += "std::cout << \"WRITE: Write a story.\" << std::endl;\n";
            } else if (command == "READ") {
                compiledCode += "std::cout << \"READ: Read a book.\" << std::endl;\n";
            } else if (command == "COMPILE") {
                compiledCode += "std::cout << \"COMPILE: Compile the code.\" << std::endl;\n";
            } else if (command == "SING") {
                compiledCode += "std::cout << \"SING: Sing a song.\" << std::endl;\n";
            } else if (command == "TALK") {
                compiledCode += "std::cout << \"TALK: Have a conversation.\" << std::endl;\n";
            } else if (command == "THINK") {
                compiledCode += "std::cout << \"THINK: Ponder life's mysteries.\" << std::endl;\n";
            } else if (command == "EAT") {
                compiledCode += "std::cout << \"EAT: Enjoy a meal.\" << std::endl;\n";
            } else if (command == "DRINK") {
                compiledCode += "std::cout << \"DRINK: Have a drink.\" << std::endl;\n";
            } else if (command == "SWIM") {
                compiledCode += "std::cout << \"SWIM: Take a swim.\" << std::endl;\n";
            } else if (command == "FLY") {
                compiledCode += "std::cout << \"FLY: Soar through the skies.\" << std::endl;\n";
            } else if (command == "JUMP") {
                compiledCode += "std::cout << \"JUMP: Jump for joy!\" << std::endl;\n";
            } else if (command == "RUN") {
                compiledCode += "std::cout << \"RUN: Go for a run.\" << std::endl;\n";
            } else if (command == "STOP") {
                compiledCode += "std::cout << \"STOP: Stop the program.\" << std::endl;\n";
                compiledCode += "exit(0);\n";
            } else {
                compiledCode += "// Unknown Command: " + command + "\n";
            }
            // Add more commands here...
        }
        return compiledCode;
    }

    static void interpret(const std::string& compiledCode) {
        std::cout << "Compiled Code:\n" << compiledCode << "\n--- Running Compiled Code ---\n";

        std::ofstream outfile("compiled_code.cpp");
        outfile << "#include <iostream>\n";
        outfile << "#include <chrono>\n";
        outfile << "#include <thread>\n";
        outfile << "int main() {\n";
        outfile << "srand(time(NULL));\n"; // Seed the random number generator
        outfile << compiledCode;
        outfile << "return 0;\n";
        outfile << "}\n";
        outfile.close();

        system("g++ -o compiled_code compiled_code.cpp");

        if (std::filesystem::exists("compiled_code")) {
            system("./compiled_code");
            std::cout << "--- End of Compiled Code Execution ---\n";
        } else {
            std::cout << "Error: Compilation failed or executable not generated.\n";
        }
    }

    static std::string extractCommand(const std::string& line) {
        return line.substr(0, line.find(' '));
    }

    static int extractValue(const std::string& line) {
        return std::stoi(line.substr(line.find(' ') + 1));
    }

    static std::string extractVarName(const std::string& line) {
        return line.substr(line.find(' ') + 1);
    }

    static std::string getRandomVariableName() {
        static std::vector<std::string> names = {"Heisenberg", "Jesse", "Gus", "Saul"};
        return names[rand() % names.size()];
    }

    static std::string getRandomRickAndMortyAction() {
        static std::vector<std::string> actions = {
            "Wubba lubba dub dub!",
            "Get schwifty!",
            "Pickle Rick!",
            "You gotta get your shit together."
        };
        return actions[rand() % actions.size()];
    }

    static std::string getRandomSpaghettiAction() {
        static std::vector<std::string> actions = {
            "Twirl the spaghetti with the Glock-19.",
            "Shoot gummy bears at the spaghetti.",
            "The spaghetti glocks back."
        };
        return actions[rand() % actions.size()];
    }
};

#endif // SSJIT_H
