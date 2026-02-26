#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();

	std::cout << "Bureaucrat " << _name << " of grade " << _grade << " initiated." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.get_name()), _grade(other.get_grade()) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		// On fait comment pour copier le nom ???
		_grade = other.get_grade();
	}

	return (*this);
}

Bureaucrat::~Bureaucrat() {

}

const std::string	Bureaucrat::get_name() const {
	return (_name);
}

int	Bureaucrat::get_grade() const {
	return (_grade);
}

void	Bureaucrat::incr_grade() {
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();

	_grade--;
}

void	Bureaucrat::decr_grade() {
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();

	_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << "." << std::endl;
	return (os);
}
