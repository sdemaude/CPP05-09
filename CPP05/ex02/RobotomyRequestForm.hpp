/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:57:05 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/03 13:30:58 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();

		virtual void		beExecuted(Bureaucrat const &other) const;
		std::string const	&getTarget() const;
		
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
};
