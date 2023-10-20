#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
        private:
                const std::string _target;
                PresidentialPardonForm(void);
                PresidentialPardonForm(const PresidentialPardonForm &presidentalForm);

        public: 
                PresidentialPardonForm(const std::string _target);
                virtual ~PresidentialPardonForm();
	        PresidentialPardonForm	&operator=(const PresidentialPardonForm &presidentalForm);
	        void    execute(const Bureaucrat &bureaucrat) const;
};

#endif