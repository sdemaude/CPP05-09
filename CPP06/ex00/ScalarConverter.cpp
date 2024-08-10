/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:26:21 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/10 14:09:50 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConvertert] Default constructor has been called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
	std::cout << "[ScalarConvertert] Copy constructor has been called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConvertert] Destructor has been called" << std::endl;
}


void ScalarConverter::convert(std::string const &number)
{
	double		nb;
	double		intpart;
	char		*end;
	std::string dot;

	nb = strtod(number.c_str(), &end);
	if (end == number)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl; 
		std::cout << "float : impossible" << std::endl; 
		std::cout << "double : impossible" << std::endl; 
		return ;
	}

	if (std::isnan(nb) or std::isinf(nb))
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl; 
	}
	else
	{
		if (nb < CHAR_MIN or nb > CHAR_MAX)
			std::cout << "char : impossible" << std::endl;
		else if (isprint(static_cast<int>(nb)))
			std::cout << "char : '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;

		if (nb < INT_MIN or nb > INT_MAX)
			std::cout << "int : impossible" << std::endl; 
		else
			std::cout << "int : " << static_cast<int>(nb) << std::endl; 
	}

	if (std::modf(nb, &intpart) == 0 and !std::isinf(nb))
		dot = ".0";

	if ((nb < -FLT_MAX or nb > FLT_MAX) and !std::isinf(nb))
		std::cout << "float : impossible" << std::endl; 
	else
		std::cout << "float : " << static_cast<float>(nb) << dot << "f" << std::endl;

	if (errno == ERANGE)
		std::cout << "double : impossible" << std::endl; 
	else
		std::cout << "double : " << nb << dot << std::endl;
}


ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}
