#include "BigNum.h"
#include <iostream>
#include <ctime>


void Factorial(unsigned int n)
{
	BigNum bigResult = 1;
	BigNum bigTmp = 2;
	clock_t start_calc, stop_calc;
	clock_t start_print, stop_print;


	start_calc = clock(); //start calculate
	for (unsigned int i = 1; i < n; ++i)
	{
		bigResult = bigResult * bigTmp;
		bigTmp++;
	}
	stop_calc = clock(); //stop calculate

	start_print = clock(); //start printing
	std::cout << "n! = 0x";
	bigResult.printHex();
	std::cout << std::endl;
	stop_print = clock(); //stop printing


	std::cout	<< "Time of calculation: "
				<< std::fixed << (stop_calc - start_calc) / (float)CLK_TCK
				<< " sec" << std::endl;

	std::cout	<< "Time of print: "
				<< std::fixed << (stop_print - start_print) / (float)CLK_TCK
				<< " sec" << std::endl;

	std::cout	<< "Usage memory: "
				<< bigResult.memusage()
				<< " bytes" << std::endl;


	bigResult.free();
	bigTmp.free();
}