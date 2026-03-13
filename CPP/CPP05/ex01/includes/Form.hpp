#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

#pragma once

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;

	public:
		Form(const std::string name, const int signGrade, const int execGrade);
		~Form();

		const std::string	get_name() const;
		bool				get_signed() const;
		const int			get_grade_to_sign() const;
		const int			get_grade_to_exec() const;
		void				set_signed(bool new_signed);

		void	beSigned(Bureaucrat brc);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "Grade is too high! Highest grade is 1.";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "Grade is too low! Lowest grade is 150.";
				}
		};

};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
