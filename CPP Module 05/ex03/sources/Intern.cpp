#include "Intern.hpp"

Intern::Intern() {
    return;
}

Intern::Intern(const Intern &copy) {
    (void)copy;
}

Intern &Intern::operator=(const Intern &assign) {
	(void)assign;
    return (*this);
}

Intern::~Intern() { 
    return;
}

enum FormName {
    ROBOTOMY_REQUEST_FORM,
    SHRUBBERY_CREATION_FORM,
    PRESIDENTIAL_PARDON_FORM
};

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) {
    
    std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int whatCase = 4;
    for(int i = 0; i < 3; i++) {
        if (formName == formNames[i])
            whatCase = i;
    }
    switch (whatCase) {
        case ROBOTOMY_REQUEST_FORM:
            return makeRobotomyRequestForm(formTarget);
        case SHRUBBERY_CREATION_FORM:
            return makeShrubberyCreationForm(formTarget);
        case PRESIDENTIAL_PARDON_FORM:
            return makePresidentialPardonForm(formTarget);
        default:
                throw InvalidFormNameException();
    }
}

AForm *Intern::makeRobotomyRequestForm(const std::string &formTarget) {
    std::cout << "Intern creates Robotomy Request Form" << std::endl;
    return (new RobotomyRequestForm(formTarget));
}

AForm *Intern::makeShrubberyCreationForm(const std::string &formTarget) {
    std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
    return (new ShrubberyCreationForm(formTarget));
}

AForm *Intern::makePresidentialPardonForm(const std::string &formTarget) {
    std::cout << "Intern creates Presidential Pardon Form" << std::endl;
    return (new PresidentialPardonForm(formTarget));
}