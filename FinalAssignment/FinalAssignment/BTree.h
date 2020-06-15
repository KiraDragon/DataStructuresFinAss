#pragma once
#include <stdexcept>
#include "TreeVisitor.h"

template <class T>
class BTree
{
private:
	const T* fKey;
	BTree<T>* fLeft;
	BTree<T>* fRight;
	T fContent; 

	BTree() : fKey((T*)0)
	{
		fLeft = &NIL;
		fRight = &NIL;
	}

public:
	static BTree<T> NIL;

	BTree(const T& aKey, T pContent) : fKey(&aKey)
	{
		fContent = pContent; 
		fLeft = &NIL;
		fRight = &NIL;
	}

	~BTree()
	{
		if (fLeft != &NIL)
			delete fLeft;
		if (fRight != &NIL)
			delete fRight;
	}

	bool isEmpty() const
	{
		return (this == &NIL);
	}

	const T& key() const
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			return *fKey;
		}
	}

	T& content() 
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			return fContent;
		}
	}

	BTree& left() const
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			return *fLeft;
		}
	}

	BTree& right() const
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			return *fRight;
		}
	}

	void attachLeft(BTree<T>* aBTree)
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else if (fLeft != &NIL)
		{
			throw std::domain_error("Non-empty sub tree");
		}
		else
		{
			fLeft = new BTree<T>(*aBTree);
		}
	}

	void attachRight(BTree<T>* aBTree)
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else if (fRight != &NIL)
		{
			throw std::domain_error("Non-empty sub tree");
		}
		else
		{
			fRight = new BTree<T>(*aBTree);
		}
	}

	BTree* detachLeft()
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			BTree& Result = *fLeft;
			fLeft = &NIL;
			return &Result;
		}
	}

	BTree* detachRight()
	{
		if (isEmpty())
		{
			throw std::domain_error("Empty BTree");
		}
		else
		{
			BTree& Result = *fRight;
			fRight = &NIL;
			return &Result;
		}
	}

	void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
	{
		if (!isEmpty())
		{
			aVisitor.preVisit(key());
			left().traverseDepthFirst(aVisitor);
			aVisitor.postVisit(key());
			right().traverseDepthFirst(aVisitor);
			aVisitor.inVisit(key());
		}
	}
};

template<class T>
BTree<T> BTree<T>::NIL;