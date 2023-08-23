#ifndef ROBOTOMYCREATIONFORM_HPP
# define ROBOTOMYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
            const std::string _target;
            RobotomyRequestForm(void);
            RobotomyRequestForm(const RobotomyRequestForm &robotomyForm);


    public: 
            RobotomyRequestForm(const std::string _target);
            virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &robotomyForm);
		
		void					execute(const Bureaucrat &bureaucrat) const;
};

#endif