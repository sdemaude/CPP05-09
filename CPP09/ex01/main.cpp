/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:42:46 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 16:38:28 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "The expression must be one argument !" << std::endl;
		return (0);
	}
	
	RPN expression;
	try
	{
		std::cout << expression.computeExpression(argv[1]) << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}

	return (0);
}
