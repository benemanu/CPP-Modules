#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const	    _name;
        bool					_signed;
        int const               _gradeSign;
        int const               _gradeExecute;

    public: 
        Form();
        Form(const std::string name, int gradeSign, int gradeExecute);
        Form(const Form &copy);
        virtual ~Form();

        Form	&operator=(const Form &copy);

        std::string	        getName(void) const;
	    int			        getGradeSign(void) const;
        int			        getGradeExecute(void) const;
        bool		        getIsSigned(void) const;

	    void			    beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public: 
                    virtual const char *what() const throw()
                    {
                        return ("Form::exception : Grade is too high");
                    }
        };

         class GradeTooLowException : public std::exception
        {
            public: 
                    virtual const char *what() const throw()
                    {
                        return ("Form::exception : Grade is too Low");
                    }
        };

};

        std::ostream	&operator<<(std::ostream &o, const Form &copy);

#endif
