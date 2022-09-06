#include "Queue.h"
#include<exception>
using namespace std;

template<typename T>
Queue<T>::Queue()
{
	rear = front = capacity = noOfElements = 0;
	data = nullptr;
}
template<typename T>
Queue<T>::~Queue()
{
	if (data)
		delete[]data;
	data = nullptr;
	rear = front = capacity = noOfElements = 0;
}
template<typename T>
void Queue<T> :: enQueue(T elem)
{
	if (capacity == 0)
		reSize(1);
	if (isFull())
		reSize(capacity * 2);
	data[front] = elem;
	noOfElements++;
	front = (front + 1) % capacity;
}
template<typename T>
T Queue<T> ::deQueue()
{
	if (isEmpty())
		throw exception();
	noOfElements--;
	T temp = data[rear];
	rear = (rear + 1) % capacity;
	if (noOfElements == (capacity / 4.0))
		reSize(capacity / 2);
	return temp;
}
template<typename T>
T Queue<T>::getElementAtFront()
{
	if (isEmpty())
		throw exception();
	return data[0];
}
template<typename T>
bool Queue<T> :: isEmpty()
{
	return noOfElements == 0;
}
template<typename T>
bool Queue<T> :: isFull()
{
	return noOfElements == capacity;
}
template<typename T>
int Queue<T> :: getNoOfElements()
{
	return noOfElements;
}
template<typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}
template <typename T>
void Queue<T>:: reSize(int newCap)
{
	T* temp = new T[newCap];
	for (int i = 0, j = rear; i < noOfElements; i++, j = (j + 1) % capacity)
		temp[i] = data[j];
	if(data)
		delete[]data;
	data = temp;
	temp = nullptr;
	capacity = newCap;
	rear = 0;
	front = noOfElements;
}