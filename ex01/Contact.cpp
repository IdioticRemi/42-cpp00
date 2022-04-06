#include <iomanip>
#include <iostream>
#include "Contact.hpp"

const std::string &Contact::getFirstname() const {
	return firstname;
}

void Contact::setFirstname(const std::string &firstname) {
	Contact::firstname = firstname;
}

const std::string &Contact::getLastname() const {
	return lastname;
}

void Contact::setLastname(const std::string &lastname) {
	Contact::lastname = lastname;
}

const std::string &Contact::getNickname() const {
	return nickname;
}

void Contact::setNickname(const std::string &nickname) {
	Contact::nickname = nickname;
}

const std::string &Contact::getPhoneNbr() const {
	return phone_nbr;
}

void Contact::setPhoneNbr(const std::string &phoneNbr) {
	phone_nbr = phoneNbr;
}

const std::string &Contact::getDarkestSecret() const {
	return darkest_secret;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	darkest_secret = darkestSecret;
}

static std::string trim(std::string str)
{
	if (str.length() >= 10)
		return str.substr(0, 9).append(".");
	return str;
}

void Contact::printInfo(int id) {
	std::cout << std::setfill(' ') << std::setw(10) << id;
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << trim(getFirstname());
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << trim(getLastname());
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << trim(getNickname());
	std::cout << " |";
	std::cout << std::endl;
}
