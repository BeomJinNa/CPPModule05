#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& source);
		virtual ~ShrubberyCreationForm(void);

		virtual void	execute(const Bureaucrat& executor) const;

		class		FileCreationFailException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	private:
		std::string	mTarget;
};
#endif
