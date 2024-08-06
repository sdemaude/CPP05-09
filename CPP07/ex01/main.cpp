/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:33:25 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:56 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main()
{
	int			intArr[] = {4, 2, 2, 1};
	std::string const strArr[] = {"Falait", "gerer", "les", "PIPES", "dans", "minishell", "?!!"};

	iter(intArr, 4, print);
	std::cout << std::endl;
	iter(strArr, 7, printc);
	std::cout << std::endl;
}
