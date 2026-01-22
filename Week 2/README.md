## Steps followed to create shared library

### 1. Open Terminal
Navigate to the folder where this file is present.
`cd path/to/folder`

### 2. Create object files
`mkdir obj` <br>
`g++ -Wall -fPIC -c src/add.cpp -o obj/add.o` <br>
`g++ -Wall -fPIC -c src/subtract.cpp -o obj/subtract.o`<br>
`g++ -Wall -fPIC -c src/multiply.cpp -o obj/multiply.o` <br>
`g++ -Wall -fPIC -c src/divide.cpp -o obj/divide.o` <br>

### 3. Create shared object library
`mkdir lib` <br>
`g++ -shared -o lib/libmathops.so obj/*.o` <br><br>
To check the dynamic symbols included: <br>
`nm -D lib/libmathops.so`

## Implicit Dynamic Linking
### Built the executable
`mkdir bin` if bin doesn't exist already. <br><br>
`g++ src/application_implicit.cpp src/menu.cpp src/input.cpp -L./lib/ -lmathops -o bin/application_implicit` <br>

### Run the executable
`./bin/application_implicit`

## Explicit Dynamic Linking
### Build the executable
`mkdir bin` if bin doesn't exist already.<br><br>
`g++ src/application_explicit.cpp src/menu.cpp src/input.cpp -o bin/application_explicit -ldl` <br>

### Run the executable
`./bin/application_explicit`