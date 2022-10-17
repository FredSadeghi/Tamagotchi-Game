#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"

using namespace std;

template <class T>
void menu(T myPet, string petName, string petType, ofstream& outputFile) { //menu to choose your options from
	int choice;
	do {
		cout << "==============================" << endl;
		cout << "1. Listen to pet" << endl;
		cout << "2. Play with pet" << endl;
		cout << "3. Feed your pet" << endl;
		cout << "4. Let pet sleep" << endl;
		cout << "5. Save Pet Stats" << endl;
		cout << "6. Exit Game" << endl;
		cout << "==============================" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			myPet.Talk(petName);
			break;
		case 2:
			myPet.Play();
			break;
		case 3:
			myPet.Eat(5, petName);
			break;
		case 4:
			myPet.Sleep(5, petName);
			break;
		case 5:
			myPet.SaveGame(petType, petName, outputFile);
			break;
		case 6:
			cout << "Exiting game";
			break;
		default:
			cout << "ERROR! Invalid selection. Please choose a number between 1 and 6.";
			break;
		}
		cout << endl;
	}
	while (choice != 6);
}

string LoadGame(string name, string petType)
{
	string temp, temp2, fullStats;
	ifstream load("stats.txt");
	while (getline(load, temp)) {
		fullStats = temp;
		istringstream stream(temp);
		stream >> temp;
		stream >> temp2;
		if (temp == name && temp2 == petType) {
			return fullStats;
		}
	}
}

int main() {
	cout << "Welcome to PetSim. Would you like to load a previous pet (load) or "
		"would you like to make a new pet (cat, dog, rabbit)" << endl;
	ifstream load("stats.txt");
	ofstream save("stats.txt", ios_base::app);
	string typePet;
	cin >> typePet;
	string name, temp, temp2;
	Pet myPet;
	if (typePet == "load") {
		while (getline(load, temp)) {
			istringstream stream(temp);
			stream >> temp;
			stream >> temp2;
			cout << temp << " " << temp2 << endl;
		}
		string chooseName, choosePet;
		cout << "Please choose a name from the list." << endl;
		cin >> chooseName;
		cout << "Please chose the pet type from the list." << endl;
		cin >> choosePet;
		Cat cats;
		Dog dogs;
		Rabbit rabbits;
		string fullStats = LoadGame(chooseName, choosePet);
		istringstream stream(fullStats);
		string loadName, loadType;
		int loadHunger, loadBored, loadSleepy;
		stream >> loadName >> loadType >> loadHunger >> loadBored >> loadSleepy;
		if (loadType == "cat") {
			cats.Draw();
			cats.setpetType("cat");
			cats.setHunger(loadHunger);
			cats.setBored(loadBored);
			cats.setSleep(loadSleepy);
			cout << "What would you like to do with " << loadName << "?" << endl;
			menu(cats, loadName, loadType, save);
		}
		else if (loadType == "dog") {
			dogs.Draw();
			dogs.setpetType("dog");
			dogs.setHunger(loadHunger);
			dogs.setBored(loadBored);
			dogs.setSleep(loadSleepy);
			cout << "What would you like to do with " << loadName << "?" << endl;
			menu(dogs, loadName, loadType, save);
		}
		else if (loadType == "rabbit") {
			rabbits.Draw();
			rabbits.setpetType("rabbit");
			rabbits.setHunger(loadHunger);
			rabbits.setBored(loadBored);
			rabbits.setSleep(loadSleepy);
			cout << "What would you like to do with " << name << "?" << endl;
			menu(rabbits, loadName, loadType, save);
		}
	}
	else if (typePet == "cat") {
		Cat myCat;
		myCat.Draw();
		myCat.setpetType("cat");
		cout << "What would you like to name your " << typePet << "?" << endl;
		cin >> name;
		cout << "What would you like to do with " << name << "?" << endl;
		menu(myCat, name, typePet, save);
	}
	else if (typePet == "dog") {
		Dog myDog;
		myDog.Draw();
		myDog.setpetType("dog");
		cout << "What would you like to name your " << typePet << "?" << endl;
		cin >> name;
		cout << "What would you like to do with " << name << "?" << endl;
		menu(myDog, name, typePet, save);
	}
	else if (typePet == "rabbit") {
		Rabbit myRabbit;
		myRabbit.Draw();
		myRabbit.setpetType("rabbit");
		cout << "What would you like to name your " << typePet << "?" << endl;
		cin >> name;
		cout << "What would you like to do with " << name << "?" << endl;
		menu(myRabbit, name, typePet, save);
	}

	
	

	return 0;
}