#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void)
	: mGrade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name)
	: mName(name)
	, mGrade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& source)
	: mName(source.mName)
	, mGrade(source.mGrade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& source)
{
	if (this != &source)
	{
		mGrade = source.mGrade;
	}

	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string	Bureaucrat::getName(void) const
{
	return (mName);
}

int	Bureaucrat::getGrade(void) const
{
	return (mGrade);
}

Bureaucrat&	Bureaucrat::increaseGrade(void)
{
	if (mGrade == 1)
		throw GradeTooHighException();
	--mGrade;

	return (*this);
}

Bureaucrat&	Bureaucrat::decreaseGrade(void)
{
	if (mGrade == 150)
		throw GradeTooLowException();
	++mGrade;

	return (*this);
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << mName << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	std::cout << mName << " executed " << form.getName() << std::endl;
	form.execute(*this);
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}
