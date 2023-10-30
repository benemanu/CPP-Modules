#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <list>

void checkInputTwoArgs(std::string input);
void checkInputMoreArgs(std::string input);
void mergeVector(std::vector<int>& _vector, int start, int mid, int end);
void sortVector(std::vector<int>& _vector, int start, int end);
std::vector<int> inputToVector(std::string input);
#endif