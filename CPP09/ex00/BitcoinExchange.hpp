/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:48:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/15 18:25:29 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <cstdlib>
#include <cctype>
#include <map>

#include "Date.hpp"

#define DATA_FILE "data.csv"

class Date;

class BitcoinExchange
{
	protected:
		std::map<Date, float>	data;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &other);
};
