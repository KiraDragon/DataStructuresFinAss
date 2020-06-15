#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Entity.h"
#include "Item.h"
using namespace std;

class Player : public Entity //child of entity
{
private:
	int _moneh; //the amount of currency the player has
	enum Status //the enumeration of the status of the player
	{
		HEALTHY, OK, NEARDEATH, DEAD
	};
	Status _status; //the current status of the player

public:
	Player(); //Player default constructor
	Player(string name, int hp, int attPower, Type type); //Player constructor
	void Attack(Entity* e) override; //overriden attack method for the player
	void Use(Item* item); //Use method for the player
	int getMoneh(); //gets the moneh
	void setStatus(); //set the status of the player
	void setName(string name); //sets the name of the player
	void setMoneh(int moneh); //set the moneh
	friend ostream& operator <<(ostream& aOStream, const Status&); //an overloaded operator that could write the actual value of the enumerations into the console
	void displayStatus(); //display's the player's stats
	~Player();
};