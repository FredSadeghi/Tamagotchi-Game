#pragma once
#ifndef RABBIT_H
#define RABBIT_H

#include "Pet.h"

class Rabbit : public Pet {
public:
	Rabbit();
	Rabbit(int, int, int);
	void Play(int fun = 5);
	void Eat(int food, string);
	void Sleep(int bed, string);
	void Draw();
};
#endif // !RABBIT_H
