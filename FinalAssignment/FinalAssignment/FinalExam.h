#pragma once
#include <iostream>
#include "Entity.h"

class FinalExam : public Entity
{
public:
	FinalExam(string name, int hp, int attPower, Type type); 
	FinalExam();
	void Attack(Entity* e) override; 
	~FinalExam();
};

