#include "Dog.h"

Dog::Dog()
{
}

Dog::Dog(int _hunger, int _sleepy, int _bored) : Pet(_hunger, _sleepy, _bored)
{
}

void Dog::Play(int fun)
{
	bored -= fun;
	hunger += fun;
	sleepy += fun;
	if (bored < 0) {
		bored = 0;
	}
	if (bored > 7.5) {
		cout << "PLayed catch with your dog." << endl;
	}
	else if (bored < 7.5) {
		cout << "Took your dog for a nice walk" << endl;
	}
	DisplayStats();
}

void Dog::Eat(int food, string name)
{
	food = 5;
	setName(name);
	cout << "YUM! That steak really filled up " << name << "." << endl;
	hunger -= food;
	sleepy += food;
	bored += food;
	if (hunger < 0) {
		hunger = 0;
	}
	DisplayStats();
}

void Dog::Sleep(int bed, string name)
{
	bed = 5;
	setName(name);
	cout << "All that playing really got " << name << " tired." << endl;
	sleepy -= bed;
	hunger += bed;
	bored += bed;
	if (sleepy < 0) {
		sleepy = 0;
	}
	DisplayStats();
}

void Dog::Draw()
{
	cout << ",-.___,-." << endl;
	cout << "\\_/_ _\\_/" << endl;
	cout << "  )O_O(  " << endl;
	cout << " { (_) } " << endl;
	cout << " `- ^ -' " << endl;
}
