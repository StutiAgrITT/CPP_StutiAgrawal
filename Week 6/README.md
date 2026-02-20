## Steps to Run main.cpp

### 1. Open Terminal
Navigate to the folder where this file is present.
`cd path/to/folder`

### 2. Make directory for data files
`mkdir data`

### 3. Build the executable
`mkdir bin` : Folder for executable file
`g++ main.cpp src/*.cpp -o bin/main.out -I./inc -ltinyxml2`

### 4. Run the Program
`./bin/main.out`
