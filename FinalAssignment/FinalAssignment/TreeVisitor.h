#pragma once
#pragma once
#include <iostream>

using namespace std;

template <class T>
class TreeVisitor
{
public:
	virtual ~TreeVisitor() {}
	virtual void preVisit(const T& aKey) const {}
	virtual void postVisit(const T& aKey) const {}
	virtual void inVisit(const T& aKey) const {}

	virtual void visit(const T& aKey) const
	{
		cout << aKey << " ";
	}
};

template <class T>
class PostOrderVisitor : public TreeVisitor<T>
{
public:
	virtual void postVisit(const T& aKey) const
	{
		this->visit(aKey);
	}
};

template <class T>
class PreOrderVisitor : public TreeVisitor<T>
{
public:
	virtual void preVisit(const T& aKey) const
	{
		this->visit(aKey);
	}
};

template <class T>
class InOrderVisitor : public TreeVisitor<T>
{
public:
	virtual void inVisit(const T& aKey) const
	{
		this->visit(aKey);
	}
};