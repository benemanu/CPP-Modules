#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 	AForm("Robotomy creation", 72, 45), _target("unknown") {
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy creation", 72, 45), _target(target) {
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyForm)
{
	*this = robotomyForm;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    return;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyForm)
{
	(void)robotomyForm;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::executeCheck(bureaucrat);
	std::cout << "*some drilling noises * ";
	robotomized = rand() % 2;
	if (robotomized)
		std::cout  << _target  << " was robotomized" << std::endl;
	else
		std::cout << _target << " was not robotomized" << std::endl;
	
}