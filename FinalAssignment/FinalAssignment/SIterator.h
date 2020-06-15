#pragma once
#include <iostream>
#include "SListNode.h"

template <class T>
class SIterator
{
private:
	SListNode<T>* fNode;
public:
	typedef SIterator<T> Iter; 
	SIterator(SListNode<T>* aNode); 
	const T& operator*() const; 
	Iter& operator++(); 
	Iter operator++(int); 
	bool operator==(const Iter& aOther) const; 
	bool operator!=(const Iter& aOther) const; 
	SListNode<T>* getNode(); //gets the current node
	Iter end(); 
	~SIterator(){};
};

template <class T>
SIterator<T>::SIterator(SListNode<T>* aNode)
{
	fNode = aNode; 
}

template <class T>
SListNode<T>* SIterator<T>::getNode()
{
	return fNode; 
}

template <class T>
const T& SIterator<T>::operator*() const
{
	return fNode->getValue(); 
}

template <class T>
SIterator<T>& SIterator<T>::operator++()
{
	if (fNode)
	{
		fNode = fNode->getNext();
		return *this; 
	}
}

template <class T>
SIterator<T> SIterator<T>::operator++(int)
{
	SIterator<T> temp = *this; 
	++(*this);
	return temp; 
}

template <class T>
bool SIterator<T>::operator==(const SIterator<T>& aOther) const
{
	return(fNode == aOther.fNode); 
}

template <class T>
bool SIterator<T>::operator!=(const SIterator<T>& aOther) const
{
	return !(*this == aOther);
}

template <class T>
SIterator<T> SIterator<T>::end()
{
	return SIterator<T>(nullptr); 
}

