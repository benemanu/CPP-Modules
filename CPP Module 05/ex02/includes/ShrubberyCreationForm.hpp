#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
            const std::string _target;
            ShrubberyCreationForm(void);
            ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm);


    public: 
            ShrubberyCreationForm(const std::string _target);
            virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &shrubberyForm);
		
		void					execute(const Bureaucrat &bureaucrat) const;
};

#endif