/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:03:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/03 13:31:38 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				steve("Steve", 3);
	Bureaucrat				john("John", 148);
	RobotomyRequestForm		rr("rr");
	PresidentialPardonForm	pp("pp");
	ShrubberyCreationForm	sc("sc");

	std::cout << std::endl;
	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);

	std::cout << std::endl;
	john.signForm(rr);
	john.signForm(pp);
	john.signForm(sc);

	std::cout << std::endl;
	steve.signForm(rr);
	steve.signForm(pp);
	steve.signForm(sc);

	std::cout << std::endl;
	john.executeForm(rr);
	john.executeForm(pp);
	john.executeForm(sc);

	std::cout << std::endl;
	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);

	std::cout << std::endl;
	return (0);
}
