#ifndef MODULE_H
#define MODULE_H

#include "Header.h"
#include "World.h"

class Snake : private SnakeWorld {

	public:
		SnakeStruct Struct;
		COORD Apple;

	public:
		Snake(COORD _size);
		Snake(short _X, short _Y);
		~Snake();
		WinType SnakeMove();
		COORD getApple();
		WorldObjs getObj(short _X, short _Y);
};

#endif //MODULE_H