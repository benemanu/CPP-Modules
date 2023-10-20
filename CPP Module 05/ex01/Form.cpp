#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExecute(150) {
    return ;
}

Form::Form(const std::string name, int gradeSign, int gradeExecute) : _name(name),  _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    if (_gradeExecute > 150 || _gradeSign > 150)
        throw GradeTooHighException();
    else if (_gradeExecute < 1 || _gradeSign < 1)
        throw GradeTooLowException();
    
}
Form::Form(const Form &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {
    *this = copy;
}

Form::~Form() {
    return ;
}

Form &Form::operator=(const Form &form) {
    if (this != &form)
        _signed = form._signed;
    return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "'"<<form.getName() << "'" << std::endl;
	o << "\t" << "signed : " << (form.getIsSigned() ? "true" : "false") << std::endl;
	o << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	o << "\t" << "grade needed to execute : " << form.getGradeExecute() << std::endl;
	return (o);
};

std::string Form::getName(void) const{
    return _name;
}

int Form::getGradeSign(void) const{
    return _gradeSign;
}  

int Form::getGradeExecute(void) const{
    return _gradeExecute;
}

bool Form::getIsSigned(void) const {
    if (_signed)
        return true;
    return false;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeSign)
        _signed = true;
    else
        throw GradeTooLowException();
    
}