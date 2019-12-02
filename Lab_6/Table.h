#ifndef TABLE_H
#define TABLE_H

#include "Record.h"

class Table : protected Record
{
public:	virtual void add_Record() = 0;
		virtual void del_Record() = 0;
		virtual void print() = 0;
		virtual size_t get_Count() = 0;
		virtual Record* get_Record(unsigned short) = 0;
};

class TableStat : public Table
{
public:	TableStat() { this->arr.reserve(10); }

public:	void add_Record();
		void del_Record();
		void print();
		size_t get_Count();
		Record* get_Record(unsigned short);
};

class TableDyn : public Table
{
public:	void add_Record();
		void del_Record();
		void print();
		size_t get_Count();
		Record* get_Record(unsigned short);
};

#endif //TABLE_H