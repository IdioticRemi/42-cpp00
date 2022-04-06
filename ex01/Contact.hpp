#ifndef CPP00_CONTACT_HPP
#define CPP00_CONTACT_HPP

#include <string>

class Contact {
public:
	void printInfo(int id);
	// Accessors
	const std::string &getFirstname() const;
	const std::string &getLastname() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNbr() const;
	const std::string &getDarkestSecret() const;
	void setFirstname(const std::string &firstname);
	void setLastname(const std::string &lastname);
	void setNickname(const std::string &nickname);
	void setPhoneNbr(const std::string &phoneNbr);
	void setDarkestSecret(const std::string &darkestSecret);

private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone_nbr;
	std::string	darkest_secret;
};

#endif
