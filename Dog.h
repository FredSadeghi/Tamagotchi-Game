#pragma once
#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet {
public:
	Dog();
	Dog(int, int, int);
	void Play(int fun = 5);
	void Eat(int food, string);
	void Sleep(int bed, string);
	void Draw();
};
#endif // !DOG_H