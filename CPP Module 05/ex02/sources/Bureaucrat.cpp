#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat::~Bureaucrat() {
    return;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::gradeOneDown(void) {
    if (_grade >= 150)
		throw GradeTooHighException();
	_grade++;
}

void Bureaucrat::gradeOneUp(void) {
    if(_grade <= 1)
        throw GradeTooLowException();
    _grade--;
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldnt sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << _name << " cannot executes " << form.getName() <<  " because " << e.what() << std::endl;
	}
}