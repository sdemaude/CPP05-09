/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:24 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 14:40:07 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : data(other.data)
{}

BitcoinExchange::~BitcoinExchange()
{}

static bool	toMap(char const *line, std::map<Date, float> &map)
{
	int		i = 0;
	int		year;
	int		month;
	int		day;
	double	value;

	while(line[i] && !isdigit(line[i]))
		i++;
	if (!line[i])
		return (true);
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
	infileDB.open(fileName.c_str());

	if (!infileDB.is_open())
	{
		std::cout << "Could not open database file, check permissions" << std::endl;
		return (false);
	}

	for (std::string line; std::getline(infileDB, line);)
		if (!toMap(line.c_str(), this->data))
			correctFile = false;

	infileDB.close();
	return (correctFile);
}

static bool digitInString(std::string const &str)
{
	for (size_t i = 0 ; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			return (true);
	}
	return (false);
}

static bool	getInfo(char const *line, int *year, int *month, int *day, double *amount)
{
	int		i = 0;

	while (line[i] && !isdigit(line[i]))
		i++;
	if (!line[i])
		return (false);
	*year = atoi(line + i);
	while (line[i] && isdigit(line[i]))
		i++;
	if (line[i] != '-')
		return (false);
	i++;
	*month = atoi(line + i);
	while (line[i] && isdigit(line[i]))
		i++;
	if (line[i] != '-')
		return (false);
	i++;
	*day = atoi(line + i);
	while (line[i] && (isdigit(line[i]) || isspace(line[i])))
		i++;
	if (line[i] != '|')
		return (false);
	i++;
	while (line[i] && isspace(line[i]))
		i++;
	*amount = strtod(line + i, NULL);

	if (*amount < 0)
		i++;
	while (line[i] && (isdigit(line[i]) || line[i] == '.'))
		i++;
	if (line[i])
		throw (Date::InvalidDateFormat());

	if (*amount < 0)
		throw (BitcoinExchange::NegativeNumber());
	if (*amount > 1000)
		throw (BitcoinExchange::TooLargeNumber());

	return (true);
}

void BitcoinExchange::convertValue(std::string const &fileName)
{
	std::ifstream infile;
	infile.open(fileName.c_str());
	if (!infile.is_open())
	{
		std::cout << "Could not open input file, check permissions" << std::endl;
		return;
	}

	for (std::string line; std::getline(infile, line);)
	{
		if (!digitInString(line))
			std::getline(infile, line);
		try
		{
			int		year = 0;
			int		month = 0;
			int		day = 0;
			double	amount = 0;

			getInfo(line.c_str(), &year, &month, &day, &amount);
			Date date(year, month, day);
			std::cout << date << " => " << amount << " = " << amount * this->findClosest(date) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout <<  "Error : " << e.what();	
			try 
			{
				(void)dynamic_cast<Date::InvalidDateFormat&>(e);
				std::cout << line << std::endl;
			}
			catch (std::exception &)
			{
				std::cout << std::endl;
			}
		}
	}

	infile.close();
}

float	BitcoinExchange::findClosest(Date const &key) const
{
	std::map<Date, float>::const_iterator it = this->data.begin();
	float	valueAtKey = 0;

	while (it != this->data.end())
	{
		if (key < it->first)
			break;
		valueAtKey = it->second;
		it++;
	}
	return (valueAtKey);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	this->data = other.data;
	return (*this);
}

const char *BitcoinExchange::NegativeNumber::what() const throw()
{
	return ("not a positive number.");
}

const char *BitcoinExchange::TooLargeNumber::what() const throw()
{
	return ("too large a number.");
}
