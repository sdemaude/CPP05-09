/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:36:03 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/03 15:05:43 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "[Intern] Default constructor has been called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << "[Intern] Copy constructor has been called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor has been called" << std::endl;
}

static AForm *makeShrubberyCF(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomyRF(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidentialPF(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	AForm *(*allForm[])(std::string const &formTarget) = {&makeShrubberyCF, &makeRobotomyRF, &makePresidentialPF};
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (allForm[i](target));
		}
	}

	std::cout << "Intern could not create form named " << formName << std::endl;
	return (NULL);
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}
