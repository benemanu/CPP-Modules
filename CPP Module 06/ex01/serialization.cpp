#include "serialization.hpp"

Serializer::Serializer() : data(nullptr) {}


Serializer::Serializer(const Serializer& other) : data(other.data) {}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}


Serializer::~Serializer() {}

Data* Serializer::getData() const { return data; }
void Serializer::setData(Data* ptr) { data = ptr; }

uintptr_t Serializer::serialize(Data* ptr) const {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) const {
    return reinterpret_cast<Data*>(raw);
}
