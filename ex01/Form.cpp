#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(void)
	: mGradeToSign(1)
	, mGradeToExecute(1)
	, mSigned(false)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExcute)
	: mName(name)
	, mGradeToSign(gradeToSign)
	, mGradeToExecute(gradeToExcute)
	, mSigned(false)
{
	if (gradeToExcute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExcute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& source)
	: mName(source.mName)
	, mGradeToSign(source.mGradeToSign)
	, mGradeToExecute(source.mGradeToExecute)
	, mSigned(source.mSigned)
{
}

Form&	Form::operator=(const Form& source)
{
	if (this != &source)
	{
		mSigned = source.mSigned;
	}

	return (*this);
}

Form::~Form(void)
{
}

const std::string&	Form::getName(void) const
{
	return (mName);
}

int	Form::getGradeToSign(void) const
{
	return (mGradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (mGradeToExecute);
}

bool	Form::getSigned(void) const
{
	return (mSigned);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= mGradeToSign)
	{
		mSigned = true;
		std::cout << mName << " has been signed by " << bureaucrat.getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}
