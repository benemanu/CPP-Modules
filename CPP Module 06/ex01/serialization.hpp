#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

struct Data {
    int age;
    std::string name;
};

class Serializer {
public:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

    Data* getData() const;
    void setData(Data* ptr);

    uintptr_t serialize(Data* ptr) const;
    Data* deserialize(uintptr_t raw) const;

private:
    Data* data;
};

#endif
