#include "Pet.h"


Pet::Pet(int _hunger, int _sleepy, int _bored)
{
	hunger = _hunger;
	sleepy = _sleepy;
	bored = _bored;
}

void Pet::passTime(int time)
{
	hunger += time;
	bored += time;
	sleepy += time;
}

void Pet::Play(int fun)
{
	bored -= fun;
	hunger += fun;
	sleepy += fun;
	if (bored < 0) {
		bored = 0;
	}
	passTime();
}

void Pet::Eat(int food)
{
	hunger -= food;
	sleepy += food;
	bored += food;
	if (hunger < 0) {
		hunger = 0;
	}
	passTime();
}

void Pet::Sleep(int bed)
{
	sleepy -= bed;
	hunger += bed;
	bored += bed;
	if (sleepy < 0) {
		sleepy = 0;
	}
	passTime();
}

void Pet::Talk(string petName)
{
	if (hunger >= 15) {
		cout << petName << " is hungry. You should feed them." << endl;
	}
	if (sleepy >= 15) {
		cout << petName << " is sleepy. They should go to sleep." << endl;
	}
	if (bored >= 15) {
		cout << petName << " is bored. You should play with them." << endl;
	}

}

void Pet::DisplayStats()
{
	cout << endl << "Hunger level is: " << hunger << endl;
	cout << "Boredom level is: " << bored << endl;
	cout << "Sleepiness level is: " << sleepy << endl;
}

void Pet::SaveGame(string petType, string petName, ofstream& save)
{
	save << petName << " ";
	save << petType << " ";
	save << hunger << " ";
	save << bored << " ";
	save << sleepy;
	save << endl;
	save.close();
}

int Pet::GetMood() const
{
	return sleepy + hunger + bored;
}





