/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:33:47 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:16 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int len, void f(T &))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void iter(T const *array, int len, void f(T const &))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void print(T &param)
{
	std::cout << param << std::endl;
}

template <typename T>
void printc(T const &param)
{
	std::cout << param << std::endl;
}
