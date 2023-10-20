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
	AForm* rrf;
	try {
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		rrf->beSigned(me);
		rrf->execute(me);
		std::cout << *rrf << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;

	std::cout << std::endl;
	std::cout << "Test 2:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me1("Lucie", 138);
	Intern someRandomIntern1;
	AForm* rrff;
	try {
		rrff = someRandomIntern1.makeForm("shrubbery creation", "Bender");
		std::cout << *rrff << std::endl;
		rrff->beSigned(me1);
		rrff->execute(me1);
		std::cout << *rrff << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrff;

	std::cout << std::endl;
	std::cout << "Test 3:" << std::endl;
	std::cout << std::endl;

	Bureaucrat me2("Lucie", 131);
	Intern someRandomIntern2;
	AForm* rrrff;
	try {
		rrrff = someRandomIntern2.makeForm("shrubberycreation", "Target");
		std::cout << *rrrff << std::endl;
		rrrff->beSigned(me2);
		rrrff->execute(me2);
		std::cout << *rrrff << std::endl;
		delete rrrff;
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
	AForm* rrrfff;
	try {
		rrrfff = someRandomIntern3.makeForm("robotomy request", "Bender");
		std::cout << *rrrfff << std::endl;
		rrrfff->beSigned(me3);
		rrrfff->execute(me3);
		std::cout << *rrrfff << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrrfff;

	return (0);
}