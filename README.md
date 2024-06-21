# SSJIT Compiler

SSJIT (SanityScrew Just-In-Time) Compiler is a tool for compiling and interpreting SanityScrew language code.

## Features

- Compiles SanityScrew code into C++ code
- Interprets and executes compiled C++ code
- Supports a wide range of SanityScrew commands and functionalities

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/your_username/ssjit-compiler.git
   ```

2. Compile the SSJIT compiler:

   ```bash
   g++ -o ssjit_compiler ssjit_compiler.cpp SSJIT.h
   ```

3. Run the compiler with a SanityScrew code file:

   ```bash
   ./ssjit_compiler input_file.ss
   ```

## Usage

The SSJIT compiler takes a SanityScrew code file as input and generates an executable that interprets and executes the code.

```bash
./ssjit_compiler input_file.ss
```

## Examples

### Example 1: Hello World

Input (hello.ss):
```
PRINT Hello, World!
```

Output:
```
Hello, World!
```

### Example 2: Arithmetic Operations

Input (arithmetic.ss):
```
SET x 10
SET y 5
ADD x 5
SUB y 3
MULT x 2
DIV y 2
PRINT x
PRINT y
```

Output:
```
20
1
```

## Command Reference

- `SET <var> <value>`: Set variable to a value
- `ADD <var> <value>`: Add value to variable
- `SUB <var> <value>`: Subtract value from variable
- `MULT <var> <value>`: Multiply variable by value
- `DIV <var> <value>`: Divide variable by value
- `PRINT <var>`: Print variable value
- `RAND <var> <min> <max>`: Generate a random value between min and max and assign to variable
- `IF <condition>`: Start an if block based on condition
- `ELSE`: Else block in an if statement
- `ENDIF`: End if block
- `WHILE <condition>`: Start a while loop based on condition
- `ENDWHILE`: End while loop
- `INPUT <var>`: Input value into variable
- `SLEEP <seconds>`: Pause execution for specified seconds
- `WAIT <seconds>`: Same as SLEEP
- `HIDE <comment>`: Hide a comment in code
- `EXIT`: Exit the program
