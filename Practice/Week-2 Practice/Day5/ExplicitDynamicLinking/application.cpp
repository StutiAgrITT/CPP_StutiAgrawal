#include <dlfcn.h>
#include <iostream>

int main() {
    void *lib_handle;
    //RTLD_LAZY: resolve unresolved later
    lib_handle = dlopen("./lib/libmaths.so", RTLD_LAZY);

    //checking whether loading failed
    if(!lib_handle) {
        std::cerr << dlerror() << '\n';
        exit(1);
    }

    int (*addFunction)(int, int);
    int (*multiplyFunction)(int, int);
    void (*printFunction)();

    addFunction = (int (*)(int, int)) dlsym(lib_handle, "addNumbers");
    char* error = dlerror();
    if(error != NULL) {
        std::cerr << error << '\n';
        dlclose(lib_handle);
        exit(1);
    }
    multiplyFunction = (int (*)(int, int)) dlsym(lib_handle, "multiplyNumbers");
    printFunction = (void (*)()) dlsym(lib_handle, "printHello");


    int sum = addFunction(5, 7);
    int product = multiplyFunction(5, 7);
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Product: " << product << '\n';
    printFunction();

    dlclose(lib_handle);
    return 0;
}