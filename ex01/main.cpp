#include "ex01.hpp"

void welcome_user()
{
	std::cout << "==== PHONEBOOK v42.0.69 ====" << std::endl;
	std::cout << "  ADD    : Add contact" << std::endl;
	std::cout << "  SEARCH : Search contact" << std::endl;
	std::cout << "  EXIT   : Exit" << std::endl;
	std::cout << "============================" << std::endl << std::endl;
}

static void command_prompt(std::string &input)
{
	input.clear();
	std::cout << "> ";
	std::getline(std::cin, input);
}

int main()
{
	PhoneBook pb;
	std::string input;

	pb.setIdx(0);
	pb.setContactQty(0);

	welcome_user();
	command_prompt(input);
	while (!std::cin.eof() && input != "EXIT")
	{
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (!input.empty())
			std::cout << "Ermm... I'm pretty sure this is not a command." << std::endl << std::endl;
		if (std::cin.eof())
			return 1;
		command_prompt(input);
	}
	return 0;
}