/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:03:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/10 13:48:22 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		intern;
	Bureaucrat	john("John", 1);
	std::cout << std::endl;
	AForm		*sc(intern.makeForm("shrubbery creation", "sc"));
	AForm		*rr(intern.makeForm("robotomy request", "rr"));
	AForm		*pp(intern.makeForm("presidential pardon", "pp"));
	AForm		*test(intern.makeForm("presidential pardon", "test"));

	std::cout << std::endl;
	intern.makeForm("Nothing", "Nothing");

	std::cout << std::endl;
	john.signForm(*sc);
	john.signForm(*rr);
	john.signForm(*pp);

	std::cout << std::endl;
	john.executeForm(*sc);
	std::cout << std::endl;
	john.executeForm(*rr);
	std::cout << std::endl;
	john.executeForm(*pp);
	std::cout << std::endl;
	john.executeForm(*test);

	std::cout << std::endl;
	delete sc;
	delete rr;
	delete pp;
}
