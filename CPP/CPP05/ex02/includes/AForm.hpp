/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:02:32 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:02:32 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;

	public:
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		const std::string	get_name() const;
		bool				get_signed() const;
		int					get_grade_to_sign() const;
		int					get_grade_to_exec() const;

		void			beSigned(const Bureaucrat& brc);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			pre_execute(int const grade) const;

		static int	check_grade(const int grade);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return "Grade is too low!";
				}
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "This form is not signed yet.";
				}
		};

		class NotEnoughGradeToExec : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Your grade is too low to execute this form.";
				}
		};

};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
