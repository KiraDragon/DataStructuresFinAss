#pragma once
#include <iostream>
#include "Item.h"
#include "DListNode.h"
using namespace std; 

template<class T>
class Stack
{
private:
	T* fElements; //The element in the stack
	int fStackPointer; //The int pointer for the stack
	int StackSize; //The size of the stack 

public:
	Stack(int size); //Constructor of the stack with a fixed size
	Stack();
	~Stack();

	bool isEmpty() const; //check if the stack is empty or not
	int getSize() const; //gets the size of the stack
	void push(const T& aContent); //push a new data type T into the stack
	void pop(); //pops the top most value out of the stack
	T& top() const; //returns the top value
	T& getElement(int slot); //gets the element in the slot

	friend DListNode<Item*>; //friends with the ListNodeTemplate class with the item pointer
};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::Stack(int size)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Illegal stack size"); //If the int is less than 0 or equals to 0, itll through a invalid argument error
	}
	else
	{
		fElements = new T[size]; //creates an array with the data type T, with the size from the constructor 
		fStackPointer = 0; //default stack pointer is 0
		StackSize = size; //stack size is set with the size 
	}
}

template <class T>
T& Stack<T>::getElement(int slot)
{
	return fElements[slot]; //returns the element at the position in the stack
}

template <class T>
void Stack<T>::push(const T& content)
{
	if (fStackPointer < StackSize)
	{
		fElements[fStackPointer++] = content; //pushes the content into the position in the stack
	}
	else
	{
		throw std::overflow_error("Stack Full"); //throws out stack full when trying to push into a full stack
	}
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return(fStackPointer == 0); //returns true if the stack is empty
}

template <class T>
void Stack<T>::pop()
{
	if (!isEmpty())
	{
		fStackPointer--; //pops the top most element out of the stack by decreasing the pointer
	}
	else
	{
		throw std::underflow_error("Stack is empty");
	}
}

template <class T>
T& Stack<T>::top() const
{
	if (!isEmpty())
	{
		return fElements[fStackPointer - 1]; //returns the top most element of the stack
	}
	else
	{
		throw std::underflow_error("Stack is empty");
	}
}


template<class T>
int Stack<T>::getSize() const
{
	return fStackPointer; //gets the current size of the stack
}

template<class T>
Stack<T>::~Stack()
{
	delete[] fElements;
}