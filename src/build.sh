#!/bin/bash

# Directories to compile
declare -a dirs=("RK_FUNCTION" 
                 "RKC_DBFCONTROL" 
                 "RKC_DIB" 
                 "RKC_DSOUND" 
                 "RKC_FILE" 
                 "RKC_FONTMAKER" 
                 "RKC_MEMORY" 
                 "RKC_NETWORK" 
                 "RKC_RPG_AICONTROL" 
                 "RKC_RPG_SCRIPT" 
                 "RKC_RPG_TABLE" 
                 "RKC_RPGSCRN" 
                 "RKC_UPDIB" 
                 "RKC_WINDOW")

# Check if the build directory exists
if [ -d "../build" ]; then
    # Remove the build directory
    rm -rf ../build
fi

# Create the build directory
mkdir ../build

# Loop through each directory and compile
for dir in "${dirs[@]}"; do
    echo "Compiling $dir..."
    g++ -Werror -static -m32 -mdll -std=c++17 -o "../build/$dir.dll" "$dir/src/core.cpp" "$dir/dll.def"
    
    # Check the exit status of the g++ command
    if [ $? -eq 0 ]; then
        echo "$dir compiled successfully!"
    else
        echo "Error compiling $dir. Check above for the error message."
        exit 1
    fi
done

echo "All compilations completed successfully!"
