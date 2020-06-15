#pragma once
#include <iostream>
#include "Entity.h"

class OnlineQuiz : public Entity
{
public:
	OnlineQuiz(string name, int hp, int attPower, Type type);
	OnlineQuiz();
	void Attack(Entity* e) override;
	~OnlineQuiz();
};

