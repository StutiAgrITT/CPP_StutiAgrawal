#include "os_utils.h"

int getOSCode() {
    #ifdef OS_WINDOWS
        return 1;
    #else
        return 2;
    #endif
}

int main() {
    int os = getOSCode();
    return os; // to check using echo $?
}