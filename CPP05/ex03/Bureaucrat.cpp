/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:42:55 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/12 11:02:19 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "[Bureaucrat] Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	std::cout << "[Bureaucrat] Special constructor has been called" << std::endl;
	if (grade < GRADE_MAX)
		throw (GradeTooHighException());
	else if (grade > GRADE_MIN)
		throw (GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
	std::cout << "[Bureaucrat] Copy constructor has been called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor has been called" << std::endl;
}

std::string const	&Bureaucrat::getName() const
{
	return (this->name);
}

int const	&Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < GRADE_MAX)
		throw (GradeTooHighException());
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > GRADE_MIN)
		throw (GradeTooLowException());
	this->grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned())
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because it's already signed" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because grade is too low" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		std::cout << this->name << " try to execute " << form.getName() << std::endl;
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.getGrade();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High !!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low !!");
}

std::ostream &operator<<(std::ostream &flux, Bureaucrat const &other)
{
	flux << other.getName() << ", bureaucrat grade " << other.getGrade();
	return flux;
}
