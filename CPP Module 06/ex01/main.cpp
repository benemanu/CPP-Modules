#include "serialization.hpp"

int main() {
    Data data;
	data.name = "Benedikt";
	data.age = 20;
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << ptr->name << std::endl;
	std::cout << ptr->age << std::endl;
	std ::cout << "raw: 0x" << std::hex << raw << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
    
    return 0;
}
