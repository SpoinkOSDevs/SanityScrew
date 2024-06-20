#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cstdlib> // For system()

// Memory tape and pointer
constexpr int TAPE_SIZE = 30000;
char tape[TAPE_SIZE] = {0};
char* ptr = tape;

// Variable storage
std::unordered_map<std::string, int> variables;

// Base class for Unicorn++ objects
class UnicornObject {
public:
    virtual ~UnicornObject() = default;
    virtual void execute() = 0;
};

// Derived object for output operation
class OutputObject : public UnicornObject {
    std::string text;
public:
    explicit OutputObject(const std::string& t) : text(t) {}
    void execute() override {
        std::cout << text;
    }
};

// JIT execution function
void jitExecute(const std::vector<std::shared_ptr<UnicornObject>>& objects) {
    for (const auto& obj : objects) {
        obj->execute();
    }
}

// Function to interpret and JIT compile Unicorn++ code
void interpretUnicorn(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    std::vector<std::shared_ptr<UnicornObject>> objects;

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        ++lineCount;
        if (line.empty() || line[0] == '#') {
            continue;
        }

        char op = line[0];
        switch (op) {
            case '🦄': // Increment
                objects.emplace_back(std::make_shared<OutputObject>("Incrementing memory\n"));
                break;
            case '🌈': // Decrement
                objects.emplace_back(std::make_shared<OutputObject>("Decrementing memory\n"));
                break;
            case '🧚‍♀️': // Move right
                objects.emplace_back(std::make_shared<OutputObject>("Moving pointer to the right\n"));
                break;
            case '🐉': // Move left
                objects.emplace_back(std::make_shared<OutputObject>("Moving pointer to the left\n"));
                break;
            case '🪄': // Output
                objects.emplace_back(std::make_shared<OutputObject>("Outputting character\n"));
                break;
            case '🕳️': // Input
                objects.emplace_back(std::make_shared<OutputObject>("Inputting character\n"));
                break;
            case '📝': { // Output text
                std::string text = line.substr(1); // Remove the '📝'
                objects.emplace_back(std::make_shared<OutputObject>(text + "\n"));
                break;
            }
            case '🖍️': { // Variable declaration
                std::string varName = line.substr(1, line.find(' ', 1) - 1);
                int value = std::stoi(line.substr(line.find(' ', 1) + 1));
                variables[varName] = value;
                break;
            }
            case '🎠': // Random operation
                objects.emplace_back(std::make_shared<OutputObject>("Performing random operation 🎠\n"));
                break;
            default:
                std::cerr << "Warning: Unknown operation at line " << lineCount << ": " << line << std::endl;
                break; // Ignore unknown operations
        }
    }

    file.close();

    // Generate C++ code with injected Unicorn++ operations
    std::string cppCode = "#include <iostream>\n"
                          "int main() {\n"
                          "    char tape[" + std::to_string(TAPE_SIZE) + "] = {0};\n"
                          "    char* ptr = tape;\n"
                          "    std::unordered_map<std::string, int> variables;\n";

    for (const auto& obj : objects) {
        cppCode += "    // ";
        obj->execute(); // Log verbose output
    }

    cppCode += "    // TODO: Insert Unicorn++ operations here\n"
               "    return 0;\n"
               "}\n";

    std::cout << "Generated C++ code:\n" << cppCode << std::endl;

    // JIT execution of Unicorn++ code
    jitExecute(objects);
}

// Function to write C++ code to a file
void writeCppFile(const std::string& cppCode) {
    std::ofstream outputFile("UrProgram.cpp");
    if (!outputFile.is_open()) {
        throw std::runtime_error("Error: Could not create output file");
    }
    outputFile << cppCode;
    outputFile.close();
}

// Function to compile C++ code into an executable
void compileToExecutable(const std::string& cppFileName) {
    std::string compileCommand = "g++ " + cppFileName + " -o UrProgram";
    int compileResult = system(compileCommand.c_str());
    if (compileResult != 0) {
        throw std::runtime_error("Error: Compilation failed");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " [-C|-R] <filename.unicorn>" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string filename = argv[2];

    try {
        if (option == "-C") {
            // Compilation mode (generate C++ code and compile to executable)
            interpretUnicorn(filename);
            std::string cppCode = "// Generated by Unicorn++ Compiler\n" + cppCode; // Example of how to get cppCode here
            writeCppFile(cppCode);
            compileToExecutable("UrProgram.cpp");
            std::cout << "Compilation successful. Executable file created: UrProgram" << std::endl;

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
