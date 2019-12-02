#ifndef VIEW_H
#define VIEW_H

#include "Module.h"

class BoardView
{
	private:
		Board *board;

	public:
		BoardView(Board*);
		void paintBoard();
		void paintCoords();
		void show();
		WinType startGame();
};

#endif // VIEW_H