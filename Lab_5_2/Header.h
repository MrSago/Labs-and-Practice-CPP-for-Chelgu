#ifndef HEADER_H
#define HEADER_H

#define SNAKE_START_SIZE 3
#define SNAKE_STEP 1

struct COORD {
	short X;
	short Y;
};

enum SnakeLook {
	LOOK_UP = 1,
	LOOK_DOWN = 2,
	LOOK_LEFT = 3,
	LOOK_RIGHT = 4,
};

enum WorldObjs {

	/*Snake struct*/
	SNAKE_HEAD = 8,
	SNAKE_TAIL = 2,

	/*World structures*/
	WORLD_BARRIER = -1,
	WORLD_APPLE = 1,
	WORLD_SPACE = 0

};

enum WinType {
	GAME_CONTINUE = 0,
	GAME_OVER = 1
};

struct SnakeStruct {
	COORD CoordsHead;
	COORD *CoordsTail;
	COORD CoordsSave;
	size_t Lenght;
	SnakeLook Look;
};

#endif //HEADER_H