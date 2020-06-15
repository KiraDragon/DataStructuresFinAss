#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	enum Type //Enumeration type for the items
	{
		HP, ATT
	};

	Item(string name, Type type, int potency, string desc, int price); //The constructor for item
	~Item();
	string getName(); //gets the name of the item
	Type getType(); //gets the type of the item
	int getPotency(); //gets the potency of the item
	string getDesc(); //gets the description of the item
	int getPrice(); //gets the price 

private:
	int _potency; //the potency of the item
	int _price; //the price of the item
	string _name; //the name of the item
	string _desc; //the description of the item
	Type _type; //the type of the item
};

