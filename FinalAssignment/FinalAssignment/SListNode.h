#pragma once
#include <iostream>
using namespace std; 

template<class T>
class SListNode
{
private: 
	T fContent;
	SListNode* fNext;
	string fEvent;

public:
	SListNode(string aEvent, const T& aContent, SListNode* aNext = (SListNode*)0)
	{
		fEvent = aEvent;
		fContent = aContent;
		fNext = aNext; 
	}

	const string getEvent()
	{
		return fEvent; //returns the event 
	}

	const T& getValue() const
	{
		return fContent; //returns the content
	}

	SListNode* getNext()
	{
		return fNext; //returns a pointer to the next node
	}
};