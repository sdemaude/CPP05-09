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
		std::cerr << "One file expected as argument" << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange converter;
	if (!converter.setData(DATA_FILE))
		return (EXIT_FAILURE);
	converter.convertValue(argv[1]);
	return (EXIT_SUCCESS);
}
