#include "Module.h"

Snake::Snake(COORD _size) : SnakeWorld(_size) { Struct = SnakeGen();  Apple = AppleGen(); };
Snake::Snake(short _X, short _Y) : SnakeWorld(_X, _Y) { Struct = SnakeGen(); Apple = AppleGen(); };
Snake::~Snake() { delete Struct.CoordsTail; }

COORD Snake::getApple() { return Apple; }
WorldObjs Snake::getObj(short _X, short _Y) { return buf[_Y][_X]; }

WinType Snake::SnakeMove()
{
	COORD tmp_coord, *tmp_tail;

	Struct.CoordsSave.X = Struct.CoordsHead.X;
	Struct.CoordsSave.Y = Struct.CoordsHead.Y;

	switch (Struct.Look)
	{
	case LOOK_UP:
		if (buf[Struct.CoordsHead.Y - SNAKE_STEP][Struct.CoordsHead.X] == WORLD_BARRIER ||
			buf[Struct.CoordsHead.Y - SNAKE_STEP][Struct.CoordsHead.X] == SNAKE_TAIL)
		{
			return GAME_OVER;
		}

		if (buf[Struct.CoordsHead.Y - SNAKE_STEP][Struct.CoordsHead.X] == WORLD_APPLE)
		{
			++Struct.Lenght;

			Apple = AppleGen();

			tmp_tail = new COORD[Struct.Lenght - 1];
			for (size_t i = 0; i < Struct.Lenght - 2; ++i)
				tmp_tail[i] = Struct.CoordsTail[i];
			delete Struct.CoordsTail;
			Struct.CoordsTail = tmp_tail;

			Struct.CoordsTail[Struct.Lenght - 2].X = Struct.CoordsTail[Struct.Lenght - 3].X;
			Struct.CoordsTail[Struct.Lenght - 2].Y = Struct.CoordsTail[Struct.Lenght - 3].Y;
		}

		Struct.CoordsHead.Y -= SNAKE_STEP;
		buf[Struct.CoordsHead.Y][Struct.CoordsHead.X] = SNAKE_HEAD;

		break;

	case LOOK_DOWN:
		if (buf[Struct.CoordsHead.Y + SNAKE_STEP][Struct.CoordsHead.X] == WORLD_BARRIER ||
			buf[Struct.CoordsHead.Y + SNAKE_STEP][Struct.CoordsHead.X] == SNAKE_TAIL)
		{
			return GAME_OVER;
		}

		if (buf[Struct.CoordsHead.Y + SNAKE_STEP][Struct.CoordsHead.X] == WORLD_APPLE)
		{
			++Struct.Lenght;

			Apple = AppleGen();

			tmp_tail = new COORD[Struct.Lenght - 1];
			for (size_t i = 0; i < Struct.Lenght - 2; ++i)
				tmp_tail[i] = Struct.CoordsTail[i];
			delete Struct.CoordsTail;
			Struct.CoordsTail = tmp_tail;

			Struct.CoordsTail[Struct.Lenght - 2].X = Struct.CoordsTail[Struct.Lenght - 3].X;
			Struct.CoordsTail[Struct.Lenght - 2].Y = Struct.CoordsTail[Struct.Lenght - 3].Y;
		}

		Struct.CoordsHead.Y += SNAKE_STEP;
		buf[Struct.CoordsHead.Y][Struct.CoordsHead.X] = SNAKE_HEAD;

		break;

	case LOOK_LEFT:
		if (buf[Struct.CoordsHead.Y][Struct.CoordsHead.X - SNAKE_STEP] == WORLD_BARRIER ||
			buf[Struct.CoordsHead.Y][Struct.CoordsHead.X - SNAKE_STEP] == SNAKE_TAIL)
		{
			return GAME_OVER;
		}

		if (buf[Struct.CoordsHead.Y][Struct.CoordsHead.X - SNAKE_STEP] == WORLD_APPLE)
		{
			++Struct.Lenght;

			Apple = AppleGen();


			tmp_tail = new COORD[Struct.Lenght - 1];
			for (size_t i = 0; i < Struct.Lenght - 2; ++i)
				tmp_tail[i] = Struct.CoordsTail[i];
			delete Struct.CoordsTail;
			Struct.CoordsTail = tmp_tail;

			Struct.CoordsTail[Struct.Lenght - 2].X = Struct.CoordsTail[Struct.Lenght - 3].X;
			Struct.CoordsTail[Struct.Lenght - 2].Y = Struct.CoordsTail[Struct.Lenght - 3].Y;
		}

		Struct.CoordsHead.X -= SNAKE_STEP;
		buf[Struct.CoordsHead.Y][Struct.CoordsHead.X] = SNAKE_HEAD;

		break;

	case LOOK_RIGHT:
		if (buf[Struct.CoordsHead.Y][Struct.CoordsHead.X + SNAKE_STEP] == WORLD_BARRIER ||
			buf[Struct.CoordsHead.Y][Struct.CoordsHead.X + SNAKE_STEP] == SNAKE_TAIL)
		{
			return GAME_OVER;
		}

		if (buf[Struct.CoordsHead.Y][Struct.CoordsHead.X + SNAKE_STEP] == WORLD_APPLE)
		{
			++Struct.Lenght;

			Apple = AppleGen();

			tmp_tail = new COORD[Struct.Lenght - 1];
			for (size_t i = 0; i < Struct.Lenght - 2; ++i)
				tmp_tail[i] = Struct.CoordsTail[i];
			delete Struct.CoordsTail;
			Struct.CoordsTail = tmp_tail;

			Struct.CoordsTail[Struct.Lenght - 2].X = Struct.CoordsTail[Struct.Lenght - 3].X;
			Struct.CoordsTail[Struct.Lenght - 2].Y = Struct.CoordsTail[Struct.Lenght - 3].Y;
		}

		Struct.CoordsHead.X += SNAKE_STEP;
		buf[Struct.CoordsHead.Y][Struct.CoordsHead.X] = SNAKE_HEAD;

		break;
	}

	for (size_t i = 0; i < Struct.Lenght - 2; ++i)
	{
		buf[Struct.CoordsSave.Y][Struct.CoordsSave.X] = SNAKE_TAIL;

		tmp_coord.X = Struct.CoordsSave.X;
		tmp_coord.Y = Struct.CoordsSave.Y;

		Struct.CoordsSave.X = Struct.CoordsTail[i].X;
		Struct.CoordsSave.Y = Struct.CoordsTail[i].Y;

		Struct.CoordsTail[i].X = tmp_coord.X;
		Struct.CoordsTail[i].Y = tmp_coord.Y;
	}

	buf[Struct.CoordsTail[Struct.Lenght - 2].Y][Struct.CoordsTail[Struct.Lenght - 2].X] = WORLD_SPACE;
	buf[Struct.CoordsSave.Y][Struct.CoordsSave.X] = SNAKE_TAIL;

	tmp_coord.X = Struct.CoordsSave.X;
	tmp_coord.Y = Struct.CoordsSave.Y;

	Struct.CoordsSave.X = Struct.CoordsTail[Struct.Lenght - 2].X;
	Struct.CoordsSave.Y = Struct.CoordsTail[Struct.Lenght - 2].Y;

	Struct.CoordsTail[Struct.Lenght - 2].X = tmp_coord.X;
	Struct.CoordsTail[Struct.Lenght - 2].Y = tmp_coord.Y;


	return GAME_CONTINUE;
}