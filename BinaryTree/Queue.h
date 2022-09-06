#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;

	void reSize(int newCap);
public:
	Queue();
	~Queue();
	void enQueue(T elem);
	T deQueue();
	T getElementAtFront();
	bool isEmpty();
	bool isFull();
	int getNoOfElements();
	int getCapacity();
};

#endif // !QUEUE_H

