#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const	_name;
        bool					_signed;
        int const               _gradeSign;
        int const               _gradeExecute;

    public: 
        AForm();
        AForm(const std::string name, int gradeSign, int gradeExecute);
        AForm(const AForm &copy);
        virtual ~AForm();

        AForm	&operator=(const AForm &copy);

        const std::string	getName(void) const;
		int					getGradeSign(void) const;
        int                 getGradeExecute(void) const;
        bool                getIsSigned(void);

		void                beSigned(const Bureaucrat &bureaucrat);
        virtual void		execute(const Bureaucrat &bureaucrat) const = 0;
		void				executeCheck(const Bureaucrat &bureaucrat) const;

        class GradeTooHighException : public std::exception
        {
            public: 
                    virtual const char *what() const throw()
                    {
                        return ("AForm::exception : Grade is too high");
                    }
        };

         class GradeTooLowException : public std::exception
        {
            public: 
                    virtual const char *what() const throw()
                    {
                        return ("AForm::exception : Grade is too Low");
                    }
        };

        class ExecuteNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("form is not signed"); }
		};
		
		class FileOpeningFail : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("file cannot be opened"); }
		};

};

        std::ostream	&operator<<(std::ostream &o, const AForm &copy);

#endif