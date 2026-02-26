#include "../includes/Bureaucrat.hpp"

int main(void) {
	Bureaucrat	a("Adrian", 1);
	Bureaucrat *b = NULL;

	try {
		b = new Bureaucrat("Brian", 151);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << b << std::endl;

	try {
		Bureaucrat	c("Crian", 151);
		std::cout << c;
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	try {
		a.incr_grade();
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << a;

	delete b;

	return (0);
}
