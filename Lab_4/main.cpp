#include "Header.h"
#include <iostream>

#define PRNT_RETURNED "Returned to main function"

int main()
{
	scoped_example();
	std::cout << PRNT_RETURNED << std::endl;
	getchar();

	auto_example();
	std::cout << PRNT_RETURNED << std::endl;
	getchar();

	shared_example();
	std::cout << PRNT_RETURNED << std::endl;
	getchar();

	return 0;
}