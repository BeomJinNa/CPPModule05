#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5)
	, mTarget(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source)
	: AForm(source)
	, mTarget(source.mTarget)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(
						const PresidentialPardonForm &source)
{
	if (this != &source)
	{
		AForm::operator=(source);
		mTarget = source.mTarget;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	checkBureaucratGrade(executor);

	std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
