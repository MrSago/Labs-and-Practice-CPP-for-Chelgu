#include "Header.h"
#include <iostream>

#define COUNT 1024
#define SIZE ((COUNT * MB) / sizeof(int))

void scoped_example()
{
	std::cout << "Start scoped_example" << std::endl;

	scoped_ptr <int> arr = new int[SIZE];
	std::cout << "arr created" << std::endl;
	getchar();

	std::cout << "End scoped_example" << std::endl;
}

void auto_example()
{
	std::cout << "Start auto_example" << std::endl;

	auto_ptr <int> arr1 = new int[SIZE];
	std::cout << "arr1 created" << std::endl;
	getchar();

	auto_ptr <int> arr2 = arr1;
	std::cout << "arr2 = arr1" << std::endl;
	getchar();

	auto_ptr <int> arr3 = new int[SIZE];
	std::cout << "arr3 created" << std::endl;
	getchar();

	arr2 = arr3;
	std::cout << "arr2 = arr3" << std::endl;
	getchar();
	
	std::cout << "End auto_example" << std::endl;
}

void shared_example()
{
	std::cout << "Start shared_example" << std::endl;

	{
		shared_ptr <int> arr1 = new int[SIZE];
		std::cout << "arr1 created" << std::endl;
		getchar();

		shared_ptr <int> arr2 = arr1;
		std::cout << "arr2  = arr1" << std::endl;
		getchar();
	}

	std::cout << "end of scope" << std::endl;
	getchar();

	{
		shared_ptr <int> arr3 = new int[SIZE];
		std::cout << "arr3 created" << std::endl;
		getchar();

		{
			shared_ptr <int> arr4 = arr3;
			std::cout << "arr4 = arr3" << std::endl;
			getchar();
		}
	}
	std::cout << "end of scope" << std::endl;
	getchar();

	std::cout << "Stop shared_example" << std::endl;
}