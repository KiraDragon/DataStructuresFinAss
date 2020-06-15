#include "Entity.h"

Entity::Entity(string name, int hp, int attPower, Type type)
{
	_name = name; 
	_hp = hp;
	_attPower = attPower;
	_type = type;
}

Entity::Entity()
{

}

int Entity::getHp()
{
	return _hp; //returns the hp
}

int Entity::getAtt()
{
	return _attPower; //returns the attack
}

void Entity::setAtt(int att)
{
	_attPower = att; //sets the attack
}

void Entity::setHp(int hp)
{
	_hp = hp; //sets the hp
}

ostream& operator <<(ostream& aOStream, Entity& aEntity)
{
	aOStream << aEntity._name;
	return aOStream;
}

Entity::~Entity()
{
}
