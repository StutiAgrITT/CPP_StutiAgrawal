#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void filler1() { volatile int x = 1; x++; }
void filler2() { volatile int x = 2; x++; }
void filler3() { volatile int x = 3; x++; }
void filler4() { volatile int x = 4; x++; }
void filler5() { volatile int x = 5; x++; }
void filler6() { volatile int x = 6; x++; }
void filler7() { volatile int x = 7; x++; }
void filler8() { volatile int x = 8; x++; }
void filler9() { volatile int x = 9; x++; }
void filler10() { volatile int x = 10; x++; }

void depth20(int *p)
{
    filler1();
    *p = 100;
}

void depth19(int *p)
{
    filler2();
    depth20(p);
}

void depth18(int *p)
{
    filler3();
    depth19(p);
}

void depth17(int *p)
{
    filler4();
    depth18(p);
}

void depth16(int *p)
{
    filler5();
    depth17(p);
}

void depth15(int *p)
{
    filler6();
    depth16(p);
}

void depth14(int *p)
{
    filler7();
    depth15(p);
}

void depth13(int *p)
{
    filler8();
    depth14(p);
}

void depth12(int *p)
{
    filler9();
    depth13(p);
}

void depth11(int *p)
{
    filler10();
    depth12(p);
}

void depth10(int *p)
{
    filler1();
    depth11(p);
}

void depth9(int *p)
{
    filler2();
    depth10(p);
}

void depth8(int *p)
{
    filler3();
    depth9(p);
}

void depth7(int *p)
{
    filler4();
    depth8(p);
}

void depth6(int *p)
{
    filler5();
    depth7(p);
}

void depth5(int *p)
{
    filler6();
    depth6(p);
}

void depth4(int *p)
{
    filler7();
    depth5(p);
}

void depth3(int *p)
{
    filler8();
    depth4(p);
}

void depth2(int *p)
{
    filler9();
    depth3(p);
}

void depth1(int *p)
{
    filler10();
    depth2(p);
}

void entry()
{
    int *badPointer = nullptr;
    depth1(badPointer);
}

int main()
{

    vector<string> data;
    for (int i = 0; i < 50; i++)
    {
        data.push_back("item_" + to_string(i));
    }

    for (size_t i = 0; i < data.size(); i++)
    {
        if (i % 10 == 0)
            cout << data[i] << endl;
    }

    entry();

    cout << "End" << endl;
    return 0;
}