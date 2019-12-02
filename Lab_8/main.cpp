#include <iostream>
#include <conio.h>
#include "libxl.h"
#include <vector>

using namespace libxl;

int main()
{
	Book* book;
	Sheet* sheet;
	std::vector<size_t> age;
	size_t d, sum = 0;
	size_t i;



	if (!(book = xlCreateBook()))
		return -1;
	if (!book->load(L"data1.xls"))
		return -1;
	if (!(sheet = book->getSheet(0)))
		return -1;

	i = 2;
	d = (size_t)sheet->readNum((int)i++, 2);
	while (d)
	{
		age.push_back(d);
		d = (size_t)sheet->readNum((int)i++, 2);
	}
	book->release();



	if (!(book = xlCreateBook()))
		return -1;
	if (!book->load(L"data2.xls"))
		return -1;
	if (!(sheet = book->getSheet(0)))
		return -1;

	i = 2;
	d = (size_t)sheet->readNum((int)i++, 2);
	while (d)
	{
		age.push_back(d);
		d = (size_t)sheet->readNum((int)i++, 2);
	}
	book->release();



	for (size_t k = 0; k < age.size(); ++k)
		sum += age[k];

	sum = sum / age.size();
	std::cout << "Avarage age: " << sum << std::endl;

	if (!(book = xlCreateBook()))
		return -1;
	if (!(sheet = book->addSheet(L"Sheet1")))
		return -1;

	sheet->writeStr(2, 1, L"Avarage age:");
	sheet->writeNum(2, 2, (double)sum);

	if (book->save(L"output.xls"))
		std::cout << "Saved at output.xls" << std::endl;
	else return -1;
	book->release();



	_getch();
	return 0;
}