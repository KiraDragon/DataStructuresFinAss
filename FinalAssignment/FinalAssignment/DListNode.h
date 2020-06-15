#pragma once
#include <iostream>
using namespace std; 

template <class T>

class DListNode
{
public: 
	typedef DListNode<T> DNode;
	
private:
	T fContent; 
	DNode* fNext; 
	DNode* fPrev; 

public:
	static DNode NIL; 
	DListNode()
	{
		fContent = T();
		fNext = &NIL;
		fPrev = &NIL;
	}
	DListNode(const T& aContent);
	void prepend(DNode& aNode);
	void append(DNode& aNode);
	void remove(); 
	void detatch(); 

	const T& getValue() const; 
	DNode* getNext() const;
	DNode* getPrevious() const; 
};

template<class T>
DListNode<T> DListNode<T>::NIL;

template<class T>
DListNode<T>::DListNode(const T& aContent)
{
	fContent = aContent;
	fNext = &NIL;
	fPrev = &NIL; 
}

template<class T>
void DListNode<T>::prepend(DNode& aNode)
{
	aNode.fNext = this; 
	if (fPrev != &NIL)
	{
		aNode.fPrev = fPrev;
		fPrev->fNext = &aNode; 
	}
	fPrev = &aNode; 
}

template<class T>
void DListNode<T>::append(DNode& aNode)
{
	aNode.fPrev = this; 
	if (fNext != &NIL)
	{
		aNode.fNext = fNext;
		fNext->fPrev = &aNode; 
	}
	fNext = &aNode; 
}

template<class T>
void DListNode<T>::remove()
{
	if (fNext == &NIL)
	{
		fPrev->fNext = &NIL; 
	}
	else
	{
		if (fPrev == &NIL)
		{
			fNext->fPrev = &NIL; 
		}
		else
		{
			fNext->fPrev = fPrev; 
			fPrev->fNext = fNext; 
		}
	}
}

template<class T>
void DListNode<T>::detatch()
{
	fNext = &NIL; 
	fPrev = &NIL; 
}

template<class T>
const T& DListNode<T>::getValue() const
{
	return fContent; 
}

template<class T>
DListNode<T>* DListNode<T>::getNext() const
{
	return fNext; 
}

template<class T>
DListNode<T>* DListNode<T>::getPrevious() const
{
	return fPrev;
}