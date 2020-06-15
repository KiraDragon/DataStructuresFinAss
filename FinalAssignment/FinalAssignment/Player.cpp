#include "Player.h"



Player::Player(string name, int hp, int attPower, Type type) : Entity(name, hp, attPower, type) //uses the entity constructor as a base to construct player
{
	_moneh = 0;
	_status = Player::Status::HEALTHY;
}

void Player::Attack(Entity* e)
{
	int newHp;
	cout << "Player Attacks" << endl;
	newHp = e->getHp() - _attPower; //decreases the entity's hp by the player's attack
	e->setHp(newHp); //sets the new hp of the entity
}

void Player::Use(Item* item)
{
	if (item->getType() == Item::ATT) //if the target item is att type, add the players new att
	{
		int newAtt;
		newAtt = _attPower + item->getPotency();
		setAtt(newAtt);
	}

	if (item->getType() == Item::HP) //if the target item is hp type, it adds the player's hp
	{
		int newHp;
		newHp = _hp + item->getPotency();
		setHp(newHp);
	}
}

void Player::setMoneh(int moneh)
{
	_moneh = moneh; //sets the moneh of the player
}

void Player::setName(string name) //sets name of player
{
	_name = name; 
}

void Player::setStatus()
{
	if (_hp > 80) //sets the status of the player according to hp 
	{
		_status = Player::Status::HEALTHY;
	}
	else
	{
		if (_hp < 80 && _hp > 30)
		{
			_status = Player::Status::OK;
		}
		else
		{
			if (_hp < 30 && _hp > 0)
			{
				_status = Player::Status::NEARDEATH;
			}
			else
			{
				if (_hp <= 0)
				{
					_status = Player::Status::DEAD;
				}
			}
		}
	}
}

int Player::getMoneh()
{
	return _moneh; //returns the moneh
}

void Player::displayStatus() //displays the status of the player
{
	setStatus(); 
	ofstream file("status.txt", ofstream::trunc); 
	string status = "status"; 
	file << "++++++++++++++++++++++++++++++++++\n";
	file << "Name: " << _name << "\n\n";
	file << "HP: " << _hp << "\n\n";
	file << "Attack Power: " << _attPower << "\n\n";
	file << "Status: " << _status << "\n\n";
	file << "Moneh: " << _moneh << "\n\n";
	file << "++++++++++++++++++++++++++++++++++"; 
	file.close(); 
	status = "notepad \"" + status + "\"";
	system(status.c_str());
}

ostream& operator <<(ostream& aOStream, const Player::Status& Status) //overloaded operator that prints out the value instead of the number in the enumerator
{
	if (Status == 0)
	{
		aOStream << "HEALTHY";
	}
	else if (Status == 1)
	{
		aOStream << "OK";
	}
	else if (Status == 2)
	{
		aOStream << "NEAR DEATH";
	}
	else if (Status == 3)
	{
		aOStream << "DEAD";
	}

	return aOStream;
}

Player::Player()
{
}

Player::~Player()
{
}
