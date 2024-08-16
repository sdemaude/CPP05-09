/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:27 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 11:57:53 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define DATA_FILE "data.csv"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "One file expected as argument" << std::endl;
		return (0);
	}

	BitcoinExchange converter;
	if (!converter.setData(DATA_FILE))
		return (1);
	converter.convertValue(argv[1]);
	return (0);
}
