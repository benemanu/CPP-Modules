#include <iostream>
#include <cstdlib>
#include <ctime>
#include<unistd.h>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void) {
    std::srand(static_cast<unsigned>(std::time(0)));
    int lower = 1;
    int upper = 3;
    int randomValue = (std::rand() % (upper - lower + 1)) + lower;
    if (randomValue == 1)
        return new A();
    else if (randomValue == 2)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}



void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e)
	{
	}
}

int main() {
    Base* base = generate();
    sleep(5);
    Base* base1 = generate();
    identify(base);
    identify(*base);
    identify(base1);
    identify(*base1);
    
    delete base1;
    delete base;
    return 0;
}
