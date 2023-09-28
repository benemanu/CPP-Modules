#include "iter.hpp"

int main( void ) {

	int array[] = {1, 2, 3, 4, 3, 2, 1};
	::iter<int>(array, 7, ::print);

	std::string str = "Hello World!";
	iter<const char>(str.c_str(), str.length(), ::print);

}