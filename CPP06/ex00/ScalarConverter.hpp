/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:26:20 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/05 15:32:59 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cerrno>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);

		ScalarConverter &operator=(ScalarConverter const &other);

	public :
		~ScalarConverter();

		static void convert(std::string const &number);
};
