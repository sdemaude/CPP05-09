/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:17:04 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/05 17:00:43 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

class Base
{
	public :
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
