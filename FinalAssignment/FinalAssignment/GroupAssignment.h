#pragma once
#include <iostream>
#include "Entity.h"

class GroupAssignment : public Entity
{
public:
	GroupAssignment(string name, int hp, int attPower, Type type);
	GroupAssignment();
	void Attack(Entity* e) override;
	~GroupAssignment();
};

