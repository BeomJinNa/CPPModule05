#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	: mGradeToSign(1)
	, mGradeToExecute(1)
	, mSigned(false)
{
}

AForm::AForm(int gradeToSign, int gradeToExcute)
	: mGradeToSign(gradeToSign)
	, mGradeToExecute(gradeToExcute)
	, mSigned(false)
{
	if (gradeToExcute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExcute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExcute)
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

AForm::AForm(const AForm& source)
	: mName(source.mName)
	, mGradeToSign(source.mGradeToSign)
	, mGradeToExecute(source.mGradeToExecute)
	, mSigned(source.mSigned)
{
}

AForm&	AForm::operator=(const AForm& source)
{
	if (this != &source)
	{
		mSigned = source.mSigned;
	}

	return (*this);
}

AForm::~AForm(void)
{
}

const std::string&	AForm::getName(void) const
{
	return (mName);
}

int	AForm::getGradeToSign(void) const
{
	return (mGradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (mGradeToExecute);
}

bool	AForm::getSigned(void) const
{
	return (mSigned);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= mGradeToSign)
	{
		mSigned = true;
		std::cout << mName << " has been signed by " << bureaucrat.getName() << std::endl;
	}
	else
		throw GradeTooLowException();
}

void	AForm::checkBureaucratGrade(const Bureaucrat& bureaucrat) const
{
	if (mSigned == false || bureaucrat.getGrade() > mGradeToExecute)
		throw ExecutionDeniedException();
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char*	AForm::ExecutionDeniedException::what(void) const throw()
{
	return ("Execution denied");
}
