---

# Unicorn++ Documentation

## Table of Contents

1. **Introduction**
   - Overview
   - Purpose
   - Features

2. **Getting Started**
   - Installation
   - Hello World Example

3. **Language Syntax**
   - Memory Operations
   - Pointer Operations
   - Input and Output
   - Control Structures

4. **Standard Library Functions**
   - `📝` - Output Text
   - `🦄` - Increment Memory Cell
   - `🌈` - Decrement Memory Cell
   - `🧚‍♀️` - Move Pointer Right
   - `🐉` - Move Pointer Left
   - `🪄` - Output Character
   - `🕳️` - Input Character
   - `✨` - Start Loop
   - `💫` - End Loop

5. **Examples**
   - Basic Examples
   - Advanced Examples

6. **Interpreter/Compiler**
   - Interpreter Features
   - Compiler Features
   - Command-Line Usage

7. **FAQs**
   - Common Issues
   - Troubleshooting

8. **Appendix**
   - Credits
   - License

---

## 1. Introduction

### Overview

Unicorn++ is an absurd and whimsical programming language inspired by esoteric languages like Brainfuck and Whitespace. It operates on a virtual tape of 30,000 memory cells and uses a pointer to manipulate and interact with these cells. Unicorn++ features a small set of unique symbols for memory manipulation, input/output operations, and control flow.

### Purpose

The primary goal of Unicorn++ is to provide a fun and challenging environment for programming enthusiasts to explore unconventional programming concepts. It encourages creativity and problem-solving through its minimalist syntax and unusual approach to computation.

### Features

- Simple and minimalistic syntax
- Memory manipulation with increment and decrement operations (`🦄`, `🌈`)
- Pointer movement (`🧚‍♀️`, `🐉`)
- Input and output operations (`🪄`, `🕳️`)
- Looping constructs (`✨`, `💫`)
- Text output (`📝`)

---

## 2. Getting Started

### Installation

Unicorn++ does not require installation of a separate runtime environment. You can directly use the provided interpreter/compiler script in any Linux environment that supports `g++`:

1. **Download** the Unicorn++ interpreter/compiler script (`unicornpp.cpp`).
2. **Compile** the script using `g++`:

   ```sh
   g++ -o unicornpp unicornpp.cpp
   ```

### Hello World Example

Create a file named `hello_world.unicorn` with the following code:

```plaintext
📝Hello, World!📝
🪄
```

Compile and execute the Unicorn++ program:

```sh
./unicornpp hello_world.unicorn hello_world_program
./hello_world_program
```

Expected Output:

```
Hello, World!
```

---

## 3. Language Syntax

### Memory Operations

- `🦄`: Increment the value at the current memory cell.
- `🌈`: Decrement the value at the current memory cell.

### Pointer Operations

- `🧚‍♀️`: Move the pointer to the right (increase memory cell index).
- `🐉`: Move the pointer to the left (decrease memory cell index).

### Input and Output

- `🪄`: Output the character at the current memory cell.
- `🕳️`: Input a character and store it in the current memory cell.
- `📝`: Output a string of text enclosed in `📝...📝`.

### Control Structures

- `✨`: Start a loop if the current memory cell is not zero.
- `💫`: End a loop if the current memory cell is not zero.

---

## 4. Standard Library Functions

### `📝` - Output Text

Outputs a string of text. Example: `📝Hello, World!📝`

### `🦄` - Increment Memory Cell

Increments the value at the current memory cell.

### `🌈` - Decrement Memory Cell

Decrements the value at the current memory cell.

### `🧚‍♀️` - Move Pointer Right

Moves the pointer to the right (increase memory cell index).

### `🐉` - Move Pointer Left

Moves the pointer to the left (decrease memory cell index).

### `🪄` - Output Character

Outputs the character at the current memory cell.

### `🕳️` - Input Character

Inputs a character and stores it in the current memory cell.

### `✨` - Start Loop

Starts a loop if the current memory cell is not zero.

### `💫` - End Loop

Ends a loop if the current memory cell is not zero.

---

## 5. Examples

### Basic Examples

1. **Hello, World!**

   ```plaintext
   📝Hello, World!📝
   🪄
   ```

   Output: `Hello, World!`

### Advanced Examples

_(Provide more complex examples demonstrating loops, multiple output/input operations, etc.)_

---

## 6. Interpreter/Compiler

### Interpreter Features

- Translates Unicorn++ code into equivalent C++ code.
- Handles memory operations, input/output, and control structures.
- Outputs generated C++ code to a file.

### Compiler Features

- Compiles the generated C++ code into a binary executable.
- Uses `g++` as the backend compiler.

### Command-Line Usage

To interpret and compile a Unicorn++ program:

```sh
./unicornpp <input_file.unicorn> <output_executable>
```

Example:

```sh
./unicornpp hello_world.unicorn hello_world_program
./hello_world_program
```

---
