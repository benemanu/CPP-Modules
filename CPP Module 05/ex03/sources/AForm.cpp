#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExecute(150) {
    return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExecute) : _name(name),  _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    if (_gradeExecute > 150 || _gradeSign > 150)
        throw GradeTooHighException();
    else if (_gradeExecute < 1 || _gradeSign < 1)
        throw GradeTooLowException();
    
}
AForm::AForm(const AForm &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
    *this = copy;
}

AForm::~AForm() {
    return ;
}

AForm &AForm::operator=(const AForm &aform) {
    if (this != &aform)
        _signed = aform._signed;
    return (*this);
}

std::ostream	&operator<<(std::ostream &o, const AForm &aform)
{
	o << "'" << aform.getName() << "'" << std::endl;
	o << "\t" << "signed : " << (aform.getIsSigned() ? "true" : "false") << std::endl;
	o << "\t" << "grade needed to sign : " << aform.getGradeSign() << std::endl;
	o << "\t" << "grade needed to execute : " << aform.getGradeExecute() << std::endl;
	return (o);
};

const std::string AForm::getName(void) const{
    return _name;
}

int AForm::getGradeSign(void) const{
    return _gradeSign;
}  

int AForm::getGradeExecute(void) const{
    return _gradeExecute;
}

bool AForm::getIsSigned(void) const{
    return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeSign)
        _signed = true;
    else
        throw GradeTooLowException();
    
}

void	AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->_signed)
		throw AForm::ExecuteNotSigned();
	if (this->_gradeExecute < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}