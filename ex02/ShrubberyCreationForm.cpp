#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, mTarget(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source)
	: AForm(source)
	, mTarget(source.mTarget)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(
						const ShrubberyCreationForm &source)
{
	if (this != &source)
	{
		AForm::operator=(source);
		mTarget = source.mTarget;
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	static const std::string	content =
"                      ___\n"
"                _,-'\"\"   \"\"\"\"`--.\n"
"             ,-'          __,,-- \\\n"
"           ,'    __,--\"\"\"\"dF      )\n"
"          /   .-\"Hb_,--\"\"dF      /\n"
"        ,'       _Hb ___dF\"-._,-'\n"
"      ,'      _,-\"\"\"\"   \"\"--..__\n"
"     (     ,-'                  `.\n"
"      `._,'     _   _             ;\n"
"       ,'     ,' `-'Hb-.___..._,-'\n"
"       \\    ,'\"Hb.-'HH`-.dHF\"\n"
"        `--'   \"Hb  HH  dF\"\n"
"                \"Hb HH dF\n"
"                 \"HbHHdF\n"
"                  |HHHF\n"
"                  |HHH|\n"
"                  |HHH|\n"
"                  |HHH|\n"
"                  |HHH|\n"
"                  dHHHb\n"
"                .dFd|bHb.               o\n"
"      o       .dHFdH|HbTHb.          o /\n"
"\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
"##########################################\n";

	checkBureaucratGrade(executor);

	std::ofstream				outFile;

	outFile.open(mTarget + "_shrubbery");
	if (!outFile.is_open())
		throw FileCreationFailException();
	outFile << content;
}

const char*	ShrubberyCreationForm::FileCreationFailException::what(void) const throw()
{
	return ("Cannot save the file");
}
