#include <iostream>
#include "Binary-Tree.h"

using namespace std;

int main() {
	BST<int>tree;
	int treeValue;

	cout << "Enter values, then end with -1" << endl;
	cin >> treeValue;
	while (treeValue != -1) {
		tree.insert(treeValue);
		cin >> treeValue;
	}
	tree.printTree();
	cout << "In-order traversal: " << endl;
	tree.inorder();
	cout << endl;
	cout << "Pre-order traversal: " << endl;
	tree.preorder();
	cout << endl;
	cout << "Post-order traversal: " << endl;
	tree.postorder();
	cout << endl;
	cout << "The height of the tree is: " << tree.height() << endl;
	cout << "The number of nodes is: " << tree.nodeCount() << endl;
	cout << "The number of leaves is: " << tree.leavesCount() << endl;

	cout << "Which node do you want to delete?" << endl;
	cin >> treeValue;
	tree.findAndDeleteByCopying(treeValue);
	tree.printTree();





}