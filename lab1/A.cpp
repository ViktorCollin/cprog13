#include <iostream>

class A {
public:
    A() 
        {std::cout << "The default contructor" << std::endl; }
    A(const A & ref) 
        {std::cout << "The copy contructor" << std::endl; }
    ~A() 
        {std::cout << "The destructor" << std::endl; }
    A(char * s) 
        {std::cout << "Some other constructor " << s << std::endl;}
    A & operator=(const A & s) 
        {std::cout << "The assignment operator" << std::endl; 
         return *this;}
};

void no_ref(A a) {}
void with_ref(const A & a) {}

int main()
{
    std::cout << "A a('my name is a');" << std::endl;
    A a("my name is a");
    
    std::cout << "A b = a" << std::endl;
    A b = a;         // vad är skillnaden Copy Constructor 
    std::cout << "A c(a)" << std::endl;
    A c(a);          // mellan dessa Copy Constructor
    std::cout << "A d" << std::endl;
    A d;             // tre tekniker? Default costructor 
    std::cout << "d = a" << std::endl;
    d = a;

    std::cout << "Start: no_ref" << std::endl;
    no_ref(a);       // Bildas temporära objekt?
    std::cout << "End: no_ref. \nStart: with_ref" << std::endl;
    with_ref(a);     // Bildas temporära objekt?
    std::cout << "End: with_ref" << std::endl;

    A *aa = new A[5];
    delete aa;       // Vad kommer att hända?
    return 0;
}
