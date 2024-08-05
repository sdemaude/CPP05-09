/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:38:44 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/05 16:09:06 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

typedef struct	SData
{
	int	value1;
	int	value2;
	int	value3;
}				Data;

class Serializer
{
	private :
		Serializer();
		Serializer(Serializer const &other);

		Serializer &operator=(Serializer const &other);

	public :
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
