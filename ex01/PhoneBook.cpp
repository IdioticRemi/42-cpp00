#include "PhoneBook.hpp"

int PhoneBook::getIdx() const {
	return idx;
}

void PhoneBook::setIdx(int idx) {
	PhoneBook::idx = idx % 8;
}

int PhoneBook::getContactQty() const {
	return contact_qty;
}

void PhoneBook::setContactQty(int contactQty) {
	contact_qty = contactQty;
}

static void field_prompt(std::string &input, const std::string &field)
{
	input.clear();
	std::cout << field << ": ";
	std::getline(std::cin, input);
	while (!std::cin.eof() && input.empty())
	{
		input.clear();
		std::cout << field << ": ";
		std::getline(std::cin, input);
	}
}

void PhoneBook::printContacts() {
	for (int i = 0; i < getContactQty(); i++)
		contacts[i].printInfo(i);
}

void PhoneBook::searchContact() {
	std::string input;
	Contact contact;

	if (!getContactQty())
	{
		std::cout << "Ermm, but you dont even have friends!?" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "        ID | FIRST NAME |  LAST NAME |   NICKNAME |" << std::endl;
	printContacts();
	std::cout << std::endl;
	field_prompt(input, "> Search ID");
	while (input.length() > 1 || !std::isdigit(input[0]) || input[0] - '0' > getContactQty() - 1)
	{
		if (std::cin.eof())
			return;
		std::cout << "Bro, that aint no valid ID! try again" << std::endl;
		std::cout << std::endl;
		field_prompt(input, "> Search ID");
	}
	if (std::cin.eof())
		return;
	contact = contacts[input[0] - '0'];
	std::cout << std::endl;
	std::cout << "FULL NAME       : " << contact.getFirstname() << " " << contact.getLastname() << std::endl;
	std::cout << "NICKNAME        : " << contact.getNickname() << std::endl;
	std::cout << "PHONE NUMBER    : " << contact.getPhoneNbr() << std::endl;
	std::cout << "DARKEST SECRET  : " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact() {
	std::string input;
	Contact contact;

	std::cout << std::endl;

	field_prompt(input, "First name");
	if (std::cin.eof())
		return;
	contact.setFirstname(input);
	field_prompt(input, "Last name");
	if (std::cin.eof())
		return;
	contact.setLastname(input);
	field_prompt(input, "Nickname");
	if (std::cin.eof())
		return;
	contact.setNickname(input);
	field_prompt(input, "Phone number");
	if (std::cin.eof())
		return;
	contact.setPhoneNbr(input);
	field_prompt(input, "Darkest secret");
	if (std::cin.eof())
		return;
	contact.setDarkestSecret(input);

	contacts[getIdx() % 8] = contact;
	setIdx(getIdx() + 1);
	setContactQty(std::min(getContactQty() + 1, 8));

	std::cout << std::endl;
	std::cout << "Added successfully." << std::endl;
	std::cout << std::endl;
}