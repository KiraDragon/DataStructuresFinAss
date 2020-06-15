#pragma once
#include <iostream>
#include <string>
#include "Entity.h"
#include "FinalExam.h"
#include "GroupAssignment.h"
#include "OnlineQuiz.h"
#include "WeeklyQuiz.h"

class EnemyFactory
{
public:
	EnemyFactory(); //constructor 
	Entity* produceEnemy(int determiner); //factory method 
	~EnemyFactory();
};

