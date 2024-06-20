#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

// Unicorn++ interpreter and compiler
void interpretUnicorn(const std::string& code, const std::string& filename) {
    std::ofstream outFile(filename + ".cpp");
    if (!outFile.is_open()) {
        throw std::runtime_error("Error: Could not create output file " + filename + ".cpp");
    }

    outFile << "#include <iostream>\n";
    outFile << "#include <cstdio>\n"; // For getchar and putchar
    outFile << "void unicorn_print(const char* str) {\n";
    outFile << "std::cout << str;\n";
    outFile << "}\n";
    outFile << "void unicorn_println(const char* str) {\n";
    outFile << "std::cout << str << std::endl;\n";
    outFile << "}\n";
    outFile << "void unicorn_input(char* ptr) {\n";
    outFile << "*ptr = getchar();\n";
    outFile << "}\n";
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
                outFile << "unicorn_input(ptr);\n";
                break;
            case '📝': { // Output text (string literal)
                // Find the end of the string literal
                size_t start = i + 1;
                size_t end = code.find('📝', start);
                if (end == std::string::npos) {
                    throw std::runtime_error("Error: Unterminated string literal");
                }
                std::string text = code.substr(start, end - start);
                outFile << "unicorn_print(\"" << text << "\");\n";
                i = end; // Move to the end of the string literal
                break;
            }
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
