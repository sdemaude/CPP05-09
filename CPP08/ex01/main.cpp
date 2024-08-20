/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:11:01 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/20 10:22:38 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define SIZE 10000

int main()
{
	Span	sp;
	int		i;

	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	sp = Span(SIZE);
	std::vector<int> vect;
	for (i = 1; i <= SIZE; i++)
		vect.push_back(i);
	
	try
	{
		sp.addRange(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	sp = Span(42);
	try
	{
		sp.addRange(vect.begin(), vect.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	sp.addNumber(1);
	
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
