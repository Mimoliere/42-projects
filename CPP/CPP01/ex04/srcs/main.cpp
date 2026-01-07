#include "../includes/replaceStr.hpp"

int	main(int argc, char *argv[]) {
	int	ret = 0;

	if (argc != 4) {
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./sed <file_to_read> <str_to_replace> <new_str>" << std::endl;
		return (1);
	}

	std::cout << "str: " << argv[2] << std::endl;
	std::cout << "new: " << argv[3] << std::endl << std::endl;

	ret = replaceStr(argv);
	if (ret == 0)
		std::cout << "Replaced successfully !" << std::endl;
	return (ret);
}
