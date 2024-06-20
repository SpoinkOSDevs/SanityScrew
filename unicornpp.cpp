#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// Unicorn++ interpreter
void interpretUnicorn(const std::string& code) {
    std::vector<int> memory(30000, 0);
    int pointer = 0;
    std::vector<size_t> loopStack;

    for (size_t i = 0; i < code.size(); ++i) {
        char cmd = code[i];
        switch (cmd) {
            case '🦄': // Increment the memory cell at the pointer
                ++memory[pointer];
                break;
            case '🌈': // Decrement the memory cell at the pointer
                --memory[pointer];
                break;
            case '🧚‍♀️': // Move the pointer to the right
                ++pointer;
                if (pointer >= memory.size()) pointer = 0; // Wrap around
                break;
            case '🐉': // Move the pointer to the left
                if (pointer == 0) pointer = memory.size() - 1; // Wrap around
                else --pointer;
                break;
            case '🪄': // Output the character at the memory cell
                std::cout << static_cast<char>(memory[pointer]);
                break;
            case '🕳️': // Input a character and store it in the memory cell
                memory[pointer] = std::cin.get();
                break;
            case '✨': // Start a loop if the current memory cell is non-zero
                if (memory[pointer] == 0) {
                    int openBrackets = 1;
                    while (openBrackets != 0) {
                        ++i;
                        if (code[i] == '✨') ++openBrackets;
                        if (code[i] == '💫') --openBrackets;
                    }
                } else {
                    loopStack.push_back(i);
                }
                break;
            case '💫': // End a loop if the current memory cell is non-zero
                if (memory[pointer] != 0) {
                    i = loopStack.back();
                } else {
                    loopStack.pop_back();
                }
                break;
            default:
                break; // Ignore any other characters
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.unicorn>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    try {
        interpretUnicorn(code);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
