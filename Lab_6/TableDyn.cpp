#include "Table.h"
#include <iostream>
#include <string>

void TableDyn::add_Record()
{
	system("cls");

	Record rec;

	std::cout << "Enter Name: ";
	std::cin >> rec.Name;

	std::cout << "Age: ";
	std::cin >> rec.Age;

	this->arr.push_back(rec);

	return;
}

void TableDyn::del_Record()
{
	system("cls");

	std::string num;
	size_t n;

	if (this->arr.size() == 0) return;

	this->print();

	std::cout << std::endl << "Enter num to delete: ";
	std::cin >> num;

	n = _atoi64(num.c_str());

	if (!(n > 0 && n <= this->arr.size())) return;

	this->arr.erase(this->arr.begin() + n - 1);

	return;
}

void TableDyn::print()
{
	if (this->arr.size() == 0)
	{
		std::cout << "empty" << std::endl;
		return;
	}

	for (short i = 0; i < this->arr.size(); ++i)
	{
		std::cout << i + 1 << '.' << ' ' << this->arr[i].Name << ' ' << this->arr[i].Age << std::endl;
	}
}

size_t TableDyn::get_Count() { return this->arr.size(); }

Record* TableDyn::get_Record(unsigned short index) { return &this->arr[index]; }