/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:03:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/01 16:15:26 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	astride("Astride", 5);
	Bureaucrat	william;

	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << "Try to increment " << astride << std::endl;
			astride.incrementGrade();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	try
	{
		std::cout << "Try to decrement " << william << std::endl;
		william.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "Try to initialize dumb bureaucrat" << std::endl;
		Bureaucrat	dumby("Dumbo", GRADE_MIN + 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Try to initialize another dumb bureaucrat" << std::endl;
		Bureaucrat	dumby2("Dumbo", GRADE_MAX - 1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
