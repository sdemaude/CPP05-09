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

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : data(other.data)
{}

BitcoinExchange::~BitcoinExchange()
{}

static bool	toMap(char const *line, std::map<Date, double> &map)
{
	int		i = 0;
	int		year;
	int		month;
	int		day;
	double	value;

	while(line[i] && !isdigit(line[i]))
		i++;
	if (!line[i])
		return (true); //old was false
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
	while (line[i] && line[i] != ',')
		i++;
	i++;
	value = strtod(line + i, NULL);

	try
	{
		Date inmap(year, month, day);
		map[inmap] = value;
		//std::cout << "Value at Key " << inmap << " is: " << map.at(inmap) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error bad input !" << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::setData(std::string const &fileName)
{
	bool	correctFile = true;

	std::ifstream infileDB;
	infileDB.open(fileName);

	if (!infileDB.is_open())
	{
		std::cout << "Could not open database file, check permissions" << std::endl;
		return (false);
	}

	std::map<Date, double> map;
	for (std::string line; std::getline(infileDB, line);)
		if (!toMap(line.c_str(), map))
			correctFile = false;

	infileDB.close();
	return (correctFile);
}

static bool	getInfo(char const *line, int *year, int *month, int *day, double *amount)
{
	int		i = 0;

	(void)year;
	(void)month;
	(void)day;
	(void)amount;

	while (line[i] && !isdigit(line[i]))
		i++;
	if (!line[i])
		return (false);

	*year = atoi(line + i);
	while (line[i] && line[i] != '-')
		i++;
	i++;
	*month = atoi(line + i);
	while (line[i] && line[i] != '-')
		i++;
	i++;
	*day = atoi(line + i);
	while (line[i] && line[i] != '|')
		i++;
	while (line[i] && (!isdigit(line[i]) && line[i] != '-'))
		i++;
	*amount = strtod(line + i, NULL);

	return (true);
}

void BitcoinExchange::convertValue(std::string const &fileName)
{
	std::ifstream infile;
	infile.open(fileName);
	if (!infile.is_open())
	{
		std::cout << "Could not open input file, check permissions" << std::endl;
		return;
	}

	for (std::string line; std::getline(infile, line);)
	{
		try
		{
			int		year = 0;
			int		month = 0;
			int		day = 0;
			double	amount = 0;

			getInfo(line.c_str(), &year, &month, &day, &amount);
			Date date(year, month, day);

			std::cout << date << " => " << amount << " = " << amount * this->data.at(date) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout <<  "Error : ..." << e.what() << std::endl;
		}
	}

	infile.close();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	this->data = other.data;
	return (*this);
}