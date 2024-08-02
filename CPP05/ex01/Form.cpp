/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:29 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/02 13:59:39 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(GRADE_MAX), gradeToExec(GRADE_MAX)
{
	std::cout << "[Form] Default constructor has been called" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExec) : name(name), isSigned(false)
{
	std::cout << "[Form] Special constructor has been called" << std::endl;

	if (gradeToSign < GRADE_MAX)
		throw (GradeTooHighException());
	else if (gradeToSign > GRADE_MIN)
		throw (GradeTooLowException());
	this->gradeToSign = gradeToSign;

	if (gradeToExec < GRADE_MAX)
		throw (GradeTooHighException());
	else if (gradeToExec > GRADE_MIN)
		throw (GradeTooLowException());
	this->gradeToExec = gradeToExec;
}

Form::Form(Form const &other) : name(other.name),
								isSigned(other.isSigned),
								gradeToSign(other.gradeToSign),
								gradeToExec(other.gradeToExec)
{
	std::cout << "[Form] Copy constructor has been called" << std::endl;
}

Form::~Form()
{
	std::cout << "[Form] Destructor has been called" << std::endl;
}

std::string const	&Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToExec);
}

int	Form::getGradeToExec() const
{
	return (this->gradeToSign);
}

void Form::beSigned(Bureaucrat const &other)
{
	if (other.getGrade() > this->gradeToSign)
		throw (GradeTooLowException());
	this->isSigned = true;
}

Form &Form::operator=(Form const &other)
{
	this->gradeToSign = other.getGradeToSign();
	this->gradeToExec = other.getGradeToExec();
	this->isSigned = other.getIsSigned();
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High !!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !!");
}

std::ostream &operator<<(std::ostream &flux, Form const &other)
{
	flux << other.getName() << ", grade to sign : " << other.getGradeToSign() << ", grade to execute : " << other.getGradeToExec() << ". Form ";
	if (other.getIsSigned())
		flux << "is signed.";
	else
	 	flux << "isn't signed.";
	return flux;
}
