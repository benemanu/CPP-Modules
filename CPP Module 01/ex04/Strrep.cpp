
#include "Strrep.hpp"
#include <iostream>
#include <fstream>
#include <string>

Strrep::Strrep(std::string filename)
{
    this->inputFile = filename;
    this->outputFile = filename + ".replace";
}

Strrep::~Strrep()
{
    return;
}

void    Strrep::myreplace(std::string str1, std::string str2)
{
    int ind = 0;
    std::ifstream input_file(this->inputFile.c_str());
    if (input_file.is_open())
    {
        std::string line;
        std::ofstream output_file(this->outputFile.c_str()); 
        if (!output_file.is_open())
        {
            std::cout << "Error: File could not be opened" << std::endl;
            return;
        }
        while (std::getline(input_file, line, '\n'))
        {   
            ind = 1;
            size_t pos = 0;
            pos = line.find(str1);
            if (pos != std::string::npos)
            {
                while (pos != std::string::npos)
                {
                    line.erase(pos, str1.length());
                    line.insert(pos, str2);
                    pos = line.find(str1);
                }
                output_file << line;
            }
            else
                output_file << line;
            output_file << std::endl;
        }
        output_file.close();
        if (line.empty() && ind == 0)
        {
            std::cout << "Error: File is empty" << std::endl;
            return;
        }
        input_file.close();
    }
    else
    {
        std::cout << "Error: File could not be opened" << std::endl;
        return;
    }
}