#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <stdexcept>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& source);
		Intern&	operator=(const Intern& source);
		~Intern(void);

		AForm*	makeForm(std::string formType, std::string target) const;

		class	TypeMatchingFailException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
	private:
};
#endif
