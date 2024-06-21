#include "SSJIT.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::vector<std::string> code;
    std::ifstream file(argv[1]);
    std::string line;
    while (std::getline(file, line)) {
        code.push_back(line);
    }

    SSJIT::compileAndRun(code);

    return 0;
}
