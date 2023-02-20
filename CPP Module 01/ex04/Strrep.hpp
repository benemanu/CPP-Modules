#ifndef STRREP_HPP
# define STRREP_HPP

#include <iostream>
#include <fstream>

class Strrep
{
    private:
        std::string inputFile;
        std::string outputFile;

    public:
        Strrep(std::string filename);
        ~Strrep();

        void myreplace(std::string str1, std::string str2);
};

#endif