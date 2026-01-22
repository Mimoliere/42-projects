#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact _contacts[MAX_CONTACTS];
		int		_index;
		int		_max_index;
		bool	_stop;
	public:
		PhoneBook();

		void		addContact();
		std::string	askForInformation(std::string info);
		void		searchContact();
		void		printOne(int index, Contact contact);
		std::string	truncateInfo(std::string info);
		bool		isAllNumeric(std::string str);
		bool		rightIndex(std::string str);
		void		incrementIndex();

		bool	getStop();
		void	setStop(bool val);
};

#endif
