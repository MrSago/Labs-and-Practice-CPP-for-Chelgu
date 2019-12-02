#include <iostream>
#include <conio.h>
#include "Table.h"


int main()
{
	Table *otable;
	char _c;

	std::cout << "Static or dynamic? (1/2)";
	while (true)
	{
		_c = _getch();
		if (_c == '1')
		{
			otable = new TableStat;
			_c = 0;
			break;
		}
		if (_c == '2')
		{
			otable = new TableDyn;
			_c = 0;
			break;
		}
		std::cout << "Please again" << std::endl;
	}
	
	while (true)
	{
		system("cls");

		std::cout << "1-add 2-del 3-display 4-count 5-exit" << std::endl;

		_c = _getch();
		switch (_c)
		{
		case '1':
			otable->add_Record();
			otable->print();
			_getch();
			break;

		case '2':
			otable->del_Record();
			otable->print();
			_getch();
			break;

		case '3':
			otable->print();
			_getch();
			break;

		case '4':
			std::cout << otable->get_Count();
			otable->print();
			_getch();
			break;

		case '5':
			return 0;
		}
	}
}