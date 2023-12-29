#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "\033[33mFirst Test\033[0m" << std::endl;
	try
	{
		Bureaucrat	bureacrat1("b1");
		Bureaucrat	bureacrat150("b150");

		for (int i = 0; i < 149; ++i)
			bureacrat1.increaseGrade();

		ShrubberyCreationForm	sForm("sample");

		bureacrat1.signForm(sForm);
		bureacrat1.executeForm(sForm);
		std::cout << "File created: sample_shrubbery" << std::endl;
		std::cout << "\033[32mError Test\033[0m" << std::endl;
		bureacrat150.executeForm(sForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n\033[33mSecond Test\033[0m" << std::endl;
	try
	{
		Bureaucrat	bureacrat1("b1");
		Bureaucrat	bureacrat150("b150");

		for (int i = 0; i < 149; ++i)
			bureacrat1.increaseGrade();

		RobotomyRequestForm	rForm("sample");

		bureacrat1.signForm(rForm);

		for (int i = 0; i < 10; ++i)
			bureacrat1.executeForm(rForm);
		std::cout << "\033[32mError Test\033[0m" << std::endl;
		bureacrat150.executeForm(rForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n\033[33mThird Test\033[0m" << std::endl;
	try
	{
		Bureaucrat	bureacrat1("b1");
		Bureaucrat	bureacrat150("b150");

		for (int i = 0; i < 149; ++i)
			bureacrat1.increaseGrade();

		PresidentialPardonForm	pForm("sample");

		bureacrat1.signForm(pForm);

		bureacrat1.executeForm(pForm);
		std::cout << "\033[32mError Test\033[0m" << std::endl;
		bureacrat150.executeForm(pForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return (0);
}
