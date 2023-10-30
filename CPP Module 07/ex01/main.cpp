#include "iter.hpp"

int main() {
    int array[] = {1, 2, 3, 4, 3, 2, 1};
    iter<int, int>(array, 7, printElement<int>);

    bool str[] = {true, false, true};
    iter<bool, bool>(str, 3, printElement<bool>);

    return 0;
}
