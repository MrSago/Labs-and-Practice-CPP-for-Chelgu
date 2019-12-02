#include "ProcessInf.h"
#include <conio.h>
#include <iostream>


int main() {
	
	Process p;
	int _c;

	std::cout << "1. Full information	2. Main information" << std::endl;
	do {
		_c = _getch();
	} while (_c != '1' && _c != '2');

	switch (_c) {
	case '1':
		std::cout << "Scanning process, please wait!" << std::endl;
		p.GetFullProcessInfo();
		p.PrintFullInfo();
		break;

	case '2':
		p.GetMainProcessInfo();
		p.PrintMainInfo();
		break;

	default:
		break;
	}

	_getch();
	return 0;
}