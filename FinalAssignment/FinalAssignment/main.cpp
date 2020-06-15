
#include <string>
#include <iostream>
#include "BTree.h"
#include "DListNode.h"
#include "SListNode.h"
#include "SIterator.h"
#include "TreeVisitor.h"
#include "Stack.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include "Queue.h"
#include "EnemyFactory.h"

using namespace std; 

/* Test Methods
void testStatus()
{
	Player testBoy = Player("Name", 10, 10, Entity::PLAYER, 10);
	testBoy.displayStatus(); 
	testBoy.setHp(5); 
	testBoy.displayStatus();
}


void testQueue()
{
	Queue<int> lQueue = Queue<int>(3); 
	lQueue.enqueue(1);
	lQueue.enqueue(2);
	lQueue.enqueue(3);

	cout << "No of elements: " << lQueue.size() << endl << endl;

	cout << "value: " << lQueue.dequeue() << endl;
	cout << "value: " << lQueue.dequeue() << endl;
	cout << "value: " << lQueue.dequeue() << endl << endl;

	cout << "No of elements: " << lQueue.size() << endl; 
}


void mapTraversal()
{
	string s("map1");
	string ss("map2");
	string ss2("map3");
	string sss("map4");
	string sss2("map5");
	string ss2s("map6");
	string ss2s2("map7");
	BTree<string> mapNode1(s, "The first Map");
	BTree<string> mapNode2(ss, "The second map");
	BTree<string> mapNode3(ss2, "The third map");
	BTree<string> mapNode4(sss, "The fourth map");
	BTree<string> mapNode5(sss2, "The fifth map");
	BTree<string> mapNode6(ss2s, "The sixth map");
	BTree<string> mapNode7(ss2s2, "The seventh map");
	BTree<string>* playerPos = &mapNode1; 

	mapNode1.attachLeft(&mapNode2);
	mapNode1.attachRight(&mapNode3);
	mapNode1.left().attachLeft(&mapNode4); 
	mapNode1.left().attachRight(&mapNode5); 
	mapNode1.right().attachLeft(&mapNode6);
	mapNode1.right().attachRight(&mapNode7); 

	while (true)
	{
		string response; 
		if (playerPos != &BTree<string>::NIL)
		{

			cout << "\nLocation: " << playerPos->key() << endl;
			cout << playerPos->content() << endl; 
			cout << "Go Left or Right: " << endl;
			cin >> response;

			if (response == "left")
			{
				playerPos = &playerPos->left();
			}
			else if (response == "right")
			{
				playerPos = &playerPos->right();
			}
			else if (response == "map")
			{
				mapNode1.traverseDepthFirst(PreOrderVisitor<string>());
			}
			else if (response == "q")
			{
				break;
			}
		}
		else
		{
			cout << "Invalid" << endl; 
			playerPos = &mapNode1; 
		}
	}
}


void testFight()
{
	Player p1 = Player("P1", 100, 100, Entity::PLAYER, 100);
	Queue<Entity*> EnemyQueue = Queue<Entity*>(3); 
	EnemyFactory eF = EnemyFactory(); 
	EnemyQueue.enqueue(eF.produceEnemy(1));
	EnemyQueue.enqueue(eF.produceEnemy(2));
	EnemyQueue.enqueue(eF.produceEnemy(4));
	Entity* currentEnemy = EnemyQueue.dequeue();
	while (true)
	{
		string response;
		if (currentEnemy->getHp() > 0)
		{
			cout << "Attack test" << endl; 
			cin >> response; 
			if (response == "attack")
			{
				p1.Attack(currentEnemy); 
				currentEnemy->Attack(&p1); 
			}
		}
		else
		{
			if (!EnemyQueue.isEmpty())
			{
				currentEnemy = EnemyQueue.dequeue();
			}
			else
			{
				cout << "Finished" << endl; 
				break; 
			}
		}
	}
}


void testInventoryandBuy()
{
	typedef DListNode<Item*> ItemFrame;
	typedef Stack<ItemFrame> Inventory;
	Item hpItem1("Coffee", Item::HP, 20, "Trust me, you'll need this. +20HP");
	Item attItem1("Extra Study", Item::ATT, 5, "Not very effective, but helps. +5ATT");
	Item hpItem2("A good night's sleep", Item::HP, 40, "It's super rare and super effective! +40HP");
	Item attItem2("Extra Hardwork", Item::ATT, 10, "Hey, its something. +10ATT");
	ItemFrame hpFrame1(&hpItem1);
	ItemFrame hpFrame2(&hpItem2);
	ItemFrame attFrame1(&attItem1);
	ItemFrame attFrame2(&attItem2);
	Inventory playerInventory(3);

	string response; 
	cout << "Buy Test and Inventory Test: " << endl; 
	hpFrame1.append(attFrame2);
	hpFrame1.append(attFrame1);
	hpFrame1.append(hpFrame2);
	ItemFrame* currentItem = &hpFrame1;
	while (true)
	{
		cout << "Cycling test" << endl;
		cout << currentItem->getValue()->getName() << endl;
		cout << currentItem->getValue()->getDesc() << endl << endl;
		cin >> response;
		if (response == "next")
		{
			if (currentItem->getNext() == &ItemFrame::NIL)
			{
				cout << "Null" << endl << endl;
			}
			else
			{
				currentItem = currentItem->getNext();
			}
		}
		else if (response == "previous")
		{
			if (currentItem->getPrevious() == &ItemFrame::NIL)
			{
				cout << "Null" << endl << endl;
			}
			else
			{
				currentItem = currentItem->getPrevious();
			}
		}
		else if (response == "buy")
		{
			if (!playerInventory.isEmpty())
			{
				if (playerInventory.getSize() < 3)
				{
					ItemFrame* currentNode = &playerInventory.top();
					playerInventory.push(*currentItem);
					currentNode->prepend(playerInventory.top());
				}
				else
				{
					playerInventory.top().remove();
					playerInventory.pop();
					playerInventory.push(*currentItem);
					playerInventory.top().append(playerInventory.getElement(1));
				}
			}
			else
			{
				playerInventory.push(*currentItem);
			}
		}
		else if (response == "inventory")
		{
			cout << "========INVENTORY=========" << endl;
			for (int i = 0; i < playerInventory.getSize(); i++)
			{
				if (playerInventory.getElement(i).getValue() == NULL)
				{
					i++;
				}
				else
				{
					cout << i << ") " << playerInventory.getElement(i).getValue()->getName() << endl;
				}
			}
			cout << "==========================" << endl;
		}
		else if (response == "exit")
		{
			break; 
		}
		else
		{
			cout << "Invalid" << endl; 
		}
	}
}
*/

