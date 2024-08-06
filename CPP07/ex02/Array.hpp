/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:07:22 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/06 11:31:26 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <string>

template <typename T>
class Array
{
	private :
		T				*elements;
		unsigned int	len;

	public :
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();

		int	size() const;

		Array	&operator=(Array const &other);
		T		&operator[](unsigned int index);
		T const &operator[](unsigned int index) const;
};

template <typename T>
Array<T>::Array() : elements(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), len(n)
{
}

template <typename T>
Array<T>::Array(Array const &other) : elements(new T[other.len]), len(other.len)
{
	for (unsigned int i = 0; i < len; i++)
		this->elements[i] = other.elements[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->elements;
}

template <typename T>
int	Array<T>::size() const
{
	return (this->len);
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	delete [] this->elements;
	this->elements = new T[other.len];
	this->len = other.len;
	for (unsigned int i = 0; i < this->len; i++)
		this->elements[i] = other.elements[i];
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->len)
		throw (std::out_of_range("Index is out of bounds..."));
	return (this->elements[index]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->len)
		throw (std::out_of_range("Index is out of bounds..."));
	return (this->elements[index]);
}
