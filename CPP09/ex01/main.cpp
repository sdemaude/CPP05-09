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
		std::cerr << "The expression must be one argument !" << std::endl;
		return (EXIT_FAILURE);
	}
	
	RPN expression;
	try
	{
		std::cout << expression.computeExpression(argv[1]) << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() <<std::endl;
	}

	return (EXIT_SUCCESS);
}
