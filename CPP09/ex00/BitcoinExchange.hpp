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
#include <iostream>
#include <map>

#include "Date.hpp"

class Date;

class BitcoinExchange
{
	protected:
		std::map<Date, float>	data;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		bool	setData(std::string const &fileName);
		void	convertValue(std::string const &fileName);

		BitcoinExchange &operator=(BitcoinExchange const &other);
};
