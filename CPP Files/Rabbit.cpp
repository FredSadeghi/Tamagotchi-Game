#include "Rabbit.h"

Rabbit::Rabbit()
{
}

Rabbit::Rabbit(int _hunger, int _sleepy, int _bored) : Pet(_hunger, _sleepy, _bored)
{
}

void Rabbit::Play(int fun)
{
	bored -= fun;
	hunger += fun;
	sleepy += fun;
	if (bored < 0) {
		bored = 0;
	}
	if (bored > 7.5) {
		cout << "Your rabbit loves going throught their tunnels." << endl;
	}
	else if (bored < 7.5) {
		cout << "PLayed a good game of tug of war with your rabbit." << endl;
	}
	DisplayStats();
}

void Rabbit::Eat(int food, string name)
{
	food = 5;
	setName(name);
	cout << "YUM! " << name << " nibbled on their carrot and some other vegtables." << endl;
	hunger -= food;
	sleepy += food;
	bored += food;
	if (hunger < 0) {
		hunger = 0;
	}
	DisplayStats();
}

void Rabbit::Sleep(int bed, string name)
{
	bed = 5;
	setName(name);
	cout << "All that playing really got " << name << " tired." << endl;;
	sleepy -= bed;
	hunger += bed;
	bored += bed;
	if (sleepy < 0) {
		sleepy = 0;
	}
	DisplayStats();
}

void Rabbit::Draw()
{
	cout << "         ((`\\ " << endl;
	cout << "      ___ \\\\ '--._ " << endl;
	cout << "   .'`   `'    o  ) " << endl;
	cout << "  /    \\   '. __.'" << endl;
	cout << " _|    /_  \\ \\_\\_ " << endl;
	cout << "{_\\______\\-'\\__\\_\\ " << endl;
}
