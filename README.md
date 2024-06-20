## Unicorn++ Documentation

### Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Language Syntax](#language-syntax)
4. [Examples](#examples)
5. [Running Unicorn++ Programs](#running-unicorn-programs)
6. [FAQ](#faq)

---

### Introduction
Unicorn++ is an absurd programming language designed for maximum whimsy and minimal practicality. Inspired by Brainf*ck and Whitespace, Unicorn++ uses emojis and whimsical symbols for its commands, making programming both fun and challenging.

---

### Installation

#### Requirements
- g++ (GNU Compiler Collection)
- bash (Bourne Again Shell)

#### Steps

1. **Download the Source Code**

   Save the Unicorn++ interpreter code in a file named `unicornpp.cpp`.

   ```cpp
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
   ```

2. **Create an Installer Script**

   Save the following script as `install.sh`:

   ```sh
   #!/bin/bash

   # Compile the Unicorn++ interpreter
   g++ -o unicornpp unicornpp.cpp

   # Move the interpreter to /usr/local/bin
   sudo mv unicornpp /usr/local/bin

   # Make the interpreter executable
   sudo chmod +x /usr/local/bin/unicornpp

   echo "Unicorn++ has been installed. You can run your .unicorn files using 'unicornpp <filename.unicorn>'"
   ```

3. **Run the Installer**

   Ensure the installer script is executable and run it:

   ```sh
   chmod +x install.sh
   ./install.sh
   ```

---

### Language Syntax

#### Commands
- `🦄`: Increment the memory cell at the pointer.
- `🌈`: Decrement the memory cell at the pointer.
- `🧚‍♀️`: Move the pointer to the right.
- `🐉`: Move the pointer to the left.
- `🪄`: Output the character at the memory cell.
- `🕳️`: Input a character and store it in the memory cell.
- `✨`: Start a loop if the current memory cell is non-zero.
- `💫`: End a loop if the current memory cell is non-zero.

---

### Examples

#### Hello World
The following Unicorn++ program outputs "Hello":

Save this code in `hello.unicorn`:

```
🦄🦄🦄🦄🦄🦄🦄🦄🦄🦄✨🧚‍♀️🦄🦄🦄🦄🦄🦄🪄🧚‍♀️🦄🦄🦄🪄🧚‍♀️🪄🧚‍♀️🦄🦄🦄🪄🧚‍♀️🦄🪄🧚‍♀️🪄🐉🐉🌈💫
```

#### Increment and Print a Character
The following Unicorn++ program increments the first memory cell by 1 and prints it:

Save this code in `increment.unicorn`:

```
🦄🪄
```

---

### Running Unicorn++ Programs

To run a Unicorn++ program, use the `unicornpp` command followed by the filename:

```sh
unicornpp hello.unicorn
```

---

### FAQ

**Q: What is the purpose of Unicorn++?**

A: Unicorn++ is a whimsical and absurd programming language created for fun and entertainment. It is not intended for serious programming tasks.

**Q: What are the limitations of Unicorn++?**

A: Unicorn++ is a minimalist language with a limited set of commands. It is inspired by Brainf*ck and Whitespace and is not suited for complex programming projects.

**Q: How can I contribute to Unicorn++?**

A: Contributions are welcome! You can enhance the interpreter, add new features, or create more absurd programs. Feel free to fork the project on GitHub and submit pull requests.

---
