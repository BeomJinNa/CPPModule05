#pragma once
#ifndef AFROM_HPP
# define AFROM_HPP

# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(int gradeToSign, int gradeToExcute);
		AForm(const std::string& name, int gradeToSign, int gradeToExcute);
		AForm(const AForm& source);
		AForm&	operator=(const AForm& source);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
		void				checkBureaucratGrade(const Bureaucrat& bureaucrat) const;
		virtual void		execute(const Bureaucrat& bureaucrat) const = 0;

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
		class		ExecutionDeniedException : public std::exception
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
