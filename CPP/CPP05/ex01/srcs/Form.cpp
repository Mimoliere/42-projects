#include "../includes/Form.hpp"

Form::Form(const std::string name, const int signGrade, const int execGrade)
: _name(name), _grade_to_sign(signGrade), _grade_to_exec(execGrade), _signed(0) {

}

Form::~Form() {

}

const std::string	Form::get_name() const {
	return (_name);
}

bool	Form::get_signed() const {
	return (_signed);
}

const int	Form::get_grade_to_sign() const {
	return (_grade_to_sign);
}

const int	Form::get_grade_to_exec() const {
	return (_grade_to_exec);
}

void	Form::set_signed(bool new_signed) {
	_signed = new_signed;
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	os << form.get_name() << "form is " << (form.get_signed() ? "signed." : "not signed.") << std::endl;
	os << "Minimum grade to sign it : " << form.get_grade_to_sign() << std::endl;
	os << "Minimum grade to execute it : " << form.get_grade_to_exec() << std::endl;
	return (os);
}
