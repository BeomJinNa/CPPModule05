#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace
{
	AForm*	makeShrubberyCreation(std::string target);
	AForm*	makeRobotomyRequest(std::string target);
	AForm*	makePresidentialPardon(std::string target);
}

Intern::Intern(void)
{
}

Intern::Intern(const Intern& source)
{
	(void)source;
}

Intern&	Intern::operator=(const Intern& source)
{
	if (this != &source)
	{
	}

	return (*this);
}

Intern::~Intern(void)
{
}

AForm*	Intern::makeForm(std::string formType, std::string target) const
{
	static const std::string	lookUpTableString[3]
		= {"ShrubberyCreation",
		   "RobotomyRequest",
		   "PresidentialPardon"};

	AForm*						(*lookUpTableConstructors[3])(std::string)
		= {makeShrubberyCreation,
		   makeRobotomyRequest,
		   makePresidentialPardon};

	for (int i = 0; i < 3; ++i)
	{
		if (formType == lookUpTableString[i])
		{
			std::cout << "Intern creates " << lookUpTableString[i] << std::endl;
			return (lookUpTableConstructors[i](target));
		}
	}

	throw TypeMatchingFailException();
}

namespace
{
	AForm*	makeShrubberyCreation(std::string target)
	{
		return (new ShrubberyCreationForm(target));
	}

	AForm*	makeRobotomyRequest(std::string target)
	{
		return (new RobotomyRequestForm(target));
	}

	AForm*	makePresidentialPardon(std::string target)
	{
		return (new PresidentialPardonForm(target));
	}
}

const char*	Intern::TypeMatchingFailException::what(void) const throw()
{
	return ("No type mathced");
}
