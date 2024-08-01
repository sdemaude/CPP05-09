/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:14:28 by sdemaude          #+#    #+#             */
/*   Updated: 2024/08/01 16:41:46 by sdemaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int	const			gradeToSign;
		int const			gradeToExec;

	public:
		Form();
		//Form(std::string const &name, int grade);
		Form(Form const &other);
		~Form();

		std::string const	&getName() const;
		bool const			&getIsSigned() const;
		int const			&getGradeToSign() const;
		int const			&getGradeToExec() const;
		void				incrementGrade();
		void				decrementGrade();

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
