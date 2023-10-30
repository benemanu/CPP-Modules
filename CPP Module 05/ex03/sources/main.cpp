#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>
#include <cstdlib>
#include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "Test 1:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me("Lucie", 1);
	Intern someRandomIntern;
	AForm* ppf;
	try {
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		ppf->beSigned(me);
		ppf->execute(me);
		std::cout << *ppf << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete ppf;

	std::cout << std::endl;
	std::cout << "Test 2:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me1("Lucie", 138);
	Intern someRandomIntern1;
	AForm* scf;
	try {
		scf = someRandomIntern1.makeForm("shrubbery creation", "Bender");
		std::cout << *scf << std::endl;
		scf->beSigned(me1);
		scf->execute(me1);
		std::cout << *scf << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete scf;

	std::cout << std::endl;
	std::cout << "Test 3:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me2("Lucie", 131);
	Intern someRandomIntern2;
	AForm* scf1;
	try {
		scf1 = someRandomIntern2.makeForm("shrubberycreation", "Target");
		std::cout << *scf1 << std::endl;
		scf1->beSigned(me2);
		scf1->execute(me2);
		std::cout << *scf1 << std::endl;
		delete scf1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test 4:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me3("Lucie", 1);
	Intern someRandomIntern3;
	AForm* rrf;
	try {
		rrf = someRandomIntern3.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		rrf->beSigned(me3);
		rrf->execute(me3);
		std::cout << *rrf << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;

	return (0);
}