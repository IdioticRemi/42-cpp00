#include <iostream>

static void putstr_up(std::string str)
{
	for (int j = 0; str[j]; j++)
	{
		if (str[j] >= 'a' && str[j] <= 'z')
			std::cout << (char)std::toupper(str[j]);
		else
			std::cout << str[j];
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		for (int i = 1; i < argc; i++)
			putstr_up(argv[i]);
	else
		putstr_up("* loud and unbearable feedback NoIsE *");
	std::cout << std::endl;
	return (0);
}
