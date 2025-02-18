# DataStructure
Repo for Data Structure Programme

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
./programme.exe



