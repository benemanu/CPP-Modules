#include "iter.hpp"

int main() {
    int array[] = {1, 2, 3, 4, 3, 2, 1};
    iter<int, int>(array, 7, printElement<int>);

    std::string str = "Hello World!";
    const char* c_str = str.c_str();
    iter<const char, const char>(c_str, str.length(), printElement<const char>);

    return 0;
}
