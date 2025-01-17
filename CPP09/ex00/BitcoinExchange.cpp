/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:24 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/17 14:10:00 by sdemaude         ###   ########.fr       */
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

static bool digitInString(std::string const &str)
{
	for (size_t i = 0 ; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			return (true);
	}
	return (false);
}

static int	getValue(char const *line, int &i, char c, bool space)
{
	int	value = atoi(line + i);

	if (!isdigit(line[i]))
		throw (std::invalid_argument(NULL));
	
	for (; isdigit(line[i]); i++);
	if (space)
		for (; isspace(line[i]); i++);
	if (line[i] != c)
		throw (std::invalid_argument(NULL));
	i++;
	if (space)
		for (; isspace(line[i]); i++);

	return (value);
}

static bool	toMap(char const *line, std::map<Date, float> &map)
{
	int		i = 0;
	int		year = 0;
	int		month = 0;
	int		day = 0;
	double	value = 0;
	char	*endPtr = NULL;

	for (;isspace(line[i]); i++);
	try
	{
		year = getValue(line, i, '-', false);
		month = getValue(line, i, '-', false);	
		day = getValue(line, i, ',', false);

		value = strtod(line + i, &endPtr);
		if (line + i == endPtr)
			throw (std::invalid_argument(NULL));

		for (; isspace(*endPtr); endPtr++);
		if (*endPtr != '\0')
			throw (std::invalid_argument(NULL));

		Date inmap(year, month, day);
		map[inmap] = value;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: Incorrect input in .csv file!" << std::endl;
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
		std::cerr << "Could not open database file, check permissions" << std::endl;
		return (false);
	}

	for (std::string line; std::getline(infileDB, line);)
		if (digitInString(std::string(line)) && !toMap(line.c_str(), this->data))
			correctFile = false;

	infileDB.close();
	return (correctFile);
}

static void	getInfo(char const *line, int &year, int &month, int &day, double &amount)
{
	int		i = 0;
	char	*endPtr = NULL;

	for (;isspace(line[i]); i++);
	try
	{
		year = getValue(line, i, '-', false);
		month = getValue(line, i, '-', false);	
		day = getValue(line, i, '|', true);
	}
	catch (std::exception &e)
	{
		throw (Date::InvalidDateFormat());
	}

	amount = strtod(line + i, &endPtr);
	if (line + i == endPtr)
		throw (Date::InvalidDateFormat());

	for (; isspace(*endPtr); endPtr++);

	if (*endPtr != '\0')
		throw (Date::InvalidDateFormat());
	if (amount < 0)
		throw (BitcoinExchange::NegativeNumber());
	if (amount > 1000)
		throw (BitcoinExchange::TooLargeNumber());
}

void BitcoinExchange::convertValue(std::string const &fileName)
{
	std::ifstream infile;
	infile.open(fileName.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Could not open input file, check permissions" << std::endl;
		return;
	}

	for (std::string line; std::getline(infile, line);)
	{
		if (!digitInString(line))
			continue;
		try
		{
			int		year = 0;
			int		month = 0;
			int		day = 0;
			double	amount = 0;

			getInfo(line.c_str(), year, month, day, amount);
			Date date(year, month, day);
			std::cout << date << " => " << amount << " = " << amount * this->findClosest(date) << std::endl;
		}
		catch (Date::InvalidDateFormat &e)
		{
			std::cerr <<  "Error : " << e.what() << line << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr <<  "Error : " << e.what() << std::endl;
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
