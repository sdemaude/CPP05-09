/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:42:49 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 15:34:18 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int>	stack;

	public:
		RPN();
		RPN(RPN const &other);
		~RPN();

		int	computeExpression(std::string const &line);

		RPN	&operator=(RPN const &other);

		class IncorrectExpression : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};
