## Steps to Run main.cpp

### 1. Open Terminal
Navigate to the folder where this file is present.
`cd path/to/folder`

### 2. Download library for XML Parsing
`sudo apt update`
`sudo apt install libtinyxml2-dev`

### 2. Make directory for data files
`mkdir data`

### 3. Build the executable
`mkdir bin` : Folder for executable file
`g++ main.cpp src/*.cpp -o bin/main.out -I./inc -I./externals -ltinyxml2`

### 4. Run the Program
`./bin/main.out`
