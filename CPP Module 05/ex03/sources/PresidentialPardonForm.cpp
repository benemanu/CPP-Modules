#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 	AForm("presidential pardon", 25, 5), _target("unknown") {
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("presidential pardon", 25, 5), _target(target) {
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialForm)
{
	*this = presidentialForm;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialForm)
{
	(void)presidentialForm;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
    this->AForm::executeCheck(bureaucrat);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}