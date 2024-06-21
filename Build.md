# Build Instructions for SSJITCompiler

## Prerequisites
- CMake (version 3.10 or higher)
- C++11 compiler (e.g., GCC, Clang)

## Build Steps
1. Clone the SSJITCompiler repository:
   ```shell
   git clone https://github.com/SpoinkOSDevs/SanityScrew.git
   ```

2. Navigate to the SSJITCompiler directory:
   ```shell
   cd SSJITCompiler
   ```

3. Create a build directory:
   ```shell
   mkdir build
   ```

4. Move into the build directory:
   ```shell
   cd build
   ```

5. Generate the build files with CMake:
   ```shell
   cmake ..
   ```

6. Build the SSJITCompiler executable:
   ```shell
   cmake --build .
   ```

7. After successful compilation, the SSJITCompiler executable will be available in the build directory.

## Running the SSJITCompiler
To compile and run code using the SSJITCompiler, follow these steps:
1. Create a text file containing SSJIT code (e.g., `example.ss`).
2. Run the SSJITCompiler executable with the input file as an argument:
   ```shell
   ./SSJITCompiler example.ss
   ```
