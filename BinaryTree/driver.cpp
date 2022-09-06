#include "BinaryTree.h"
#include<iostream>
using namespace std;

int main()
{
	BinaryTree<char> tree(7);
	tree.setRoot('A');
	tree.setLeftchild('A', 'B');
	tree.setRightchild('A', 'C');
	tree.setLeftchild('B', 'D');
	tree.setRightchild('B', 'E');
	tree.setRightchild('D', 'H');
	tree.setLeftchild('E', 'I');
	tree.setRightchild('E', 'J');
	tree.setLeftchild('I', 'K');
	tree.setRightchild('C', 'F');
	tree.displayParenthesizedView();
	cout << endl;
	tree.displayExplorerView();
	cout << '\n';
	//tree.levelOrder();
	cout << '\n';
	tree.displayLevel(0);
	tree.displayLevel(1);
	tree.displayLevel(2);
	tree.displayLevel(3);
	tree.displayLevel(4);
	tree.displayDescendants('F');
	/*tree.remove('E');
	tree.displayExplorerView();*/
	return 0;
}