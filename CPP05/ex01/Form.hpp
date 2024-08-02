/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/02 13:59:45 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int					gradeToSign;
		int					gradeToExec;

	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExec);
		Form(Form const &other);
		~Form();

		std::string const	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(Bureaucrat const &other);

		Form &operator=(Form const &other);

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

std::ostream &operator<<(std::ostream &flux, Form const &other);
