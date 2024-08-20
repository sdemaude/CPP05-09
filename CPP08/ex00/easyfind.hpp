/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:53:15 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/20 10:03:33 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator	find = std::find(container.begin(), container.end(), toFind);

	if (find == container.end())
		throw (std::runtime_error("Nothing found in container..."));
	return (find);
}
