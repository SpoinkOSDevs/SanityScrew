#!/bin/bash

# Compile the interpreter
g++ -o SanityScrew SanityScrew.cpp

# Move the interpreter to /usr/local/bin
sudo mv SanityScrew /usr/local/bin

# Make the interpreter executable
sudo chmod +x /usr/local/bin/SanityScrew

echo "SanityScrew has been installed."
