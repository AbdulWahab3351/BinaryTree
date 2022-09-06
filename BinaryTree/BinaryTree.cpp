#include "BinaryTree.h"
#include<string>
#include<iostream>
using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree(int h)
{
	if (h <= 0)
	{
		nodeStatus = new bool;
		data = new T;
		maxHeight = 1;
		arraySize = 1;
		return;
	}
	maxHeight = h;
	arraySize = pow(2, maxHeight) - 1;
	data = new T[arraySize];
	nodeStatus = new bool[arraySize];
	for (int i = 0; i < arraySize; i++)
		nodeStatus[i] = false;
}
template<typename T>
void BinaryTree<T>:: setRoot(T v)
{
	data[0] = v;
	nodeStatus[0] = true;
}
template<typename T>
T BinaryTree<T>:: getRoot()
{
	if (nodeStatus[0])
		return data[0];
	throw string("Root not exists\n");
}
template<typename T>
void BinaryTree<T>::setLeftchild(T parent, T child)
{
	if (!nodeStatus[0])
		return;
	int index = findIndex(0,parent);
	if (index == -1)
		return;
	data[2 * index + 1] = child;
	nodeStatus[2 * index + 1] = true;
}
template<typename T>
void BinaryTree<T>::setRightchild(T parent, T child)
{
	if (!nodeStatus[0])
		return;
	int index = findIndex(0, parent);
	if (index == -1)
		return;
	data[2 * index + 2] = child;
	nodeStatus[2 * index + 2] = true;
}
template<typename T>
int BinaryTree<T>:: findIndex(int i, T key)
{
	int status = -1;
	if (data[i] == key)
		status = i;
	if ((status == -1) && (2 * i + 1 <= arraySize) && nodeStatus[2 * i + 1])
		status = findIndex(2 * i + 1, key);
	if ((status == -1) && (2 * i + 2 <= arraySize) && nodeStatus[2 * i + 2])
		status = findIndex(2 * i + 2, key);
	return status;
}
template<typename T>
T BinaryTree<T> :: getParent(T node)
{
	if (!nodeStatus[0])
		throw string("Tree is empty\n");
	int index = findIndex(0, node);
	if (index == -1)
		throw string("Node does not exists\n");
	if (index == 0)
		throw string("Root Node has no parent\n");
	return data[(index - 1) / 2];
}
template<typename T>
void BinaryTree<T>::remove(T node)
{
	if (!nodeStatus[0])
		return;
	int index = findIndex(0, node);
	if (index == -1)
		throw string("Node does not exists\n");
	removeDescendands(index);
}
template<typename T>
void BinaryTree<T>:: removeDescendands(int index)
{
	if (!nodeStatus[index])
		return;
	nodeStatus[index] = false;
	if (index * 2 + 2 < arraySize)
	{
		if (nodeStatus[2 * index + 1])
			removeDescendands(2 * index + 1);
		if (nodeStatus[2 * index + 2])
			removeDescendands(2 * index + 2);
	}
}
template<typename T>
void BinaryTree<T>::displayDescendant(int index)
{
	if (!nodeStatus[index])
		return;
	cout << data[index] << " ";
	if (index * 2 + 2 <= arraySize)
	{
		if (nodeStatus[2 * index + 1])
			displayDescendant(2 * index + 1);
		if (nodeStatus[2 * index + 2])
			displayDescendant(2 * index + 2);
	}
}
template<typename T>
void BinaryTree<T>::displayInOrder(int index)
{
	if (index > arraySize)
		return;
	if (index * 2 + 1 < arraySize && nodeStatus[2 * index + 1])
		displayInOrder(2 * index + 1);
	cout << data[index] << " ";
	if (index * 2 + 2 < arraySize && nodeStatus[2 * index + 2])
		displayInOrder(2 * index + 2);
}
template<typename T>
void BinaryTree<T>::displayPostOrder(int index)
{
	if (index > arraySize)
		return;
	if (index * 2 + 1 < arraySize && nodeStatus[2 * index + 1])
		displayPostOrder(2 * index + 1);
	if (index * 2 + 2 < arraySize && nodeStatus[2 * index + 2])
		displayPostOrder(2 * index + 2);
	cout << data[index] << " ";
}
template<typename T>
int BinaryTree<T>::findLevelOfNode(T node)
{
	if (!nodeStatus[0])
		return -1;
	int index = findIndex(0, node);
	int level = 0;
	while (index != 0)
	{
		++level;
		index = (index - 1) / 2;
	} 
	return level;
}
template<typename T>
void BinaryTree<T>:: displayDescendants(T node)
{
	if (!nodeStatus[0])
		return;
	int index = findIndex(0, node);
	if (index == -1)
		throw string("Node does not exists\n");
	if (2 * index + 1 < arraySize)
		displayDescendant(2 * index + 1);
	if (2 * index + 2 < arraySize)
		displayDescendant(2 * index + 2);
}
template<typename T>
void BinaryTree<T>:: displayAncestors(T node)
{
	if (!nodeStatus[0])
		return;
	int index = findIndex(0, node);
	if (index == -1)
		return;
	if (index == 0)
		throw string("Root node has no ancestors\n");
	do
	{
		index = (index - 1) / 2;
		cout << data[index] << " ";
	} while (index != 0);
	cout << endl;
}
template<typename T>
void BinaryTree<T>:: preOrder()
{
	if (!nodeStatus[0])
		return;
	cout << data[0] << " ";
	if (nodeStatus[1])
		displayDescendant(1);
	if (nodeStatus[2])
		displayDescendant(2);
}

