
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 	AForm("Shrubbery creation", 145, 137), _target("unknown") {
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation", 145, 137), _target(target) {
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm)
{
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	(void)shrubberyForm;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream	file;

	this->AForm::executeCheck(bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	if (file.good() == false)
		throw FileOpeningFail();
   file << "              v .   ._, |_  .," << std::endl;
    file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\\\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
    file << "       \'7-,--.\'._||  / / ," << std::endl;
    file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /   " << _target << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
	file << "----------------/ ,  . \\--------._" << std::endl;
	file.close();
}