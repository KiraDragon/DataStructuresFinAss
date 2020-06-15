#pragma once
#include <iostream>
#include <string>

using namespace std;
class Entity //The parent class for all units (including the player and enemies)
{
public:
	enum Type //The enumeration for the entity type
	{
		PLAYER, QUIZ, ASSIGNMENT, TEST, PORTFOLIO 
	};

protected:
	string _name; //name of the entity
	int _hp; //HP for the entities (health points)
	int _attPower; //Attack power for the entities 
	Type _type; //The enumeration of entity type

public:
	Entity(); //Default constructor
	Entity(string name, int hp, int attPower, Type type); //Constructor for entities
	virtual void Attack(Entity* e) = 0; //virtual attack method
	int getHp(); //gets the health of the entity
	int getAtt(); //gets the attack of the entity
	void setHp(int hp); //sets the hp of the entity
	void setAtt(int att); //sets the attack of the entity
	friend ostream& operator <<(ostream& aOStream, Entity& aEntity); //an overloaded output operator for the player
	~Entity(); //destructor for the entity
};

