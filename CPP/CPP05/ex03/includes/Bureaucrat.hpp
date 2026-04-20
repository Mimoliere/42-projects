/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:02:42 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:02:43 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string	get_name() const;
		int					get_grade() const;
		void				set_grade(int new_grade);

		void				incr_grade();
		void				decr_grade();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high! Highest grade is 1.";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low! Lowest grade is 150.";
				}
		};

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
