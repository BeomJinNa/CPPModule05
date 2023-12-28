#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\033[33mError test\033[0m" << std::endl;
	try
	{
		Form	form0("test_0", 0, 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		Form	form151("test_151", 151, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n\033[33mMain Test\033[0m" << std::endl;
	try
	{
		Form		form10("test_10", 10, 10);
		Form		form150("test_150", 150, 150);
		Bureaucrat	bureacrat1("b1");
		Bureaucrat	bureacrat150("b150");

		for (int i = 0; i < 149; ++i)
			bureacrat1.increaseGrade();

		std::cout << std::boolalpha;
		std::cout << "b150 grade : " << bureacrat150.getGrade() << std::endl;
		bureacrat150.signForm(form10);
		bureacrat150.signForm(form150);
		std::cout << "form 10 : " << form10.getSigned() << ", form 150 : "
				  << form150.getSigned() << std::endl;

		std::cout << "b1 grade : " << bureacrat1.getGrade() << std::endl;
		bureacrat1.signForm(form10);
		bureacrat1.signForm(form150);
		std::cout << "form 10 : " << form10.getSigned() << ", form 150 : "
				  << form150.getSigned() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}
