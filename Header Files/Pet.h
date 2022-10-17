#pragma once
#ifndef PET_H
#define PET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

class Pet { //base class for all the pets
public:
	Pet(int Hunger = 0, int Sleepy = 0, int Bored = 0);
	virtual void Play(int fun = 5);
	virtual void Eat(int food = 5);
	virtual void Sleep(int bed);
	void Talk(string);
	void setHunger(int _hunger) { hunger = _hunger; }
	void setSleep(int _sleepy) { sleepy = _sleepy; }
	void setBored(int _bored) { bored = _bored; }
	void setName(string _petName) { petName = _petName; }
	void setpetType(string _petType) { petType = _petType; }
	int getHunger() { return hunger; }
	int getSleep() { return sleepy; }
	int getBored() { return bored; }
	string getName() { return petName; }
	string getpetType() { return petType; }
	void DisplayStats();
	//string LoadGame(string, string);
	void SaveGame(string, string, ofstream&);
private:
	string petName, petType;
protected:
	int hunger, sleepy, bored;
	int GetMood() const;
	void passTime(int time = 1);
};


#endif // !PET_H

