/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:27 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/14 18:28:19 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <fstream>

#define DATA_FILE "data.csv"

bool	toMap(std::string const &dataBase)
{
	while (dataBase)
	return true;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "One file expected as argument" << std::endl;
		return (0);
	}
	(void)argv;

	std::ifstream infileDB;
	infileDB.open(DATA_FILE);
	if (!infileDB.is_open())
		std::cout << "Could not open database file, check permissions" << std::endl;
	
	std::string dataBase;
	std::getline(infileDB, dataBase, '\0');
	infileDB.close();

	if (!toMap(dataBase))
		std::cerr << "Error" << std::endl;

	try
	{
		Date date(2140, 10, 10);
		std::cout << date << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
