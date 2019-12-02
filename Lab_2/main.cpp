#include <iostream>

void Factorial(unsigned int n);

int main()
{
	unsigned int n;
	std::cout << "Enter n = "; std::cin >> n;
	Factorial(n);
	getchar();
	getchar();
	return 0;
}