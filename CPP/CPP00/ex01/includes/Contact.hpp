/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:02:30 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:02:31 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
	public:
		Contact();

		void setFirstName(std::string name);
		void setLastName(std::string name);
		void setNickname(std::string nick);
		void setPhone(std::string number);
		void setSecret(std::string s);

		std::string	getFirstName();
		std::string getLastName();
		std::string	getNickname();
		std::string getPhone();
		std::string getSecret();

		std::string toString();
};

#endif
