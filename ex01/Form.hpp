#pragma once
#ifndef FROM_HPP
# define FROM_HPP

# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string& name, const int& gradeToSign, const int& gradeToExcute);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		~Form(void);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);

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
		const int			mGradeToSign;
		const int			mGradeToExecute;
		bool				mSigned;
};
#endif
