#ifndef CPP00_PHONEBOOK_HPP
#define CPP00_PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
public:
	void addContact();
	void searchContact();

	int getIdx() const;

	void setIdx(int idx);

private:
	void printContacts();

	int		idx;
	int		contact_qty;
public:
	int getContactQty() const;

	void setContactQty(int contactQty);

private:
	Contact	contacts[8];
};

#endif
