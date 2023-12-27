#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	top("top");
		Bureaucrat	bottom("bottom");

		std::cout << "init states" << std::endl;
		std::cout << top.getName() << " : " << top.getGrade() << std::endl;
		std::cout << bottom.getName() << " : " << bottom.getGrade() << std::endl;

		for (int i = 0; i < 149; ++i)
			top.increaseGrade();

		std::cout << "\nset states" << std::endl;
		std::cout << top.getName() << " : " << top.getGrade() << std::endl;
		std::cout << bottom.getName() << " : " << bottom.getGrade() << std::endl;

		top.increaseGrade();
		bottom.decreaseGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}
