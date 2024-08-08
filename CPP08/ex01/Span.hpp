/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:10:59 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/08 19:32:52 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span : public std::vector<int>
{
	private :
		unsigned int	N;

	public :
		Span();
		Span(unsigned int N);
		Span(Span const &other);
		virtual ~Span();

		void			addNumber(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		Span	&operator=(Span const &other);

		template <typename Iterator>
		void			addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void	Span::addRange(Iterator begin, Iterator end)
{
	if (distance(begin, end) + this->size() > this->N)
		throw (std::out_of_range("Too much elements in container"));
	this->insert(this->end(), begin, end);
}