template<typename T>
void BinaryTree<T>:: inOrder()
{
	if (!nodeStatus[0])
		return;
	displayInOrder(0);
}

template<typename T>
int BinaryTree<T> :: heightOfTree()
{
	if (!nodeStatus[0])
		return 0;
	return getHeight(0);
}
template<typename T>
int BinaryTree<T> :: getHeight(int v)
{
	int left = 0;
	int right = 0;
	if (2 * v + 1 < arraySize && nodeStatus[2 * v + 1])
		left = getHeight(2 * v + 1);
	if (2 * v + 2 < arraySize && nodeStatus[2 * v + 2])
		right = getHeight(2 * v + 2);
	return left > right ? 1 + left : 1 + right;
}
template<typename T>
void BinaryTree<T>:: postOrder()
{
	if (!nodeStatus[0])
		return;
	displayPostOrder(0);
}
template<typename T>
void BinaryTree<T>:: displayParenthesizedView()
{
	if (!nodeStatus[0])
		return;
	parenthesizedView(0);
}
template <typename T>
void BinaryTree<T> :: parenthesizedView(int index)
{
	cout << data[index];
	if (index * 2 + 2 < arraySize)
	{
		if (nodeStatus[2 * index + 1] || nodeStatus[2 * index + 2])
			cout << '(';
		else
			return;
		if (nodeStatus[2 * index + 1])
			parenthesizedView(2 * index + 1);
		cout << ',';
		if (nodeStatus[2 * index + 2])
			parenthesizedView(2 * index + 2);
		cout << ')';
	}
}
template <typename T>
void BinaryTree<T>:: explorerView(int index, int level)
{
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << data[index] << '\n';
	if (index * 2 + 2 < arraySize)
	{
		if (nodeStatus[2 * index + 1])
			explorerView(index * 2 + 1, level + 1);
		if (nodeStatus[2 * index + 2])
			explorerView(index * 2 + 2, level + 1);
	}
}
template <typename T>
void BinaryTree<T>:: displayExplorerView()
{
	if (!nodeStatus[0])
		return;
	explorerView(0, 0);
}
template <typename T>
void BinaryTree<T>::levelOrderTraversing(Queue<T>& q, Queue<int>& qIndex)
{
	int index;
	while (!q.isEmpty())
	{
		cout << q.deQueue() << ' ';
		index = qIndex.deQueue();
		if ((2 * index + 1 < arraySize) && nodeStatus[2 * index + 1])
		{
			qIndex.enQueue(2 * index + 1);
			q.enQueue(data[2*index+1]);
		}
		if ((2 * index + 2 < arraySize) && nodeStatus[2 * index + 2])
		{
			qIndex.enQueue(2 * index + 2);
			q.enQueue(data[2*index+2]);
		}
	}
}
template <typename T>
void BinaryTree<T> :: levelOrder()
{
	if (!nodeStatus[0])
		return;
	Queue<T> q;
	Queue<int> qIndex;
	q.enQueue(data[0]);
	qIndex.enQueue(0);
	levelOrderTraversing(q, qIndex);
}
template<typename T>
void BinaryTree<T>:: displayLevelNo(Queue<T>& q, Queue<int>& qIndex, int lowerLimit, int upperLimit)
{
	T temp;
	int index;
	while (!q.isEmpty())
	{
		temp = q.deQueue();
		index = qIndex.deQueue();
		if (index >= lowerLimit && index <= upperLimit)
			cout << temp << ' ';
		else
		{
			if ((2 * index + 1 < arraySize) && nodeStatus[2 * index + 1])
			{
				qIndex.enQueue(2 * index + 1);
				q.enQueue(data[2 * index + 1]);
			}
			if ((2 * index + 2 < arraySize) && nodeStatus[2 * index + 2])
			{
				qIndex.enQueue(2 * index + 2);
				q.enQueue(data[2 * index + 2]);
			}
		}
	}
}
template<typename T>
void BinaryTree<T>::displayLevel(int levelNo)
{
	if (levelNo >= maxHeight)
		return;
	if (!nodeStatus[0])
		return;
	int upperLimit = pow(2, levelNo + 1);
	int lowerLimit = upperLimit / 2 - 1;
	upperLimit -= 2;
	Queue<T> q;
	Queue<int> qIndex;
	q.enQueue(data[0]);
	qIndex.enQueue(0);
	displayLevelNo(q, qIndex, lowerLimit, upperLimit);
	cout << endl;
}

