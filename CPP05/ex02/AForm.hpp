/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/02 18:12:34 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		int					gradeToSign;
		int					gradeToExec;

	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExec);
		AForm(AForm const &other);
		virtual ~AForm();

		std::string const	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		virtual void		beSigned(Bureaucrat const &other);
		virtual void		beExecuted(Bureaucrat const &other);

		AForm &operator=(AForm const &other);

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

std::ostream &operator<<(std::ostream &flux, AForm const &other);
