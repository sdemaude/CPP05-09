/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:52:26 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/05 17:00:39 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	srand(time(NULL));

    Base *x(generate());
    Base *y(generate());
    Base *z(generate());

	identify(x);
    identify(y);
    identify(z);

	std::cout << std::endl;

    identify(*x);
    identify(*y);
    identify(*z);
    
    delete x;
    delete y;
    delete z;
}
