/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:42:48 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/16 16:31:08 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstdlib>

RPN::RPN()
{}
		
RPN::RPN(RPN const &other) : stack(other.stack)
{}
		
RPN::~RPN()
{}

static bool	isSymbol(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

static bool	correctLine(std::string const &line)
{
	for (int i = 0; line[i]; i++)
		if (!isdigit(line[i]) && !isspace(line[i]) && !isSymbol(line[i]))
			return (false);
	return (true);
}

int	RPN::computeExpression(std::string const &line)
{
	if (line.empty() || !correctLine(line))
		throw (IncorrectExpression());

	for (int i = 0; line[i]; i++)
	{
		if (isdigit(line[i]))
			this->stack.push(line[i] - 48); 
		else if (isSymbol(line[i]))
		{
			if (this->stack.size() < 2)
				throw (IncorrectExpression());

			int res = 0;
			int b = this->stack.top();
			this->stack.pop();
			int a = this->stack.top();
			this->stack.pop();

			switch (line[i]) {
				case '+':
				{
					res = a + b;
					break;
				}
				case '-':
				{
					res = a - b;
					break;
				}
				case '*':
				{
					res = a * b;
					break;
				}
				case '/':
				{
					if (b == 0)
						throw (IncorrectExpression());
					res = a / b;
					break;
				}
			}
			this->stack.push(res);
		}
	}
	
	if (this->stack.size() != 1)
		throw (IncorrectExpression());
	return (this->stack.top());
}

RPN	&RPN::operator=(RPN const &other)
{
	this->stack = other.stack;
	return (*this);
}

const char *RPN::IncorrectExpression::what() const throw()
{
	return ("Error, invalid expression");
}
