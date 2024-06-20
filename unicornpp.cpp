#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>
#include <chrono> // For delay
#include <thread> // For sleep

// Define the memory tape and pointer
char tape[30000] = {0};
char* ptr = tape;

// Variable storage
std::unordered_map<std::string, int> variables; // Map for storing variables

// Function prototypes
void interpretUnicorn(const std::string& code);
void executeOperation(char op, std::ifstream& file);
void obfuscateOperation(char& op);

// Unicorn++ interpreter
void interpretUnicorn(const std::string& code) {
    std::ifstream file(code);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + code);
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines or comments (lines starting with '#')
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Obfuscate operations (just for fun!)
        for (char& op : line) {
            obfuscateOperation(op);
        }

        // Execute operations from the line
        executeOperation(line[0], file);
    }

    file.close();
}

// Execute operations based on the first character of the line
void executeOperation(char op, std::ifstream& file) {
    switch (op) {
        case '🦄': // Increment the memory cell at the pointer
            ++*ptr;
            break;
        case '🌈': // Decrement the memory cell at the pointer
            --*ptr;
            break;
        case '🧚‍♀️': // Move the pointer to the right
            ++ptr;
            break;
        case '🐉': // Move the pointer to the left
            --ptr;
            break;
        case '🪄': // Output the character at the memory cell
            putchar(*ptr);
            break;
        case '🕳️': // Input a character and store it in the memory cell
            *ptr = getchar();
            break;
        case '📝': { // Output text (string literal)
            std::string text;
            std::getline(file, text, '7'); // Read until '7'
            std::cout << text;
            break;
        }
        case '🖍️': { // Declare or assign a variable
            std::string varName;
            int value;
            file >> varName >> value;
            variables[varName] = value;
            break;
        }
        case '🔍': { // Find operation (boolean check)
            std::string varName;
            int value;
            file >> varName >> value;
            if (variables.count(varName) && variables[varName] == value) {
                executeOperation('🦄', file); // Increment if true
            }
            break;
        }
        case '🍎': { // Input an integer and store it in a variable
            std::string varName;
            int value;
            std::cin >> value;
            file >> varName; // Read variable name
            variables[varName] = value;
            break;
        }
        case '👀': { // Output the value of a variable
            std::string varName;
            file >> varName;
            if (variables.count(varName)) {
                std::cout << variables[varName];
            } else {
                std::cerr << "Error: Variable " << varName << " not found!" << std::endl;
            }
            break;
        }
        case '✨': { // Start a loop if the current memory cell is non-zero
            if (*ptr == 0) {
                // Find the matching 💫 to skip the loop
                int loopDepth = 1;
                while (loopDepth > 0) {
                    std::getline(file, line);
                    if (line.empty() || line[0] == '#') {
                        continue;
                    }
                    if (line[0] == '✨') {
                        ++loopDepth;
                    } else if (line[0] == '💫') {
                        --loopDepth;
                    }
                }
            }
            break;
        }
        case '💫': { // End a loop if the current memory cell is non-zero
            if (*ptr != 0) {
                // Find the matching ✨ to jump back to the loop start
                int loopDepth = 1;
                std::streampos pos = file.tellg();
                while (loopDepth > 0 && std::getline(file, line)) {
                    if (line.empty() || line[0] == '#') {
                        continue;
                    }
                    if (line[0] == '💫') {
                        ++loopDepth;
                    } else if (line[0] == '✨') {
                        --loopDepth;
                    }
                }
                if (loopDepth > 0) {
                    throw std::runtime_error("Error: Unterminated loop");
                }
                file.seekg(pos); // Jump back to the loop start
            }
            break;
        }
        case '🚀': { // Launch a rocket (totally illogical!)
            std::cout << "\n🚀 Rocket launched!\n";
            break;
        }
        case '🧻': { // Use toilet paper (why not!)
            std::cout << "\n🧻 Toilet paper used!\n";
            break;
        }
        case '🎉': { // Celebrate (completely unnecessary!)
            std::cout << "\n🎉 Celebration time!\n";
            break;
        }
        case '🤖': { // Summon a robot (because logic!)
            std::cout << "\n🤖 Robot summoned!\n";
            break;
        }
        case '🛑': { // Stop everything (absolutely illogical!)
            std::cout << "\n🛑 Stop everything!\n";
            break;
        }
        case '💩': { // Output nonsense (totally absurd!)
            std::cout << "\n💩 Nonsense output!\n";
            break;
        }
        default:
            break; // Ignore any other characters
    }
}

// Stupid obfuscation function (even more illogical!)
void obfuscateOperation(char& op) {
    // Add random delays
    int delayMs = std::rand() % 50;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));

    // Swap random operations (why not!)
    switch (op) {
        case '🦄':
        case '🌈':
        case '🧚‍♀️':
        case '🐉':
        case '🪄':
        case '🕳️':
        case '📝':
        case '🖍️':
        case '🔍':
        case '🍎':
        case '👀':
        case '✨':
        case '💫':
        case '🚀':
        case '🧻':
        case '🎉':
        case '🤖':
        case '🛑':
        case '💩':
            break; // Leave as is
        default:
            // Swap with a random operation
            char newOp = "🦄🌈🧚‍♀️🐉🪄🕳️📝🖍️🔍🍎👀✨💫🚀🧻🎉🤖🛑💩"[std::rand() % 20];
            op = newOp;
            break;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [-C|-R] <filename.unicorn>" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string filename;

    if (argc == 3) {
        filename = argv[2];
    } else {
        std::cerr << "Error: Missing filename argument" << std::endl;
        return 1;
    }

    try {
        if (option == "-C") {
            // Compilation mode (just for show, doesn't actually compile anything!)
            std::cout << "Compiling " << filename << "..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Compilation successful. Created a mess of files!" << std::endl;
        } else if (option == "-R") {
            // Run mode (execute the Unicorn++ program)
            interpretUnicorn(filename);
        } else {
            std::cerr << "Error: Unknown option '" << option << "'" << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
