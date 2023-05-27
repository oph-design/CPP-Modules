/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:41 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 18:19:40 by oheinzel         ###   ########.fr       */
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
  this->setIsSigned(rhs.getIsSigned());
  return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
  return (_target);
}

void ShrubberyCreationForm::setTarget(std::string newTarget) {
  _target = newTarget;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  std::string fname = _target + "_shrubbery";
	std::ofstream	outfile;

  if (!this->getIsSigned())
    return ;
  if (executor.getGrade() > this->getExecGrade())
    throw GradeTooLowException();
  outfile.open(fname.c_str());
  if (!outfile.is_open())
    return ((void)(std::cerr << "failed to open file" << std::endl));
  outfile << "\n";
  outfile << "             _{\\ _{\\{\\/}/}/}__\n";
  outfile << "            {/{/\\}{/{/\\}(\\}{/\\} _\n";
  outfile << "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n";
  outfile << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
  outfile << "       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
  outfile << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
  outfile << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
  outfile << "     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
  outfile << "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n";
  outfile << "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
  outfile << "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
  outfile << "     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
  outfile << "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
  outfile << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
  outfile << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
  outfile << "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
  outfile << "            {/{\\{\\{\\/}/}{\\{\\}/}\n";
  outfile << "             {){/ {\\/}{\\/} \\}\\}\n";
  outfile << "             (_)  \\.-'.-/\n";
  outfile << "         __...--- |'-.-'| --...__\n";
  outfile << "   _...--   .-'   |'-.-'|  ' -.  --..__\n";
  outfile << " -    ' .  . '    |.'-._| '  . .  '   jro\n";
  outfile << ".  '-  '    .--'  | '-.'|    .  '  . '\n";
  outfile << "         ' ..     |'-_.-|\n";
  outfile << " .  '  .       _.-|-._ -|-._  .  '  .\n";
  outfile << "             .'   |'- .-|   '.\n";
  outfile << " ..-'   ' .  '.   `-._.-�   .'  '  - .\n";
  outfile << "  .-' '        '-._______.-'     '  .\n";
  outfile << "       .      ~,\n";
  outfile << "   .       .   |\\   .    ' '-.\n";
  outfile << "   ___________/  \\____________\n";
  outfile << "  /  Why is it, when you want \\\n";
  outfile << " |  something, it is so damn   |\n";
  outfile << " |    much work to get it?     |\n";
  outfile << "  \\___________________________/  \n";
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
