/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:53:15 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/06 13:47:01 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw (std::runtime_error("Nothing found in container..."));
	return (std::find(container.begin(), container.end(), toFind));
}
