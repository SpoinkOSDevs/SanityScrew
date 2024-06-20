---

# Unicorn++ Programming Language Documentation

## Table of Contents
1. **Introduction**
2. **Language Basics**
   - 2.1 Variables
   - 2.2 Memory Tape
   - 2.3 Input and Output
3. **Control Structures**
   - 3.1 Loops
   - 3.2 Conditionals
4. **Operations and Syntax**
   - 4.1 Operations List
   - 4.2 Syntax Rules
5. **Compilation and Execution**
   - 5.1 Compilation Steps
   - 5.2 Execution Modes
6. **Examples**
7. **Advanced Features**
   - 7.1 Object-Oriented Concepts
   - 7.2 Library Integration
8. **FAQs**
9. **Resources**

---

## 1. Introduction
Unicorn++ is a whimsical programming language designed to blend the absurdity of unicorn-related operations with the practicality of C++ syntax. It allows programmers to write code that manipulates a memory tape using magical symbols and operations.

## 2. Language Basics

### 2.1 Variables
Unicorn++ supports variable declarations using the 🖍️ symbol followed by the variable name and initial value:

```unicorn
🖍️ myVar 42
```

### 2.2 Memory Tape
The main data structure in Unicorn++ is a memory tape (`tape`) where operations manipulate the current pointer (`ptr`). It is initialized to a size of 30,000 by default.

### 2.3 Input and Output
- **Output**: Use 🪄 to output the character at the current pointer location.
- **Input**: Use 🕳️ to input a character and store it at the current pointer location.

## 3. Control Structures

### 3.1 Loops
Unicorn++ supports loops using traditional C++ syntax within its whimsical framework:

```unicorn
🌀
    🦄 // Increment
🍭
```

### 3.2 Conditionals
Currently, Unicorn++ does not support explicit conditionals but can integrate with libraries that support them.

## 4. Operations and Syntax

### 4.1 Operations List
- **🦄**: Increment the value at the current pointer.
- **🌈**: Decrement the value at the current pointer.
- **🧚‍♀️**: Move the pointer to the right.
- **🐉**: Move the pointer to the left.
- **🪄**: Output the character at the current pointer.
- **🕳️**: Input a character and store it at the current pointer.
- **📝**: Output text (followed by text to output).
- **🖍️**: Declare a variable (followed by variable name and initial value).
- **🎠**: Perform a random operation (for whimsical purposes).

### 4.2 Syntax Rules
- Every statement in Unicorn++ ends with a newline.
- Comments start with `#` and continue to the end of the line.
- Variables are global and must be declared before use.

## 5. Compilation and Execution

### 5.1 Compilation Steps
To compile Unicorn++ code:
1. **Interpretation**: Read and parse the Unicorn++ code file.
2. **Code Generation**: Generate equivalent C++ code with embedded operations.
3. **Compilation**: Compile the generated C++ code using a C++ compiler (`g++`).

### 5.2 Execution Modes
- **-C**: Compile mode generates C++ code (`UrProgram.cpp`) and compiles it to an executable (`UrProgram`).
- **-R**: Run mode interprets Unicorn++ code directly and performs operations.

## 6. Examples
### Hello World
```unicorn
📝 Hello, World!
🪄
```

### Fibonacci Sequence
```unicorn
🖍️ n 10

🖍️ a 0
🖍️ b 1
🖍️ c 0

🌀
    📝Fibonacci: 
    📝
    📝
    📝 a
    📝
    📝
    📝 b
    📝
    📝
    📝 4
    📝
    📝 5
    Output


Here is the continuation part of the Fibonacci Sequence
