/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:07 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/05 15:35:18 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "Usage : " << argv[0] << " literal" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}
