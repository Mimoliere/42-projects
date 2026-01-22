#include <cctype>
#include <iostream>

int	main(int argc, char **argv) {
	std::string	arg;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			arg = argv[i];
			for (int j = 0; arg[j]; j++) {
				arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));
			}
			std::cout << arg;
		}
	}
	std::cout << std::endl;
	return (0);
}
