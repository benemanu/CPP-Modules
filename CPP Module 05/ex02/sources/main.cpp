#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>
#include <cstdlib>

int	main(void)
{
	std::cout << std::endl;
	std::cout << "Test 1:" << std::endl;
	std::cout << std::endl;

	AForm		*shrub = new ShrubberyCreationForm("home");
	AForm		*target = new ShrubberyCreationForm("target");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Lucie", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	me.signForm(*target);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	me.gradeOneUp();
	me.gradeOneUp();
	me.gradeOneUp();
	me.executeForm(*target);
	delete shrub;
	delete target;

	std::cout << std::endl;
	std::cout << "Test 2:" << std::endl;
	std::cout << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Lucie", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << "Test 3:" << std::endl;
	std::cout << std::endl;

	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Lucie", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.gradeOneUp();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}