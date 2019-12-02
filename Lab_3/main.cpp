#include "View.h"
#include <iostream>

int main()
{
	short size;
	std::cout << "Enter size: ";
	std::cin >> size;

	Board board(size);
	BoardView view(&board);
	WinType result = view.startGame();

	switch (result)
	{
	case O_WIN:
		std::cout << "Player O winner!";
		break;

	case X_WIN:
		std::cout << "Player X winner!";
		break;

	case DRAW:
		std::cout << "Draw!";
		break;
	}

	getchar();
	getchar();
	return 0;
}