#ifndef WORLD_H
#define WORLD_H

#include "Header.h"

class SnakeWorld {

	protected:
		WorldObjs **buf;
		COORD size;

		SnakeWorld(COORD _size);
		SnakeWorld(short _X, short _Y);
		~SnakeWorld();

		SnakeStruct SnakeGen();
		COORD AppleGen();

	private:
		void Gen();
		void SpaceGen();
		void MemAlloc();
		void BarrierGen();
		//void BarriersGen();

};

#endif //WORLD_H