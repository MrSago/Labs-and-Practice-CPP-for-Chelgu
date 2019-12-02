#ifndef MODULE_H
#define MODULE_H

enum CellType {
	EMPTY = 0,
	NOL = 1,
	KREST = 2
};

enum WinType {
	NONE = 0,
	O_WIN = 1,
	X_WIN = 2,
	DRAW = 3
};

enum GameMode {
	STANDART = 3,
	ADVANCED = 5
};

class Board
{
	private:
		CellType **field;
		short size;
		GameMode mode;
		char offSet;

		bool checkLanes(short Y, short X, CellType symbol);
		bool checkDiagonals(short Y, short X, CellType symbol);
		bool checkDraw();

	public:
		Board(short _size = 3);
		~Board();
		void newGame();
		WinType isWin();
		bool makeMove(short Y, short X, CellType CurrCell);
		CellType getCell(short Y, short X);
		short getSize();
};

#endif //MODULE_H