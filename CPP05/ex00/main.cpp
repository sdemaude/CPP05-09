/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:03:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/10 11:47:58 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	gontran("Gontran", 5);
	Bureaucrat	cunégonde;

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << "Try to increment " << gontran << std::endl;
			gontran.incrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "Try to decrement " << cunégonde << std::endl;
		cunégonde.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "Try to initialize dumb bureaucrat" << std::endl;
		Bureaucrat	dumby("Dumb", GRADE_MIN + 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		std::cout << "Try to initialize another dumb bureaucrat" << std::endl;
		Bureaucrat	dumby2("Dumber", GRADE_MAX - 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return (0);
}
