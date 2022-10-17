#include "Cat.h"

Cat::Cat()
{
}

Cat::Cat(int _hunger, int _sleepy, int _bored) : Pet(_hunger, _sleepy, _bored)
{
	
}

void Cat::Play(int fun)
{
	bored -= fun;
	hunger += fun;
	sleepy += fun;
	if (bored < 0) {
		bored = 0;
	}
	if (bored > 7.5) {
		cout << "What is that red dot? I must chase it." << endl;
	}
	else if (bored < 7.5){
		cout << "Ball of yarn. My favorite toy." << endl;
	}
	DisplayStats();
}

void Cat::Eat(int food, string name)
{ 
	food = 5;
	setName(name);
	cout << "YUM! That cat food really hit the spot for " << name << "." << endl;
	hunger -= food;
	sleepy += food;
	bored += food;
	if (hunger < 0) {
		hunger = 0;
	}
	DisplayStats();
}

void Cat::Sleep(int bed, string name)
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

void Cat::Draw()
{
	cout << "  /\\_/\\  " << endl;
	cout << " ( o o ) " << endl;
	cout << "== _Y_ ==" << endl;
	cout << "   `-'   " << endl;
}