char toLower(char c) //changes the string to the lower case
{
	if (c >= 'A' && c <= 'Z')
	{
		return c + 32;
	}
	return c;
}

void displayHelp(string key)
{
	if (key == "Start Zone" || key == "Dungeon District" || key == "Market District")
	{
		cout << "         Commands          " << endl; 
		cout << "===========================" << endl;
		cout << "left: Go to the left side" << endl;
		cout << "right: Go to the right side" << endl;
		cout << "enter: Enter an area" << endl; 
		cout << "inventory: Goes into inventory mode" << endl;
		cout << "return: Goes back to the first map" << endl; 
		cout << "map: Shows all the locations available" << endl; 
		cout << "status: Checks the player's status" << endl;
		cout << "quit: Quits the game" << endl; 
		cout << "===========================" << endl;
	}
	else if (key == "Exam Hall")
	{
		cout << "         Commands          " << endl;
		cout << "===========================" << endl;
		cout << "enter: Enter an area" << endl;
		cout << "attack: Attacks the enemy" << endl;
		cout << "go: Enters the next segment" << endl; 
		cout << "status: Checks the player's status" << endl;
		cout << "===========================" << endl;
	}
	else if (key == "Practice Zone")
	{
		cout << "         Commands          " << endl;
		cout << "===========================" << endl;
		cout << "enter: Enter an area" << endl;
		cout << "attack: Attacks the enemy" << endl; 
		cout << "status: Checks the player's status" << endl;
		cout << "===========================" << endl;
	}
	else if (key == "Shops")
	{
		cout << "         Commands          " << endl;
		cout << "===========================" << endl;
		cout << "enter: Enter an area" << endl;
		cout << "next: Cycles to the next item" << endl;
		cout << "previous: Cycles to the previous item" << endl; 
		cout << "buy: Attempts to buy the current item" << endl; 
		cout << "inventory: Checks the entirety of the player's inventory" << endl;
		cout << "exit: Exits the shop" << endl; 
		cout << "===========================" << endl;
	}
	else
	{
		cout << "         Commands          " << endl;
		cout << "===========================" << endl; 
		cout << "enter: Enter an area" << endl;
		cout << "===========================" << endl;
	}
}

