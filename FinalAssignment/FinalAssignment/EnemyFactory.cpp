#include "EnemyFactory.h"




EnemyFactory::EnemyFactory()
{
}

Entity* EnemyFactory::produceEnemy(int determiner)
{
	if (determiner == 1)
	{
		return new FinalExam("Finals", 50, 20, Entity::TEST); 
	}
	else if (determiner == 2)
	{
		return new GroupAssignment("Assignment with good groupmates", 50, 5, Entity::ASSIGNMENT);
	}
	else if (determiner == 3)
	{
		return new GroupAssignment("Assignment with invisible groupmates", 50, 15, Entity::ASSIGNMENT);
	}
	else if (determiner == 4)
	{
		return new OnlineQuiz("Pretty Easy Quiz", 15, 5, Entity::QUIZ);
	}
	else if (determiner == 5)
	{
		return new FinalExam("MobyPortFolio", 80, 10, Entity::ASSIGNMENT);
	}
	else if (determiner == 6)
	{
		return new WeeklyQuiz("Tests for one chapter", 10, 5, Entity::QUIZ); 
	}
}

EnemyFactory::~EnemyFactory()
{
}
