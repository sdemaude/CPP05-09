/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:23:04 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/14 15:16:06 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>

class Date : public std::tm
{
	public :
		Date();
		Date(int year, int month, int day);
		Date(Date const &other);
		~Date();

		bool	isValid();

		Date	&operator=(Date const &other);

		bool	operator<(Date const &other);
		bool	operator==(Date const &other);
		
		class InvalidDateFormat : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &flux, Date const &date);
