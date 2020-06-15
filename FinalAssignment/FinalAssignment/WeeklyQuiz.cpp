#include "WeeklyQuiz.h"


WeeklyQuiz::WeeklyQuiz(string name, int hp, int attPower, Type type) : Entity(name, hp, attPower, type)
{
}

WeeklyQuiz::WeeklyQuiz()
{
}

void WeeklyQuiz::Attack(Entity* e)
{
	if (_hp > 0)
	{
		int newHp;
		newHp = e->getHp() - _attPower; //decreases the entity's hp by the bandit's attack
		e->setHp(newHp); //sets the new hp of the entity
		int threshold = _hp / 100 * 40;

		if (_hp <= threshold)
		{
			cout << _name << " seems easy! It slowly fades away, though attacks you!" << endl;
		}
		else
		{
			cout << _name << ", a smallfry! It tackles you!" << endl;
		}
	}
	else
	{
		cout << "It has been conquered!" << endl;
	}
}

WeeklyQuiz::~WeeklyQuiz()
{
}
