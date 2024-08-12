/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:29 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/12 10:52:22 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(GRADE_MAX), gradeToExec(GRADE_MAX)
{
	std::cout << "[AForm] Default constructor has been called" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExec) :	name(name),
																			isSigned(false),
																			gradeToSign(gradeToSign),
																			gradeToExec(gradeToExec)
{
	std::cout << "[AForm] Special constructor has been called" << std::endl;

	if (gradeToSign < GRADE_MAX)
		throw (GradeTooHighException());
	else if (gradeToSign > GRADE_MIN)
		throw (GradeTooLowException());

	if (gradeToExec < GRADE_MAX)
		throw (GradeTooHighException());
	else if (gradeToExec > GRADE_MIN)
		throw (GradeTooLowException());
}

AForm::AForm(AForm const &other) : name(other.name),
								isSigned(other.isSigned),
								gradeToSign(other.gradeToSign),
								gradeToExec(other.gradeToExec)
{
	std::cout << "[AForm] Copy constructor has been called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "[AForm] Destructor has been called" << std::endl;
}

std::string const	&AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToExec);
}

int	AForm::getGradeToExec() const
{
	return (this->gradeToSign);
}

void AForm::beSigned(Bureaucrat const &other)
{
	if (other.getGrade() > this->gradeToSign)
		throw (GradeTooLowException());
	this->isSigned = true;
}

AForm &AForm::operator=(AForm const &other)
{
	this->isSigned = other.getIsSigned();
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High !!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form's not signed !!");
}

std::ostream &operator<<(std::ostream &flux, AForm const &other)
{
	flux << other.getName() << ", grade to sign : " << other.getGradeToSign() << ", grade to execute : " << other.getGradeToExec() << ". AForm ";
	if (other.getIsSigned())
		flux << "is signed.";
	else
	 	flux << "isn't signed.";
	return flux;
}
