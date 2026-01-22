#include "../includes/Contact.hpp"

Contact::Contact() {

}

void    Contact::setFirstName(std::string name) {
	_firstName = name;
}

void Contact::setLastName(std::string name) {
	_lastName = name;
}

void Contact::setNickname(std::string nick) {
	_nickname = nick;
}

void Contact::setPhone(std::string number) {
	_phone = number;
}

void Contact::setSecret(std::string s) {
	_secret = s;
}

std::string	Contact::getFirstName() {
	return (_firstName);
}

std::string Contact::getLastName() {
	return (_lastName);
}

std::string	Contact::getNickname() {
	return (_nickname);
}

std::string Contact::getPhone() {
	return (_phone);
}

std::string Contact::getSecret() {
	return (_secret);
}

std::string	Contact::toString() {
	std::string	str;

	str += "First Name : " + getFirstName() + "\n";
	str += "Last Name : " + getLastName() + "\n";
	str += "Nickname : " + getNickname() + "\n";
	str += "Phone Number : " + getPhone() + "\n";
	str += "Secret : " + getSecret() + "\n";

	return (str);
}
