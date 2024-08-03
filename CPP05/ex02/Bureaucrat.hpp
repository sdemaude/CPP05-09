/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:31:32 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/03 11:58:48 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class AForm;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		std::string const	&getName() const;
		int const			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		Bureaucrat &operator=(Bureaucrat const &other);

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &flux, Bureaucrat const &other);
