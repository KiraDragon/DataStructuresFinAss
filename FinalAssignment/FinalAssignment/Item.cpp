#include "Item.h"



Item::Item(string name, Type type, int potency, string desc, int price)
{
	_name = name;
	_type = type;
	_potency = potency;
	_desc = desc;
	_price = price; 
}

Item::Type Item::getType()
{
	return _type; //returns the type
}

int Item::getPotency()
{
	return _potency; //returns the potency
}

int Item::getPrice()
{
	return _price; //returns the price
}


string Item::getName()
{
	return _name; //returns the name
}

string Item::getDesc()
{
	return _desc; //returns the description
}

Item::~Item()
{
}
