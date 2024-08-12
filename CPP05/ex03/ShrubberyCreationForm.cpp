/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:05:57 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/12 11:07:31 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"	

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , target(NULL)
{
	std::cout << "[ShrubberyCreationForm] Default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :	AForm("ShrubberyCreationForm", 145, 137),
																			target(target)
{
	std::cout << "[ShrubberyCreationForm] Target constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :	AForm(other.getName(),
																					other.getGradeToSign(),
																					other.getGradeToExec()),
																					target(other.getTarget())
{
	std::cout << "[ShrubberyCreationForm] Copy constructor has been called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] Destructor has been called" << std::endl;
}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		filename(target + "_shrubbery");
	std::ofstream	outfile;

	if (executor.getGrade() > this->getGradeToExec())
		throw (GradeTooLowException());
	if (!this->getIsSigned())
		throw (FormNotSignedException());

	outfile.open(filename.c_str());

	if (!outfile.is_open())
		std::cerr << "Shrubbery file : " << target << " could not be open..." << std::endl;
	else
	{
		for (int i = 0; i < ATREE_NB ; i++)
			outfile << ASCII_TREE;
		outfile.close();
	}	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);	
}
