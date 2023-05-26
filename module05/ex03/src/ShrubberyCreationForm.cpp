/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:41 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 18:05:46 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 145, 137), _target("Nala") {}

ShrubberyCreationForm::ShrubberyCreationForm
(const ShrubberyCreationForm& rhs) : AForm(rhs), _target(rhs._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
 : AForm("ShrubberyCreationForm", 145, 137), _target(newTarget) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=
(const ShrubberyCreationForm& rhs) {
  this->_target = rhs.getTarget();
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
  return (_target);
}

void ShrubberyCreationForm::setTarget(std::string newTarget) {
  _target = newTarget;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream	outfile(_target + "_shrubbery");

  if (executor.getGrade() > _execGrade)
    throw GradeTooLowException();
  if (!outfile.is_open())
    return ((void)(std::cerr << "failed to open file" << std::endl));
  outfile << "\n"
          << "             _{\\ _{\\{\\/}/}/}__\n"
          << "            {/{/\\}{/{/\\}(\\}{/\\} _\n"
          << "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
          << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
          << "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
          << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
          << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
          << "     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
          << "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
          << "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
          << "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
          << "     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
          << "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
          << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
          << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
          << "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
          << "            {/{\\{\\{\\/}/}{\\{\\}/}\n"
          << "             {){/ {\\/}{\\/} \\}\\}\n"
          << "             (_)  \\.-'.-/\n"
          << "         __...--- |'-.-'| --...__\n"
          << "   _...--   .-'   |'-.-'|  ' -.  --..__\n"
          << " -    ' .  . '    |.'-._| '  . .  '   jro\n"
          << ".  '-  '    .--'  | '-.'|    .  '  . '\n"
          << "         ' ..     |'-_.-|\n"
          << " .  '  .       _.-|-._ -|-._  .  '  .\n"
          << "             .'   |'- .-|   '.\n"
          << " ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
          << "  .-' '        '-._______.-'     '  .\n"
          << "       .      ~,\n"
          << "   .       .   |\\   .    ' '-.\n"
          << "   ___________/  \\____________\n"
          << "  /  Why is it, when you want \\\n"
          << " |  something, it is so damn   |\n"
          << " |    much work to get it?     |\n"
          << "  \\___________________________/  \n";
  outfile.close();
}

std::ostream& operator<<(std::ostream& out,
const ShrubberyCreationForm& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "Target: " << rhs.getTarget() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
