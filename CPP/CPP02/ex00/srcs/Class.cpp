#include "../includes/Class.hpp"

Class::Class() {

}

int	Class::get_att1() {
	return att1;
}

std::string	Class::get_att2() {
	return att2;
}

void	Class::set_att1(int new_att1) {
	att1= new_att1;
}

void	Class::set_att2(std::string new_att2) {
	att2= new_att2;
}
