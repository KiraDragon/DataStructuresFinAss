#pragma once
#include <iostream>
#include "Entity.h"

class WeeklyQuiz : public Entity
{
public:
	WeeklyQuiz(string name, int hp, int attPower, Type type);
	WeeklyQuiz();
	void Attack(Entity* e) override;
	~WeeklyQuiz();
};

