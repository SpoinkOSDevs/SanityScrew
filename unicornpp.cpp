#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// Unicorn++ interpreter and compiler
void interpretUnicorn(const std::string& code, const std::string& filename) {
    std::ofstream outFile(filename + ".cpp");
    if (!outFile.is_open()) {
        throw std::runtime_error("Error: Could not create output file " + filename + ".cpp");
    }

    outFile << "#include <iostream>\n";
    outFile << "int main() {\n";
    outFile << "char tape[30000] = {0};\n";
    outFile << "char* ptr = tape;\n";

    size_t i = 0;
    while (i < code.size()) {
        switch (code[i]) {
            case '🦄': // Increment the memory cell at the pointer
                outFile << "++*ptr;\n";
                break;
            case '🌈': // Decrement the memory cell at the pointer
                outFile << "--*ptr;\n";
                break;
            case '🧚‍♀️': // Move the pointer to the right
                outFile << "++ptr;\n";
                break;
            case '🐉': // Move the pointer to the left
                outFile << "--ptr;\n";
                break;
            case '🪄': // Output the character at the memory cell
                outFile << "putchar(*ptr);\n";
                break;
            case '🕳️': // Input a character and store it in the memory cell
                outFile << "*ptr = getchar();\n";
                break;
            case '✨': { // Start a loop if the current memory cell is non-zero
                outFile << "while (*ptr) {\n";
                break;
            }
            case '💫': { // End a loop if the current memory cell is non-zero
                outFile << "}\n";
                break;
            }
            default:
                break; // Ignore any other characters
        }
        ++i;
    }

    outFile << "return 0;\n";
    outFile << "}\n";
    outFile.close();

    // Compile to binary executable
    std::string compileCommand = "g++ -o " + filename + " " + filename + ".cpp";
    int compileStatus = system(compileCommand.c_str());
    if (compileStatus != 0) {
        throw std::runtime_error("Error: Compilation failed");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <filename.unicorn> <output_executable>" << std::endl;
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
        interpretUnicorn(code, argv[2]);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Compilation successful. Executable '" << argv[2] << "' created." << std::endl;

    return 0;
}
