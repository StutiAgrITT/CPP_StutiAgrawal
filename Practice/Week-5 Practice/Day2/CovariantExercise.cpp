#include <iostream>

class A{
public:
    void print(){
        std::cout << "A\n";
    }
    virtual void vprint(){
        std::cout << "A\n";
    }
};
class B : public A{
public:
    void print(){
        std::cout << "B\n";
    }
    void vprint() override{
        std::cout << "B\n";
    }
};

class C{
private:
    A m_a{};
public:
    virtual A& get(){
        std::cout << "getting obj A\n";
        return m_a;
    }
};

class D : public C{
    private:
    B m_b{};
    public:
    B& get() override // covariant return type
    {
        std::cout << "getting obj B\n";
        return m_b;
    }
};

int main()
{
    // case 1
    D d {}; //object of D
    d.get().print(); //getting object of B, printing B (no pointer)
    d.get().vprint(); // also B
    std::cout << '\n';

    // case 2
    C c {}; //object of C
    c.get().print(); //getting object of A, printing A
    c.get().vprint(); //also A
    std::cout << '\n';

    // case 3
    C& ref{ d }; //pointer C object D
    ref.get().print(); // getting object of B, but printing A as no virtual (ptr will be of C which will get A)
    ref.get().vprint(); // getting obj of B, virtual, therfore prints B
    std::cout << '\n';

    //static type: C&, dynamic type: D
    //get is covariant. static return type: A& (from C), dynamic return type: B (from D)
    //resulting obj : A& obj = B
    //non virtual print sees static type: hence A
    //virtual print sees dynamic type: hence B

    return 0;
}