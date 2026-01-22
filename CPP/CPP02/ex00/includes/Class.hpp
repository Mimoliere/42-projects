#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>

#pragma once

class Class {

	private:
		int		att1;
		std::string		att2;

	public:
		Class();
		int	get_att1();
		std::string	get_att2();
		void	set_att1(int);
		void	set_att2(std::string);
};

#endif
