#include "Bureaucrat.hpp"

void	testBasic(void)
{
	Bureaucrat	bob("bob", 6);

	std::cout << bob << std::endl;
	bob.gradeOneDown();
	std::cout << bob << std::endl;
	bob.gradeOneUp();
	bob.gradeOneUp();
	bob.gradeOneUp();
	bob.gradeOneUp();
	std::cout << bob << std::endl;
}

void	testExceptionLow(void)
{
	Bureaucrat	bob("bob", 151);
}

void	testExceptionHigh(void)
{
	Bureaucrat	bob("bob", 0);
}

void	testDownGrade(void)
{
	Bureaucrat	bob("bob", 2);
	bob.gradeOneUp();
	std::cout << bob << std::endl;
	bob.gradeOneUp();
    std::cout << bob << std::endl;
}

void	testUpGrade(void)
{
	Bureaucrat	bob("bob", 149);
	bob.gradeOneDown();
	std::cout << bob << std::endl;
	bob.gradeOneDown();
    
}

int	main(void)
{
	try
	{
		testBasic();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionLow();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionHigh();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		testDownGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testUpGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}