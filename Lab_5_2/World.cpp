#include "World.h"
#include <cstdlib>
#include <ctime>


SnakeWorld::SnakeWorld(COORD _size) : size(_size) { Gen(); }
SnakeWorld::SnakeWorld(short _X, short _Y) { size.X = _X; size.Y = _Y;  Gen(); }
SnakeWorld::~SnakeWorld()
{
	for (short i = 0; i < size.Y; ++i)
			delete[] buf[i];
	delete[] buf;
}




void SnakeWorld::Gen()
{
	MemAlloc();		//Memory allocate for the World
	BarrierGen();	//Gen World's Barrier
	SpaceGen();		//Gen Free space
	//BarriersGen();		//Gen Barriers
	//SnakeGen();			//Gen Snake in the World
	//WorldGraphics();		//World Graphics
	//AppleGen();				//Gen Apple in the World
}


void SnakeWorld::MemAlloc()
{
	buf = new WorldObjs*[size.Y];

	for (short i = 0; i < size.Y; ++i)
	{
		buf[i] = new WorldObjs[size.X];
	}
}

void SnakeWorld::BarrierGen()
{
	/*Y - coords*/
	for (short i = 0; i < size.Y; ++i)
	{
		buf[i][0] = WORLD_BARRIER;
		buf[size.Y - 1 - i][size.X - 1] = WORLD_BARRIER;
	}

	/*X - coords*/
	for (short i = 0; i < size.X; ++i)
	{
		buf[0][i] = WORLD_BARRIER;
		buf[size.Y - 1][size.X - 1 - i] = WORLD_BARRIER;
	}
}

void SnakeWorld::SpaceGen()
{
	for (short i = 1; i < size.Y - 1; ++i)
	{
		for (short j = 1; j < size.X - 1; ++j)
		{
			buf[i][j] = WORLD_SPACE;
		}
	}
}

SnakeStruct SnakeWorld::SnakeGen()
{
	SnakeStruct Snake;
	COORD tmp;
	bool check = false;

	if (!buf)
		exit(EXIT_FAILURE);

	srand((unsigned)time(NULL));
	Snake.Lenght = SNAKE_START_SIZE;
	Snake.CoordsTail = new COORD[SNAKE_START_SIZE - 1];

	do
	{
		Snake.CoordsHead.X = 1 + (rand() % (size.X - 2));
		Snake.CoordsHead.Y = 1 + (rand() % (size.Y - 2));
	} while (buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] != WORLD_SPACE);

	buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

	tmp.X = Snake.CoordsHead.X;
	tmp.Y = Snake.CoordsHead.Y;

	for (short i = 1; i < SNAKE_START_SIZE; ++i)
	{
		switch (rand() % 4)
		{
		case 0:
			if (buf[tmp.Y - 1][tmp.X] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X;
				Snake.CoordsTail[i - 1].Y = tmp.Y - 1;
				buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (!check)
				{
					Snake.Look = LOOK_DOWN;
					check = true;
				}

				break;
			}

		case 1:
			if (buf[tmp.Y + 1][tmp.X] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X;
				Snake.CoordsTail[i - 1].Y = tmp.Y + 1;
				buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (!check)
				{
					Snake.Look = LOOK_UP;
					check = true;
				}

				break;
			}

		case 2:
			if (buf[tmp.Y][tmp.X - 1] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X - 1;
				Snake.CoordsTail[i - 1].Y = tmp.Y;
				buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (!check)
				{
					Snake.Look = LOOK_RIGHT;
					check = true;
				}

				break;
			}

		case 3:
			if (buf[tmp.Y][tmp.X + 1] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X + 1;
				Snake.CoordsTail[i - 1].Y = tmp.Y;
				buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (!check)
				{
					Snake.Look = LOOK_LEFT;
					check = true;
				}

				break;
			}

		default:
			--i;
			break;
		}
	}

	return Snake;
}

COORD SnakeWorld::AppleGen()
{
	COORD Apple;

	while (1)
	{
		Apple.X = 1 + (rand() % (size.X - 2));
		Apple.Y = 1 + (rand() % (size.Y - 2));

		if (buf[Apple.Y][Apple.X] == WORLD_SPACE)
		{
			buf[Apple.Y][Apple.X] = WORLD_APPLE;
			break;
		}
	}

	return Apple;
}