#pragma once
#ifndef CAT_H
#define CAT_H

#include "Pet.h"

class Cat : public Pet {
public:
	Cat();
	Cat(int, int, int);
	void Play(int fun = 5);
	void Eat(int food, string);
	void Sleep(int bed, string);
	void Draw();
};
#endif // !CAT_H
