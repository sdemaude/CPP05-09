/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:40:16 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/15 16:45:26 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
{
	this->tm_sec = 0;
	this->tm_min = 0;
	this->tm_hour = 0;
	this->tm_mday = 1;
	this->tm_mon = 0; //0 - 11 months since January
	this->tm_year = 0; //years since 1900
	this->tm_wday = 0;
	this->tm_yday = 0;
	this->tm_isdst = 0;
}

Date::Date(int year, int month, int day)
{
	this->tm_sec = 0;
	this->tm_min = 0;
	this->tm_hour = 0;
	this->tm_mday = day;
	this->tm_mon = month - 1; //0 - 11 months since January
	this->tm_year = year - 1900; //years since 1900
	this->tm_wday = 0;
	this->tm_yday = 0;
	this->tm_isdst = 0;

	if (!this->isValid())
		throw (InvalidDateFormat());
}

Date::Date(Date const &other)
{
	this->tm_sec = other.tm_sec;
	this->tm_min = other.tm_min;
	this->tm_hour = other.tm_hour;
	this->tm_mday = other.tm_mday;
	this->tm_mon = other.tm_mon; //0 - 11 months since January
	this->tm_year = other.tm_year; //years since 1900
	this->tm_wday = other.tm_wday;
	this->tm_yday = other.tm_yday;
	this->tm_isdst = other.tm_isdst;
}

Date::~Date()
{
}

bool	Date::isValid()
{
	Date tmp = *this;

	return (std::mktime(&tmp) > 0 && tmp == *this);
}

Date	&Date::operator=(Date const &other)
{
	this->tm_sec = other.tm_sec;
	this->tm_min = other.tm_min;
	this->tm_hour = other.tm_hour;
	this->tm_mday = other.tm_mday;
	this->tm_mon = other.tm_mon; //0 - 11 months since January
	this->tm_year = other.tm_year; //years since 1900
	this->tm_wday = other.tm_wday;
	this->tm_yday = other.tm_yday;
	this->tm_isdst = other.tm_isdst;

	return (*this);
}


bool	Date::operator<(Date const &other) const
{
	if (this->tm_year != other.tm_year)
		return (this->tm_year < other.tm_year);
	else if (this->tm_mon != other.tm_mon)
		return (this->tm_mon < other.tm_mon);
	else
		return (this->tm_mday < other.tm_mday);
	
}

bool	Date::operator==(Date const &other) const
{
	if (this->tm_year != other.tm_year)
		return (this->tm_year == other.tm_year);
	else if (this->tm_mon != other.tm_mon)
		return (this->tm_mon == other.tm_mon);
	else
		return (this->tm_mday == other.tm_mday);
}

const char *Date::InvalidDateFormat::what() const throw()
{
	return ("Date format not valid !!");
}

std::ostream &operator<<(std::ostream &flux, Date const &date)
{
	std::string zero_mon;
	std::string zero_day;
	if (date.tm_mon - 9 < 0)
		zero_mon = "0";
	if (date.tm_mday - 10 < 0)
		zero_day = "0";

	flux << date.tm_year + 1900 << "-" << zero_mon << date.tm_mon + 1 << "-" << zero_day << date.tm_mday ;
	return flux;
}
