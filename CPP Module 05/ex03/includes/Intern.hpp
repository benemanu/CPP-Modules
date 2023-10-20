#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <stdio.h>
#include <string.h>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
    public: 
            Intern();
            Intern(const Intern &copy);
            ~Intern();
            Intern &operator=(const Intern &assign);

            AForm *makeForm(const std::string &formName, const std::string &formTarget);

            AForm *makeShrubberyCreationForm(const std::string &formTarget);
            AForm *makePresidentialPardonForm(const std::string &formTarget);
            AForm *makeRobotomyRequestForm(const std::string &formTarget);
            int getForm(const std::string formName);
    class InvalidFormNameException : public std::exception
        {
            public: 
                    virtual const char *what() const throw()
                    {
                        return ("error: InternException: the given form Name is not valid!\n");
                    }
        };
};

    

#endif