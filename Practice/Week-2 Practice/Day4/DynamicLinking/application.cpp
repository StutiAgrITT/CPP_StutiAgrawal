#include "math_pack.h"

int main() {
    add(2, 3); //only add used
    //only the required functions will be copied
    // rest will be ignored
    // check by:
    // np application | grep add : shows address, type, name
    // np application | grep subtract : shows nothing (eliminated, same for multiply)

}