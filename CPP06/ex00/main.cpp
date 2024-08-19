/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:07 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/19 10:52:29 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "One parameter expected !" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
