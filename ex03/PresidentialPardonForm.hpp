#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& source);
		virtual ~PresidentialPardonForm(void);

		virtual void	execute(const Bureaucrat& executor) const;
	private:
		std::string	mTarget;
};
#endif
