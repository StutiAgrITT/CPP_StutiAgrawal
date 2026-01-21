//int sum(int, int);

// if linked with c file, it would give error of undefined reference
// bcs in c: sum
// in c++ : _Z3sumii

//fix :
extern "C" int sum(int, int);


int main() {
    sum(2, 3);
}