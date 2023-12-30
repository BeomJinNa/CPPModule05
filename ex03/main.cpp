#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{
	Intern  someRandomIntern;
	AForm*	rrf[4] = {NULL, };

	try
	{
		rrf[0] = someRandomIntern.makeForm("ShrubberyCreation", "Bender1");
		rrf[1] = someRandomIntern.makeForm("RobotomyRequest", "Bender2");
		rrf[2] = someRandomIntern.makeForm("PresidentialPardon", "Bender3");
		rrf[3] = someRandomIntern.makeForm("NoType", "Bender4");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	for (int i = 0; i < 4; ++i)
	{
		if (rrf[i] != NULL)
		{
			delete rrf[i];
		}
	}

	return (0);
}
