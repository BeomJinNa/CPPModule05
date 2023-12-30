#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& source);
		virtual ~RobotomyRequestForm(void);

		virtual void	execute(const Bureaucrat& executor) const;
	private:
		std::string	mTarget;
};
#endif
