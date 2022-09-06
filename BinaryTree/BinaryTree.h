#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include"Queue.h"
template <typename T>
class BinaryTree
{
	int maxHeight;
	T* data;
	bool* nodeStatus;
	int arraySize;

	int findIndex(int i, T key);
	void removeDescendands(int index);
	void displayDescendant(int index);
	void displayInOrder(int index);
	void displayPostOrder(int index);
	int getHeight(int v);
	void parenthesizedView(int index);
	void explorerView(int index, int level);
	void levelOrderTraversing(Queue<T>& q, Queue<int>& qIndex);
	void displayLevelNo(Queue<T>& q, Queue<int>& qIndex, int lowerLimit, int upperLimit);
public:
	BinaryTree(int h);
	void setRoot(T v);
	T getRoot();
	void setLeftchild(T parent, T child);
	void setRightchild(T parent, T child);
	T getParent(T node);
	void displayLevel(int levelNo);
	void remove(T node);
	void displayDescendants(T node);
	void displayAncestors(T node);
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrder();
	int heightOfTree();
	void displayParenthesizedView();
	void displayExplorerView();
	int findLevelOfNode(T node);
};
#endif // !BINARY_TREE_H


