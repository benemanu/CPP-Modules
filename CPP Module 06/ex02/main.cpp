#include <random>
#include <iostream>

class Base { public: virtual ~Base() {} };
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base* generate(void) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 3);
    int randomValue = distribution(gen);

    if (randomValue == 1)
        return new A();
    else if (randomValue == 2)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "C" << std::endl;
    else
        std::cout << "Neither A nor B nor C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
    } catch(const std::exception& e) {}
    try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
    } catch( const std::exception& e ) {}
    try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
    } catch( const std::exception& e ) {}
}

int main( ) {
    Base* base = new Base();
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    identify(base);
    identify(a);
    identify(b);
    identify(c);

    delete base;
    delete a;
    delete b;
    delete c;
}