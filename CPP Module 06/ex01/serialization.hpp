#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <stdint.h>

struct Data {
    int age;
    std::string name;
};

class Serializer {
private:
    Data* data;
    Serializer();

public:
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& assign);
    ~Serializer();

    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};

#endif
