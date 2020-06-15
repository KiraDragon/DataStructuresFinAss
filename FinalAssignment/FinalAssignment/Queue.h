#pragma once
#include <iostream>

using namespace std; 

template <class T>
class Queue
{
private:
	T* fElements; 
	int fQueueFront;
	int fQueueRear; 
	int QueueSize; 

public:
	Queue(int size); 
	Queue();
	~Queue();
	bool isEmpty() const; 
	int size() const; 
	void enqueue(const T& aElement);
	const T& dequeue(); 
};

template<class T>
Queue<T>::Queue(int size) 
{
	if (size <= 0)
	{
		throw std::invalid_argument("Illegal queue size"); //If the int is less than 0 or equals to 0, itll through a invalid argument error
	}
	else
	{
		fElements = new T[size]; //creates an array with the data type T, with the size from the constructor 
		fQueueFront = -1; 
		fQueueRear = -1; 
		QueueSize = size; 
	}
}

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::~Queue()
{
	delete[] fElements;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return (fQueueFront == -1 && fQueueRear == -1); 
}

template<class T>
int Queue<T>::size() const
{
	return (fQueueRear + 1); 
}

template<class T>
void Queue<T>::enqueue(const T& aElement)
{
	if (fQueueRear == QueueSize - 1)
	{
		throw std::overflow_error("Queue Full");
	}
	else
	{
		if (fQueueFront == -1)
		{
			fQueueFront = 0;
		}
		fQueueRear++; 
		fElements[fQueueRear] = aElement;
	}
}

template<class T>
const T& Queue<T>::dequeue()
{
	if (isEmpty())
	{
		throw std::underflow_error("Queue is empty");
	}
	else
	{
		if (fQueueFront == fQueueRear)
		{
			fQueueFront = -1; 
			fQueueRear = -1; 
			return fElements[QueueSize - 1]; 
		}
		else
		{ 
			return fElements[fQueueFront++];
		}
	}
}