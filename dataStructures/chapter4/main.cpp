#include <iostream>
#include <stdlib.h>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc,char *argv[])
{
	BinarySearchTree<int> bstree;

	int num;
	for(int i = 0; i < 10; ++i )
	{
		cin >> num;
		bstree.Insert(num);
	}

	cout << "input search num: ";
	cin >> num;
	TreeNode<int> *find_node = bstree.Find(num);
	if( find_node != NULL )
		cout << "exist" << endl;
	else
		cout << "not exist" << endl;

	cout << "input delete num: ";
	cin >> num;
	bstree.Delete(num,bstree.GetRoot());

	cout << "PreOrder: ";
	bstree.PreOrder(bstree.GetRoot());
	cout << endl;
	cout << "NoPreOrder: ";
	bstree.NoPreOrder();
	cout << endl;

	cout << "InOrder: ";
	bstree.InOrder(bstree.GetRoot());
	cout << endl;
	cout << "NoInOrder: ";
	bstree.NoInOrder();
	cout << endl;

	cout << "PostOrder: ";
	bstree.PostOrder(bstree.GetRoot());
	cout << endl;
	cout << "NoPostOrder: ";
	bstree.NoPostOrder();
	cout << endl;
	return 0;
}