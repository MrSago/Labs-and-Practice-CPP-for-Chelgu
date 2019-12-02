# Labs-and-Practice-2-course-

1.����������� ����� Set. 
������� � ���� ���������, � ����� ��������� ���������� ��� ��� ���������� ( �������� �������� ���������� ���������, a+b == massPlus[a][b] ).

��������� ������� ����������:
������: int* mass, int** massPlus, int** massMult.
������: ��������� �������������, �������� ��� ��������� ��������� - plus(), mult(),����� ��������� ���������, ����� ������ �������� ��� ���������� ���������  - display() ��� show().
���������� ������� (��� �������-���� ������): 
bool isField(const Set& set) � ����������� ������� �������� ������� ���� Set �� ����, �������� �� ����� ���������, � ������ ���������� �����? 
(��������������� ��������, ��������������� ��������, ������������� ������������ �������� �� ��������, ������������� ��������� �� ��������, 
��������������� ���������, ��������������� ���������, ������������� ������������ �� ���������, ������������� ��������� �� ���������, ����������������).
main: ������� �������� � ����, �������������� �������������� set.txt, ���� ��������� ��� �����, �������� �� ������� ������ �����.

set.txt:
4
0 1 2 3
0 1 2 3 1 0 3 2 2 3 0 1 3 2 1 0
0 0 0 0 0 1 2 3 0 2 3 1 0 3 1 2


2.������������ ������ n (� �������� unsigned int). ��������� ��������� � ������� n!
���������� �������� �������� ����������.


3.����������� ���� Gomoku (��������-������).
����������, ��� �������, ��� ������: Board, BoardView.
��� ������������� ����� ������������ ConsoleGraphic.h � ConsoleGraphic.cpp, �������� ��������������,
���� ������������ ����� ���������� 2D ������� C++ �� ���� �����.
������, ��� ������ Model ������� ������������ ���������� � ������ ������.


4.����������� ��������� ������ ����� ���������� Scoped_Ptr, Auto_Ptr, Shared_Ptr.
main: ������������������ ������ ���������� ��� ����� ����/����� ������ (�������� Person).
1) ��������� ����� ���������� �� ���� � ��� �� ������ Person.
2) �������� ������ ��������� � �������: �� ��������, �� ���������, �� ������.
3) ������ ����� ���������� �� �������. ���������� ������ ������� �� �������� �������� ���� Person.


5.����������� ���� Gomoku (��������-������) � ����������� ���������� WinForms(C++/CLI) / ���� � ����� ������ ����. ����������.
������������ ������ Board �� ������� � 3.

5-2.����������� ������ � WinForms ���� � ����� ������ ����. ����������.


6.����������� ����� Record - � �������� ������ ����� ���� ������ Person (���, �������, ���������� �����...)
 ����������� ����� Table, ��� ������ TableStat, TableDyn � ����������� �� Table.
������ Table: virtual int addRecord()=0, virtual int delRecord()=0, virtual int getCount()=0, virtual Record* getRecord()=0.
main: ������������ ��������, � ����� ����� ��������� �������� (����������� � ���������, �� 10 �������, ������������ � �������(�������������� ����� �������).
����� ������������ ��������������� ������� ���������: 1-addRecord, 2-deleteRecord, 3-display, 4-sort, 5-exit ��� ������ � ����� �������.

������ ������������ ������ Table:
class Table
{
public:
	virtual int add_Record(Record *) = 0;
	virtual int del_Record(int) = 0;
	virtual int getcount() = 0; // "������� ���� �������?"
	virtual Record* get_Record(int) = 0; //"����� ��� ���"
	virtual void swap(Record *, Record *) = 0;
};
������ main:
	Table *otable;
	char r;
	bool end = false;
	printf("Static or dynamic? (1/2) \n");
	while (true)
	{
		r = _getch();
		if (r == '1')
		{
			otable = new TableStat;
			r = 0;
			break;
		}
		if (r == '2')
		{
			otable = new TableDyn;
			r = 0;
			break;
		}
		printf("Please again \n");
	}
	while(end != true)
	{
		r = _getch();
		switch (r)
		{
		case '1':
			otable->add_Record(...);
			print(otable);
			break;
		case '2':
			otable->del_Record(...);
			print(otable);
			break;
... � �.�.

������ ��������� 6.Table.exe.


7.�������� ������������������ ��������� �� �++ ����������� ��������� ������:
�������� � ������� ���������� ���� ����� a.txt (10 ����), 3.jpg(1000 ����),
� ����� ����� 1 � ���������� KISH.mp3 (4000 ����)
�� ���� ������������ ��������� ����� � �������

��������� ������ ������� ���������� renamedFiles � ����������:
	1.a.txt
	2.3.jpg
	3.KISH.mp3
// ����� ����������� �� �������
��-����������� ������������������ ������ ��������� � Windows, Linux


8.�������� ���������, ����������� ����� � ���� output.xlsx ����� �� ��������� ������, ����������� � ������.xlsx � ������� ����������.
��������� ������ ��������� � ����� example.
���������� ������ / ���� / �������� ������� �� ���� ����.

�.�. ������������ ��������� ���������� ��� ������ � xlsx

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
	if (!book->load(L"data1.xlsx"))
		return -1;
	if (!(sheet = book->getSheet(0)))
		return -1;

	i = 2;
	d = (size_t)sheet->readNum(2, (int)i++);
	while (!d)
	{
		age.push_back(d);
		d = (size_t)sheet->readNum(2, (int)i++);
	}
	book->release();

	if (!(book = xlCreateBook()))
		return -1;
	if (!book->load(L"data2.xlsx"))
		return -1;
	if (!(sheet = book->getSheet(0)))
		return -1;

	i = 2;
	d = (size_t)sheet->readNum(2, (int)i++);
	while (!d)
	{
		age.push_back(d);
		d = (size_t)sheet->readNum(2, (int)i++);
	}
	book->release();

	for (size_t k = 0; k < age.size(); ++k)
		sum += age[i];

	sum = sum / age.size();

	std::cout << "sum = " << sum;
	_getch();

	return 0;
}


9.Task Manager
1. Win/Linux
2. Crossplatf
Dynamic

