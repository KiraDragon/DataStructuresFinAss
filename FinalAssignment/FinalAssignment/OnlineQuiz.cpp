#include "OnlineQuiz.h"


OnlineQuiz::OnlineQuiz(string name, int hp, int attPower, Type type) : Entity(name, hp, attPower, type)
{
}

OnlineQuiz::OnlineQuiz()
{
}

void OnlineQuiz::Attack(Entity* e)
{
	if (_hp > 0)
	{
		int newHp;
		newHp = e->getHp() - _attPower; //decreases the entity's hp by the bandit's attack
		e->setHp(newHp); //sets the new hp of the entity
		int threshold = _hp / 100 * 40;

		if (_hp <= threshold)
		{
			cout << _name << " is almost over! It still strikes weakly!" << endl;
		}
		else
		{
			cout << _name << " attacks you!" << endl;
		}
	}
	else
	{
		cout << "It has been conquered!" << endl; 
	}
}

OnlineQuiz::~OnlineQuiz()
{
}
