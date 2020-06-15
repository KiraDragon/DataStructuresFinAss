#include "GroupAssignment.h"


GroupAssignment::GroupAssignment(string name, int hp, int attPower, Type type) : Entity(name, hp, attPower, type)
{
}

void GroupAssignment::Attack(Entity* e)
{
	if (_hp > 0)
	{
		int newHp;
		newHp = e->getHp() - _attPower; //decreases the entity's hp by the bandit's attack
		e->setHp(newHp); //sets the new hp of the entity
		int threshold = _hp / 100 * 40;

		if (_hp <= threshold)
		{
			cout << _name << " is barely standing! It attacks!" << endl;
		}
		else
		{
			cout << _name << " is attacking you!" << endl;
		}
	}
	else
	{
	cout << "It has been conquered!" << endl;
	}
}

GroupAssignment::GroupAssignment()
{
}

GroupAssignment::~GroupAssignment()
{
}
