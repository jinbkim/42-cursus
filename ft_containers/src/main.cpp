#include "../incl/Tests.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
		std::cout << "Usage : ./main or./main container" << std::endl;
	else if (argc == 1)
	{
		test_vector();
		test_list();
		test_stack();
		test_queue();
		test_map();
	}
	else if (argc == 2)
	{
		std::string container = argv[1];
		if (container == "vector")
			test_vector();
		else if (container == "list")
			test_list();
		else if (container == "stack")
			test_stack();
		else if (container == "queue")
			test_queue();
		else if (container == "map")
			test_map();
		else
			std::cout << "Wrong input!" << std::endl;
	}
	return (0);
}