#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45)
	, mTarget(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source)
	: AForm(source)
	, mTarget(source.mTarget)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(
						const RobotomyRequestForm &source)
{
	if (this != &source)
	{
		AForm::operator=(source);
		mTarget = source.mTarget;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkBureaucratGrade(executor);

	std::cout << "\nsome noise with drilling!!!" << std::endl;
	if (std::rand() > RAND_MAX / 2)
	{
		std::cout << mTarget << " has become a robot!" << std::endl;
	}
	else
	{
		std::cout << "\033[35mfailed to turn " << mTarget << " into a robot.\033[0m" << std::endl;
	}
}
