#include "FinalExam.h"



FinalExam::FinalExam(string name, int hp, int attPower, Type type) : Entity(name, hp, attPower, type)
{
}

void FinalExam::Attack(Entity* e)
{
	if(_hp > 0)
	{
		int newHp;
		newHp = e->getHp() - _attPower; //decreases the entity's hp by the bandit's attack
		e->setHp(newHp); //sets the new hp of the entity
		int threshold = _hp / 100 * 40;

		if (_hp <= threshold)
		{
			cout << _name << " is pounding you! But you're almost there!" << endl;
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

FinalExam::FinalExam()
{
}

FinalExam::~FinalExam()
{
}
