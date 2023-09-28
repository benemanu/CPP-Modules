#include "serialization.hpp"

int main() {
    Data* myData = new Data;
    myData->age = 20;
    myData->name = "Benedikt";

    Serializer serializer;
    uintptr_t serializedData = serializer.serialize(myData);
    Data* deserializedData = serializer.deserialize(serializedData);

    std::cout << typeid(serializedData).name() << std::endl;
    std::cout << typeid(myData->age).name() << std::endl;
    std::cout << typeid(deserializedData->age).name() << std::endl;

    delete myData;

    return 0;
}
