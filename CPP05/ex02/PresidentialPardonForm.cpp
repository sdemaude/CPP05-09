/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:09:12 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/12 11:03:59 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"	

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , target(NULL)
{
	std::cout << "[PresidentialPardonForm] Default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :	AForm("PresidentialPardonForm", 25, 5),
																			target(target)
{
	std::cout << "[PresidentialPardonForm] Target constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :	AForm(other.getName(),
																					other.getGradeToSign(),
																					other.getGradeToExec()),
																					target(other.getTarget())
{
	std::cout << "[PresidentialPardonForm] Copy constructor has been called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] Destructor has been called" << std::endl;
}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw (GradeTooLowException());
	else if (!this->getIsSigned())
		throw (FormNotSignedException());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	this->AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);	
}
