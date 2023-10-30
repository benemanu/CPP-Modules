#include "serialization.hpp"

Serializer::Serializer() : data(0) {}

Serializer::Serializer(const Serializer& copy) : data(copy.data) {}

Serializer& Serializer::operator=(const Serializer& assign) {
    if (this != &assign) {
        data = assign.data;
    }
    return *this;
}

Serializer::~Serializer() {}


uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}