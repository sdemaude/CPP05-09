/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:24 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/15 18:30:07 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


bool	toMap(char const *line, std::map<Date, double> map)
{
	bool	correctFile = true;
	int		i = 0;
	int		year;
	int		month;
	int		day;
	double	value;

	while(line[i] && !isdigit(line[i]))
		i++;
	if (!line[i])
		return (false);
	year = 0;
	month = 0;
	day = 0;
	value = 0;

	year = atoi(line + i);
	while (line[i] && line[i] != '-')
		i++;
	i++;
	month = atoi(line + i);
	while (line[i] && line[i] != '-')
		i++;
	i++;
	day = atoi(line + i);
	while (line[i] && line[i] != '|')
		i++;
	while(line[i] && (!isdigit(line[i]) && line[i] != '-'))
		i++;
	value = strtod(line + i, NULL);
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	
	try
	{
		Date inmap(year, month, day);
		map[inmap] = value;
		std::cout << "Value at Key " << inmap << " is: " << map.at(inmap) << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << "Error bad input !" << std::endl;
		correctFile = false;
	}
	return (correctFile);
}
/*
	std::ifstream infileDB;
	//infileDB.open(DATA_FILE);
	

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open())
		std::cout << "Could not open database file, check permissions" << std::endl;
	
	std::map<Date, double> map;
	for (std::string line; std::getline(infileDB, line);)
		toMap(line.c_str(), map);

	input.close();
*/
