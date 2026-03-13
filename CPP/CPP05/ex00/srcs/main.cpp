#include "../includes/Bureaucrat.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

static void print_header(const std::string& title) {
	std::cout << "\n" << BOLD << CYAN << "==== " << title << " ====" << RESET << std::endl;
}

static void print_ok(const std::string& msg) {
	std::cout << GREEN << "[OK] " << RESET << msg << std::endl;
}

static void print_fail(const std::exception& e) {
	std::cout << RED << "[EXCEPTION] " << RESET << " -> " << e.what() << std::endl;
}

int main(void) {
	print_header("Valid constructions");
	try {
		Bureaucrat top("Adrian", 1);
		Bureaucrat low("Lara", 150);
		print_ok("Creation at both valid bounds");
		std::cout << top;
		std::cout << low;
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Invalid constructions");
	try {
		Bureaucrat tooHigh("Brian", 0);
		std::cout << tooHigh;
		print_ok("This line should not be reached");
	} catch (const std::exception& e) {
		print_fail(e);
	}
	try {
		Bureaucrat tooLow("Crian", 151);
		std::cout << tooLow;
		print_ok("This line should not be reached");
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Increment/decrement limits");
	try {
		Bureaucrat a("Alex", 2);
		a.incr_grade();
		print_ok("Increment from 2 to 1 works");
		std::cout << a;
		a.incr_grade();
		print_ok("This line should not be reached");
	} catch (const std::exception& e) {
		print_fail(e);
	}
	try {
		Bureaucrat d("Dina", 149);
		d.decr_grade();
		print_ok("Decrement from 149 to 150 works");
		std::cout << d;
		d.decr_grade();
		print_ok("This line should not be reached");
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Copy and assignment behavior");
	try {
		Bureaucrat original("Eva", 42);
		Bureaucrat copy(original);
		print_ok("Copy constructor keeps name and grade");
		std::cout << copy;

		Bureaucrat assigned("Frank", 130);
		assigned = original;
		std::cout << YELLOW << "[INFO] " << RESET
			<< "After assignment, name stays constant and grade is copied:" << std::endl;
		std::cout << assigned;
	} catch (const std::exception& e) {
		print_fail(e);
	}

	return (0);
}
