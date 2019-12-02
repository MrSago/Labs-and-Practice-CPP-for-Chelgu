#include "Module.h"
#include <iostream>

bool Board::checkLanes(short Y, short X, CellType symbol)
{
	bool cols, rows;

	for (short i = Y - offSet; i < mode + Y - offSet; ++i)
	{
		cols = true;
		rows = true;

		for (short j = X - offSet; j < mode + X - offSet; ++j)
		{
			cols &= field[i][j] == symbol;
			rows &= field[j][i] == symbol;
		}

		if (cols || rows) return true;
	}

	return (cols || rows);
}

bool Board::checkDiagonals(short Y, short X, CellType symbol)
{
	bool toright = true,
		 toleft = true;

	for (short i = 0; i < mode; ++i)
	{
		toright &= field[Y - offSet + i][X - offSet + i] == symbol;
		toleft &= field[Y - offSet + i][X + offSet - i] == symbol;
	}

	return (toright || toleft);
}

bool Board::checkDraw()
{
	bool check = true;

	for (short i = 0; i < size; ++i)
	{
		for (short j = 0; j < size; ++j)
		{
			check &= field[i][j] != EMPTY;
		}
	}

	return check;
}

Board::Board(short _size) : size(_size)
{
	if (_size < 3)
	{
		size = 3;
		mode = STANDART;
		offSet = 1;
	}
	else if (_size >= 5)
	{
		mode = ADVANCED;
		offSet = 2;
	}
	else
	{
		mode = STANDART;
		offSet = 1;
	}


	field = new CellType*[size];

	for (short i = 0; i < size; ++i)
	{
		field[i] = new CellType[size];

		for (short j = 0; j < size; ++j)
			field[i][j] = EMPTY;
	}
}

Board::~Board()
{
	for (short i = 0; i < size; ++i)
		delete[] field[i];
	delete[] field;
}

WinType Board::isWin()
{
	for (short i = offSet; i < size - offSet; ++i)
	{
		for (short j = offSet; j < size - offSet; ++j)
		{
			if (checkDiagonals(i, j, NOL) ||
				checkLanes(i, j, NOL))
				return O_WIN;
			
			if (checkDiagonals(i, j, KREST) ||
				checkLanes(i, j, KREST))
				return X_WIN;

			if (checkDraw())
				return DRAW;
		}
	}

	return NONE;
}


bool Board::makeMove(short Y, short X, CellType CurrCell)
{
	if (Y < 0 || Y >= size)
		return false;

	if (X < 0 || X >= size)
		return false;

	if (field[Y][X] != EMPTY)
		return false;

	field[Y][X] = CurrCell;
	return true;
}

CellType Board::getCell(short Y, short X) { return field[Y][X]; }

short Board::getSize() { return size; }