int main()
{
	typedef DListNode<Item*> ItemFrame;
	typedef SListNode<Entity*> DungeonTile;
	typedef Stack<ItemFrame> Inventory;
	//Overworld Map
	string s("Start Zone");
	string ss("Dungeon District");
	string ss2("Market District");
	string sss("Exam Hall");
	string sss2("Practice Zone");
	string ss2s("Shops");
	string ss2s2("Shady Alley");
	BTree<string> startNode(s, "You spawn in a large flat lobby, with two paths, a sign pointing to the Dungeon District to the left and the Market District to the right");
	BTree<string> startLeft(ss, "You arrive in the Dungeon District, you see an entrance to the dungeon on the left and an arena to the right");
	BTree<string> startRight(ss2, "You arrive in the Market district, with a large amount of shops selling, mostly on the left. Though there is a shady alley on the right");
	BTree<string> LeftLeft(sss, "The dungeon sign says: Assessment Cycle, enter at your own risk");
	BTree<string> LeftRight(sss2, "It says this is the arena. Practice Zone!");
	BTree<string> RightLeft(ss2s, "You come across a shop selling multiple kinds of supplies.");
	BTree<string> RightRight(ss2s2, "A shady alley! You wonder what's in there");

	BTree<string>* playerPos = &startNode;

	startNode.attachLeft(&startLeft);
	startNode.attachRight(&startRight);
	startNode.left().attachLeft(&LeftLeft);
	startNode.left().attachRight(&LeftRight);
	startNode.right().attachLeft(&RightLeft);
	startNode.right().attachRight(&RightRight);

	//Items available in game
	Item hpItem1("Coffee", Item::HP, 20, "Trust me, you'll need this. +20HP", 40);
	Item attItem1("Extra Study", Item::ATT, 5, "Not very effective, but helps. +5ATT", 30);
	Item hpItem2("A good night's sleep", Item::HP, 40, "It's super rare and super effective! +40HP", 60);
	Item attItem2("Extra Hardwork", Item::ATT, 10, "Hey, its something. +10ATT", 50);
	ItemFrame hpFrame1(&hpItem1);
	ItemFrame hpFrame2(&hpItem2);
	ItemFrame attFrame1(&attItem1);
	ItemFrame attFrame2(&attItem2);
	hpFrame1.append(attFrame2);
	hpFrame1.append(attFrame1);
	hpFrame1.append(hpFrame2);
	ItemFrame* currentShopItem = &hpFrame1;

	//Inventory
	Inventory playerInventory(3);

	//The arena bad guys 
	EnemyFactory eF = EnemyFactory();
	Queue<Entity*> EnemyQueue = Queue<Entity*>(3);

	//Dungeon bad guys
	Entity* e1 = eF.produceEnemy(2); 
	Entity* e2 = eF.produceEnemy(3);
	Entity* e3 = eF.produceEnemy(1);
	Entity* e4 = eF.produceEnemy(5);

	DungeonTile d4("Last thing to submit. The mother of all portfolios.", e4);
	DungeonTile d3("Final approaches, literally!", e3, &d4);
	DungeonTile d2("The second assessment appears! Another group assignment! But this time, seems like you're alone", e2, &d3);
	DungeonTile d1("You come face to face with the first enemy! The Group Assignment!", e1, &d2);
	
	SIterator<Entity*> dungeonIter(&d1); 

	bool mainLoop = true;


	Player p1 = Player("", 100, 10, Entity::PLAYER);
	string name;
	cout << "-You are transported into the magical realm of SwinnnnBurnnnn. The only way to escape now is to finish the dungeon!" << endl;
	cout << "-To do this, earn money by fighting in the arena" << endl;
	cout << "-The money is then used to purchase things from the shop to get stronger" << endl;
	cout << "-You cannot use your inventory during the dungeon (No studying during assessments!) so better be ready before entering!" << endl << endl;
	cout << "Enter your name: " << endl;
	cin >> name;
	p1.setName(name);

	while (mainLoop)
	{
		if (playerPos != &BTree<string>::NIL)
		{

			cout << "\nLocation: " << playerPos->key() << endl;
			cout << playerPos->content() << endl;
			cout << "Type \"help\" for some help" << endl; 
			cout << "Command: " << endl;
			string response;
			cin >> response;

			for (char &c : response)
			{
				c = toLower(c); //changes the response to lower case
			}

			if (response == "left")
			{
				playerPos = &playerPos->left();
			}
			else if (response == "right")
			{
				playerPos = &playerPos->right();
			}
			else if (response == "enter")
			{
				if (playerPos->key() == sss)
				{
					while (true)
					{
						cout << "You enter the assessment cycle. Going through the journey to finish this hell." << endl;
						while (true)
						{
							if (dungeonIter == dungeonIter.end())
							{
								cout << "You finished the assessment cycle and earned yourself some freedom! Nah kidding. Good luck with other things to worry about now" << endl;
								mainLoop = false;
								break;
							}
							else if (p1.getHp() <= 0)
							{
								cout << "You died of stress." << endl;
								mainLoop = false;
								break;
							}
							Entity* dungeonEnemy = *dungeonIter;
							if (dungeonEnemy->getHp() > 0)
							{
								cout << dungeonIter.getNode()->getEvent() << endl;
							}
							else
							{
								cout << "You may proceed to the next segment" << endl; 
							}
							string dungeonResponse; 
							cin >> dungeonResponse; 
							for (char &c : dungeonResponse)
							{
								c = toLower(c); //changes the response to lower case
							}
							if (dungeonResponse == "attack")
							{
								p1.Attack(dungeonEnemy);
								dungeonEnemy->Attack(&p1); 
							}
							else if (dungeonResponse == "go")
							{
								if (dungeonEnemy->getHp() <= 0)
								{
									dungeonIter++; 
								}
								else
								{
									cout << "An enemy still stands in your path!" << endl; 
								}
							}
							else if (dungeonResponse == "enter")
							{
								cout << "You are already in dungeon" << endl;
							}
							else if (dungeonResponse == "help")
							{
								displayHelp(playerPos->key());
							}
							else if (dungeonResponse == "status")
							{
								p1.displayStatus();
							}
							else
							{
								cout << "Invalid Command" << endl;
							}
						}
						break;
					}
				}
				else if (playerPos->key() == sss2)
				{
					while (true)
					{
						cout << "As you enter the practice zone, enemies come to meet your wits!" << endl;
						EnemyQueue.enqueue(eF.produceEnemy(4));
						EnemyQueue.enqueue(eF.produceEnemy(4));
						EnemyQueue.enqueue(eF.produceEnemy(6));
						Entity* currentEnemy = EnemyQueue.dequeue();
						while (true)
						{
							string arenaResponse;
							if (currentEnemy->getHp() > 0)
							{
								cin >> arenaResponse;

								for (char &c : arenaResponse)
								{
									c = toLower(c); //changes the response to lower case
								}

								if (arenaResponse == "attack")
								{
									p1.Attack(currentEnemy);
									currentEnemy->Attack(&p1);
								}
								else if (arenaResponse == "help")
								{
									displayHelp(playerPos->key());
								}
								else if (arenaResponse == "status")
								{
									p1.displayStatus();
								}
								else if (arenaResponse == "enter")
								{
									cout << "You are already in arena" << endl;
								}
								else
								{
									cout << "Invalid Command" << endl;
								}
							}
							else if (p1.getHp() <= 0)
							{
								cout << "You died of stress." << endl; 
								mainLoop = false; 
								break; 
							}
							else
							{
								if (!EnemyQueue.isEmpty())
								{
									currentEnemy = EnemyQueue.dequeue();
								}
								else
								{
									cout << "The last practice question is defeated! You walk away triumphant!" << endl;
									cout << "Rewarded With: 50 moneh" << endl;
									p1.setMoneh(p1.getMoneh() + 50);
									break;
								}
							}
						}
						break;
					}
				}
				else if (playerPos->key() == ss2s)
				{
					while (true)
					{
						cout << "Many shops are selling many things. But only one sells the required items for this quest." << endl;
						while (true)
						{
							cout << currentShopItem->getValue()->getName() << endl;
							cout << currentShopItem->getValue()->getDesc() << endl;
							cout << "Price: " << currentShopItem->getValue()->getPrice() << endl << endl;
							string shopResponse;
							cin >> shopResponse;

							for (char &c : shopResponse)
							{
								c = toLower(c); //changes the response to lower case
							}

							if (shopResponse == "next")
							{
								if (currentShopItem->getNext() == &ItemFrame::NIL)
								{
									cout << "Nothing beyond this item" << endl << endl;
								}
								else
								{
									currentShopItem = currentShopItem->getNext();
								}
							}
							else if (shopResponse == "previous")
							{
								if (currentShopItem->getPrevious() == &ItemFrame::NIL)
								{
									cout << "Nothing before this item" << endl << endl;
								}
								else
								{
									currentShopItem = currentShopItem->getPrevious();
								}
							}
							else if (shopResponse == "buy")
							{
								if (p1.getMoneh() >= currentShopItem->getValue()->getPrice())
								{

									if (!playerInventory.isEmpty())
									{
										if (playerInventory.getSize() < 3)
										{
											ItemFrame* currentNode = &playerInventory.top();
											ItemFrame temp = *currentShopItem;
											temp.detatch();
											playerInventory.push(temp);
											currentNode->prepend(playerInventory.top());
										}
										else
										{
											cout << "Inventory full, removing oldest item: " << playerInventory.top().getValue()->getName() << endl; 
											playerInventory.top().detatch();
											playerInventory.pop();
											ItemFrame temp = *currentShopItem;
											temp.detatch(); 
											playerInventory.push(temp);
											playerInventory.top().append(playerInventory.getElement(1));
										}
									}
									else
									{
										ItemFrame temp = *currentShopItem;
										temp.detatch();
										playerInventory.push(temp);
									}
									p1.setMoneh(p1.getMoneh() - currentShopItem->getValue()->getPrice());
								}
								else
								{
									cout << "Not enough Moneh" << endl;
								}
							}
							else if (shopResponse == "help")
							{
								displayHelp(playerPos->key());
							}
							else if (shopResponse == "enter")
							{
								cout << "You are already in shop" << endl; 
							}
							else if (shopResponse == "inventory")
							{
								cout << "========INVENTORY=========" << endl;
								for (int i = 0; i < playerInventory.getSize(); i++)
								{
									if (playerInventory.getElement(i).getValue() == NULL)
									{
										i++;
									}
									else
									{
										cout << i << ") " << playerInventory.getElement(i).getValue()->getName() << endl;
									}
								}
								cout << "==========================" << endl;
								cout << "Moneh: " << p1.getMoneh() << endl; 
							}
							else if (shopResponse == "exit")
							{
								break;
							}
							else
							{
								cout << "Invalid" << endl;
							}
						}
						break;
					}
				}
				else if (playerPos->key() == ss2s2)
				{
					while (true)
					{
						cout << "Upon entering the alley, a shady looking man offers you...cheats! For just a measly 50 moneh! (+20ATT, HP+100)" << endl;
						cout << "Do you want it? (yes/no)" << endl;
						string badResponse; 
						cin >> badResponse;
						for (char &c : badResponse)
						{
							c = toLower(c); //changes the response to lower case
						}
						if (badResponse == "yes")
						{
							cout << "You got caught cheating by the man! He was an authority! You have been expelled" << endl; 
							mainLoop = false; 
							break; 
						}
						else if (badResponse == "no")
						{
							cout << "The man just smiled and said, Good Choice. As he disappears, as you walking out of the alley way." << endl; 
							break; 
						}
						else if (badResponse == "enter")
						{
							cout << "You are already in the alley" << endl;
						}
						else if (badResponse == "help")
						{
							displayHelp(playerPos->key());
						}
						else
						{
							cout << "Invalid" << endl; 
						}
					}
				}
				else
				{
					cout << "You are already there" << endl;
				}
			}
			else if (response == "inventory")
			{
				if (playerInventory.isEmpty()) //if it is empty, prints out below
				{
					cout << endl;
					cout << "=============================================" << endl;
					cout << "Nothing in inventory" << endl;
					cout << "=============================================" << endl;
					cout << endl;
				}
				else
				{
					string inventoryResponse; 
					ItemFrame* currentNode = &playerInventory.top();
					while (true)
					{
						if (playerInventory.isEmpty()) //if it is empty, prints out below, and breaks out of the loop (used when you use the last thing in the inventory)
						{
							cout << endl;
							cout << "=============================================" << endl;
							cout << "Nothing in inventory" << endl;
							cout << "=============================================" << endl;
							cout << endl;
							break;
						}
						else
						{
							cout << "---------------------------------------------" << endl;
							cout << "Inventory Commands:" << endl;
							cout << "next: Cycles to next item" << endl; 
							cout << "previous: Cycles to previous item" << endl; 
							cout << "use: Use selected item" << endl; 
							cout << "exit: Exits the inventory" << endl; 
							cout << "---------------------------------------------" << endl;
							cout << endl; 
							cout << "=============================================" << endl; //displays the item and its description 
							cout << currentNode->getValue()->getName() << ": " << endl;
							cout << currentNode->getValue()->getDesc() << endl;
							cout << "=============================================" << endl;
							cin >> inventoryResponse;
							for (char &c : inventoryResponse)
							{
								c = toLower(c);
							}
							if (inventoryResponse == "next") //if response in inventory is next, goes to the next item in inventory
							{
								if (currentNode->getNext() == &ItemFrame::NIL)
								{
									cout << "Nothing beyond this item" << endl;
								}
								else
								{
									currentNode = currentNode->getNext();
								}
							}
							else if (inventoryResponse == "previous") //if response in inventory is previous, goes to the previous item in inventory
							{
								if (currentNode->getPrevious() == &ItemFrame::NIL)
								{
									cout << "Nothing before this item" << endl;
								}
								else
								{
									currentNode = currentNode->getPrevious();
								}
							}
							else if (inventoryResponse == "use") //if response is use, the player uses the current item selected. It is then switched with the top node of the stack and popped off, then removed. 
							{
								p1.Use(currentNode->getValue());
								currentNode->remove();
								ItemFrame temp = playerInventory.top();
								playerInventory.top() = *(currentNode);
								*(currentNode) = temp;
								playerInventory.pop();
								if (!playerInventory.isEmpty())
								{
									currentNode = &playerInventory.top();
								}
							}
							else if (inventoryResponse == "exit") //exits the inventory
							{
								break;
							}
							else
							{
								cout << "Invalid" << endl;
							}
						}
					}
				}
			}
			else if (response == "return")
			{
				playerPos = &startNode;
			}
			else if (response == "status")
			{
				p1.displayStatus();
			}
			else if (response == "map")
			{
				startNode.traverseDepthFirst(PreOrderVisitor<string>());
			}
			else if (response == "help")
			{
				displayHelp(playerPos->key()); 
			}
			else if (response == "whosyourdaddy")
			{
				p1.setAtt(100);
				p1.setHp(99999);
			}
			else if (response == "greedisgood")
			{
				p1.setMoneh(99999);
			}
			else if (response == "quit")
			{
				break;
			}
			else
			{
				cout << "Unrecognised command" << endl; 
			}
		}
		else
		{
			cout << "Invalid" << endl;
			playerPos = &startNode;
		}
	}

	cout << "Fin." << endl;  
	return 0; 
}

