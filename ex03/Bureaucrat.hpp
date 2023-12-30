#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat&	operator=(const Bureaucrat& source);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		Bureaucrat&	increaseGrade(void);
		Bureaucrat&	decreaseGrade(void);
		void		signForm(AForm& form) const;
		void		executeForm(const AForm& form) const;

		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	private:
		const std::string	mName;
		int					mGrade;
};
#endif
