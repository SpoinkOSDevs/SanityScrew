#!/bin/bash

# Compile the Unicorn++ interpreter
g++ -o unicornpp unicornpp.cpp

# Move the interpreter to /usr/local/bin
sudo mv unicornpp /usr/local/bin

# Make the interpreter executable
sudo chmod +x /usr/local/bin/unicornpp

echo "Unicorn++ has been installed. You can run your .unicorn files using 'unicornpp <filename.unicorn>'"
