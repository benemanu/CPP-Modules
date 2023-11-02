#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);

// std::cout << std::endl;

// std::vector<int> vstack;

//     vstack.push_back(5);
//     vstack.push_back(17);
//     std::cout << vstack.back() << std::endl;
//     vstack.pop_back();
//     std::cout << vstack.size() << std::endl;
//     vstack.push_back(3);
//     vstack.push_back(5);
//     vstack.push_back(737);
//     vstack.push_back(0);

//     std::vector<int>::iterator it1 = vstack.begin();
//     std::vector<int>::iterator ite1 = vstack.end();
//     ++it1;
//     --it1;
//     while (it1 != ite1) {
//         std::cout << *it1 << std::endl;
//         ++it1;
//     }
//     std::cout << "" << std::endl;

// std::list<int> myList;
// myList.push_back(5);
// myList.push_back(17);
// std::cout << myList.back() << std::endl;
// myList.pop_back();
// std::cout << myList.size() << std::endl;
// myList.push_back(3);
// myList.push_back(5);
// myList.push_back(737);
// myList.push_back(0);
// std::list<int>::iterator it3 = myList.begin();
// std::list<int>::iterator ite3 = myList.end();
// ++it3;
// --it3;

// while (it3 != ite3) {
//     std::cout << *it3 << std::endl;
//     ++it3;
// }

// return 0;
// }