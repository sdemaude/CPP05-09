/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:58:33 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/03 15:35:51 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"	

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , target(NULL)
{
	std::cout << "[RobotomyRequestForm] Default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :	AForm("RobotomyRequestForm", 72, 45),
																			target(target)
{
	std::cout << "[RobotomyRequestForm] Target constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :	AForm(other.getName(),
																					other.getGradeToSign(),
																					other.getGradeToExec()),
																					target(other.getTarget())
{
	std::cout << "[RobotomyRequestForm] Copy constructor has been called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] Destructor has been called" << std::endl;
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::beExecuted(Bureaucrat const &other) const
{
	if (other.getGrade() > this->getGradeToExec())
		throw (GradeTooLowException());
	else if (!this->getIsSigned())
		throw (FormNotSignedException());

	srand(time(NULL));
	if (rand() % 2)
		std::cout << "**DRlllrlrllr** " << this->target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Failed to robotomize " << this->target << " !" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);	
}
