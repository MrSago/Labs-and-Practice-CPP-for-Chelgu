#include "View.h"
#include "draw.h"
#include <iostream>
#include <cstdlib>

#define FREE_SPACE "                                  "

BoardView::BoardView(Board* _board) : board(_board) { }

void BoardView::paintBoard()
{
	short size = board->getSize();

	for (short i = 0; i < size; ++i)
	{
		for (short j = 0; j < size; ++j)
		{
			gotoxy(((i + 1) * 2) + 1, (j + 1) * 2 - 1);
			putchar('+');

			gotoxy(((i + 1) * 2) + 2, (j + 1) * 2 - 1);
			putchar('-');

			gotoxy(((i + 1) * 2) + 3, (j + 1) * 2 - 1);
			putchar('+');

			gotoxy(((i + 1) * 2) + 3, (j + 1) * 2);
			putchar('|');

			gotoxy(((i + 1) * 2) + 1, (j + 1) * 2 + 1);
			putchar('+');

			gotoxy(((i + 1) * 2) + 2, (j + 1) * 2 + 1);
			putchar('-');

			gotoxy(((i + 1) * 2) + 3, (j + 1) * 2 + 1);
			putchar('+');

			gotoxy(((i + 1) * 2) + 1, (j + 1) * 2);
			putchar('|');
		}
	}
}

void BoardView::paintCoords()
{
	short size = board->getSize();

	gotoxy(2, size * 2 + 2);
	putchar('+');

	for (short i = 0; i < size * 2; ++i)
	{
		gotoxy(2, size * 2 + 1 - i);
		putchar('|');
		gotoxy(3 + i, size * 2 + 2);
		putchar('-');
	}

	gotoxy(2, 1);
	putchar('^');

	gotoxy(size * 2 + 3, size * 2 + 2);
	putchar('>');

	gotoxy(1, 1);
	putchar('y');
	
	gotoxy(size * 2 + 3, size * 2 + 3);
	putchar('x');
}

void BoardView::show()
{
	short size = board->getSize();

	for (short i = 0; i < size; ++i)
	{
		for (short j = 0; j < size; ++j)
		{
			gotoxy((i + 1) * 2 + 2, ((j + 1) * 2));
			switch (board->getCell(i, j))
			{
			case EMPTY:
				break;

			case NOL:
				putchar('O');
				break;

			case KREST:
				putchar('X');
				break;
			}
		}
	}
}

WinType BoardView::startGame()
{
	WinType result;
	short size = board->getSize();
	short x, y;

	clrscr();
	if (size < 5)
		setconsolesize((size + 7) * 2, (size + 2) * 2 + 1);
	else
		setconsolesize((size + 3) * 2, (size + 2) * 2 + 1);
	paintBoard();
	//paintCoords();

	while ((result = board->isWin()) == NONE)
	{
		do
		{ 
			show();
			gotoxy(3, size * 2 + 4);
			std::cout << FREE_SPACE;
			gotoxy(3, size * 2 + 4);
			std::cout << "Enter X: ";
			std::cin >> x >> y;
		} while (!board->makeMove(x - 1, size - y, KREST));


		if ((result = board->isWin()) == NONE)
		{
			do
			{
				show();
				gotoxy(3, size * 2 + 4);
				std::cout << FREE_SPACE;
				gotoxy(3, size * 2 + 4);
				std::cout << "Enter O: ";
				std::cin >> x >> y;
			} while (!board->makeMove(x - 1, size - y, NOL));
		}
		else break;
	}

	show();
	gotoxy(3, size * 2 + 5);

	return result;
}