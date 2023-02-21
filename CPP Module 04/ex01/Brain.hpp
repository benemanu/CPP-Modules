#pragma once

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        virtual ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};
