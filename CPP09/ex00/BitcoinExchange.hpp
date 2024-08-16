/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 11:19:29 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

#include "Date.hpp"

class Date;

class BitcoinExchange
{
	protected:
		std::map<Date, float>	data;
		float	findClosest(Date const &key) const;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		bool	setData(std::string const &fileName);
		void	convertValue(std::string const &fileName);

		BitcoinExchange &operator=(BitcoinExchange const &other);

		class NegativeNumber : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class TooLargeNumber : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};
