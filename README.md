## Notes
- Detailed data structure notes: `docs/DataStructureNote.md`

# DataStructure
Repo for Data Structure Programme

# Git related command
git status
git add .
git commit -m "Message"
git push origin DataStructure

# Build the project
# Create and navigate to the build directory
mkdir build
cd build

# Generate build files using CMake
cmake .. -G "MinGW Makefiles"

# Compile the project
cmake --build .

# or clean first and compile the project.
cmake --build . --clean-first

# Run the executable
.\data_structures.exe



