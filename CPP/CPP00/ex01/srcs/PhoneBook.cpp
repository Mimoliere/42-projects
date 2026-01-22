#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	_index = 0;
	_max_index = _index;
	_stop = 1;
}

void    PhoneBook::addContact() {
	std::string buffer;

	std::cout << std::endl << "Please enter the new contact informations." << std::endl;
	
	_contacts[_index].setFirstName(askForInformation("First Name"));
	if (_contacts[_index].getFirstName().empty())
		return ;

	_contacts[_index].setLastName(askForInformation("Last Name"));
	if (_contacts[_index].getLastName().empty())
		return ;

	_contacts[_index].setNickname(askForInformation("Nickname"));
	if (_contacts[_index].getNickname().empty())
		return ;

	_contacts[_index].setPhone(askForInformation("Phone Number"));
	if (_contacts[_index].getPhone().empty())
		return ;

	_contacts[_index].setSecret(askForInformation("Secret"));
	if (_contacts[_index].getSecret().empty())
		return ;

	incrementIndex();

	std::cout << std::endl;
}

std::string	PhoneBook::askForInformation(std::string info) {
	std::string	buffer;

	do {
		std::cout << info << " : ";
		if (!getline(std::cin, buffer)) {
			setStop(false);
			std::cout << std::endl;
			return ("");
		}
	} while (buffer.empty());
	return (buffer);
}

void	PhoneBook::searchContact() {
	std::string	indexSearch;

	std::cout << std::endl << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _max_index; i++)
		printOne(i, _contacts[i]);
	std::cout << std::endl;

	do {
		std::cout << "Index of the contact you want to display : ";
		if (!getline(std::cin, indexSearch)) {
			setStop(false);
			std::cout << std::endl;
			return ;
		}
	} while (indexSearch.empty() || !rightIndex(indexSearch));

	std::cout << std::endl << _contacts[atoi(indexSearch.c_str()) - 1].toString() << std::endl;
}

void	PhoneBook::printOne(int index, Contact contact) {
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << truncateInfo(contact.getFirstName()) << "|";
	std::cout << std::setw(10) << truncateInfo(contact.getLastName()) << "|";
	std::cout << std::setw(10) << truncateInfo(contact.getNickname()) << std::endl;
}

std::string	PhoneBook::truncateInfo(std::string info) {
	std::string	str;

	str = info.substr(0,9);

	if (info.length() > 10)
		str += '.';
	else if (info.length() == 10)
		str += info[9];

	return (str);
}

bool	PhoneBook::isAllNumeric(std::string str) {

	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

bool	PhoneBook::rightIndex(std::string str) {

	int	value = atoi(str.c_str());

	return (value >= 1 && value <= _max_index);
}

void	PhoneBook::incrementIndex() {
	_index++;
	if (_max_index < MAX_CONTACTS)
		_max_index = _index;
	if (_index == 8)
		_index = 0;
}

bool	PhoneBook::getStop() {
	return (_stop);
}

void	PhoneBook::setStop(bool val) {
	_stop = val;
}
