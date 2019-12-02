# Labs-and-Practice-2-course-

1.Реализовать класс Set. 
Имеется в виду множество, с двумя заданными операциями над его элементами ( операции задаются двумерными массивами, a+b == massPlus[a][b] ).

Возможный вариант реализации:
Данные: int* mass, int** massPlus, int** massMult.
Методы: несколько конструкторов, операции для элементов множества - plus(), mult(),вывод элементов множества, вывод таблиц операций над элементами множества  - display() или show().
Глобальная функция (или функция-член класса): 
bool isField(const Set& set) – реализовать функцию проверки объекта типа Set на поле, является ли такое множество, с такими операциями полем? 
(коммутативность сложения, ассоциативность сложения, существование нейтрального элемента по сложению, существование обратного по сложению, 
коммутативность умножения, ассоциативность умножения, существование нейтрального по умножению, существование обратного по умножению, дистрибутивность).
main: входной параметр – файл, подготовленный преподавателем set.txt, ваша программа даёт ответ, является ли входной объект полем.

set.txt:
4
0 1 2 3
0 1 2 3 1 0 3 2 2 3 0 1 3 2 1 0
0 0 0 0 0 1 2 3 0 2 3 1 0 3 1 2


2.Пользователь вводит n (в пределах unsigned int). Программа вычисляет и выводит n!
Необходимо измерять скорость вычисления.


3.Реализовать игру Gomoku (крестики-нолики).
Необходимы, как минимум, два класса: Board, BoardView.
Для псевдографики можно использовать ConsoleGraphic.h и ConsoleGraphic.cpp, выданные преподавателем,
либо использовать любую библиотеку 2D графики C++ на свой выбор.
Помним, что модуль Model придётся впоследствии переносить в другой проект.


4.Реализовать шаблонные классы умных указателей Scoped_Ptr, Auto_Ptr, Shared_Ptr.
main: продемонстрировать работу оборачивая ими любые свои/чужие классы (например Person).
1) Несколько умных указателей на один и тот же объект Person.
2) Передача умного указателя в функции: по значению, по указателю, по ссылке.
3) Массив умных указателей на объекты. Сортировка такого массива по возрасту объектов типа Person.


5.Реализовать игру Gomoku (крестики-нолики) в графическом интерфейсе WinForms(C++/CLI) / либо в любом другом граф. интерфейсе.
Использовать модуль Board из задания № 3.

5-2.Реализовать змейку в WinForms либо в любом другом граф. интерфейсе.


6.Реализовать класс Record - в качестве записи может быть просто Person (имя, фамилия, телефонный номер...)
 абстрактный класс Table, два класса TableStat, TableDyn – производные от Table.
Методы Table: virtual int addRecord()=0, virtual int delRecord()=0, virtual int getCount()=0, virtual Record* getRecord()=0.
main: пользователь выбирает, с какой базой планирует работать (статическая – небольшая, до 10 записей, динамическая – большой(неограниченный объём записей).
Далее пользователю предоставляется простой интерфейс: 1-addRecord, 2-deleteRecord, 3-display, 4-sort, 5-exit для работы с базой записей.

Пример абстрактного класса Table:
class Table
{
public:
	virtual int add_Record(Record *) = 0;
	virtual int del_Record(int) = 0;
	virtual int getcount() = 0; // "сколько штук записей?"
	virtual Record* get_Record(int) = 0; //"пятую дай мне"
	virtual void swap(Record *, Record *) = 0;
};
Пример main:
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
... и т.д.

Пример программы 6.Table.exe.


7.Написать кроссплатформенную программу на С++ выполняющую следующую задачу:
допустим в текущей директории есть файлы a.txt (10 байт), 3.jpg(1000 байт),
а также папка 1 с содержимым KISH.mp3 (4000 байт)
то есть присутствуют вложенные папки с файлами

программа должна создать директорию renamedFiles с содержимым:
	1.a.txt
	2.3.jpg
	3.KISH.mp3
// файлы упорядочены по размеру
По-возможности продемонстрировать работу программы в Windows, Linux


8.Написать программу, формирующую отчёт в виде output.xlsx файла на основании данных, находящихся в файлах.xlsx в текущей директории.
Небольшой пример находится в папке example.
Количество файлов / поля / значения выбрать на свой вкус.

п.с. использовать стороннюю библиотеку для работы с xlsx

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

