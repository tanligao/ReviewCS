#ifndef __BINARYSEARCHTREE_H
#define __BINARYSEARCHTREE_H

#include <iostream>
#include <assert.h>
#include <stack>

template<typename T>
class TreeNode
{
public:
	TreeNode():_left(NULL),_right(NULL) {}
	TreeNode(T value):_value(value),_left(NULL),_right(NULL) {}
	~TreeNode(){}
public:
	T _value;
	TreeNode<T> *_left;
	TreeNode<T> *_right;
};

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void MakeEmpty(TreeNode<T> *node);
	
	TreeNode<T>* Find(T value);
	TreeNode<T>* FindMin(TreeNode<T> *node);
	TreeNode<T>* FindMax(TreeNode<T> *node);
	
	TreeNode<T>* Insert(T value);

	TreeNode<T>* Delete(T value,TreeNode<T> *node);
	
	inline TreeNode<T>* GetRoot() { return _root; }
public:
	void PreOrder(TreeNode<T> *node);
	void InOrder(TreeNode<T> *node);
	void PostOrder(TreeNode<T> *node);

	void NoPreOrder();
	void NoInOrder();
	void NoPostOrder();
protected:
	void Destory();
private:
	TreeNode<T> *_root;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	_root = NULL;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	Destory();
}

template<typename T>
void BinarySearchTree<T>::MakeEmpty(TreeNode<T> *node)
{
	if( node != NULL )
	{
		MakeEmpty(node->_left);
		MakeEmpty(node->_right);
		delete node;
	}
}

template<typename T>	
TreeNode<T>* BinarySearchTree<T>::Find(T value)
{
	TreeNode<T> *pnode = _root;
	while( pnode != NULL )
	{
		if( pnode->_value > value )
			pnode = pnode->_left;
		else if( pnode->_value < value )
			pnode = pnode->_right;
		else
			return pnode;
	}
	return NULL;
}

template<typename T>	
TreeNode<T>* BinarySearchTree<T>::FindMin(TreeNode<T> *node)
{
	TreeNode<T> *pnode = node;
	while( pnode != NULL )
	{
		if( pnode->_left == NULL )
			return pnode;
		else
			pnode = pnode->_left;
	}
	return pnode;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::FindMax(TreeNode<T> *node)
{
	TreeNode<T> *pnode = node;
	while( pnode != NULL )
	{
		if( pnode->_right == NULL )
			return pnode;
		else
			pnode = pnode->_right;
	}
	return pnode;
}

template<typename T>	
TreeNode<T>* BinarySearchTree<T>::Insert(T value)
{
	TreeNode<T> *pnode = _root;
	TreeNode<T> *pparent_node = pnode;
	while( pnode != NULL )
	{
		pparent_node = pnode;
		if( pnode->_value > value )
			pnode = pnode->_left;
		else
			pnode = pnode->_right;
	}
	pnode = new TreeNode<T>(value);
	if( pparent_node == NULL )
	{
		_root = pnode;
	}
	else if( pparent_node->_value > value )
	{
		pparent_node->_left = pnode;
	}
	else
	{
		pparent_node->_right = pnode;
	}
	return pnode;
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::Delete(T value,TreeNode<T> *node)
{
	TreeNode<T> *ptmp;

	assert(node != NULL);
	if( value < node->_value )
		node->_left = Delete(value,node->_left);
	else if( value > node->_value)
		node->_right = Delete(value,node->_left);
	else if( node->_left && node->_right )
	{
		ptmp = FindMin(node->_right);
		node->_value = ptmp->_value;
		node->_right = Delete(node->_value,node->_right);
	}
	else
	{
		ptmp = node;
		if( node->_left == NULL )
			node = node->_right;
		else if( node->_right == NULL )
			node = node->_left;
		delete ptmp;
	}
	return node;
}

template<typename T>
void BinarySearchTree<T>::Destory()
{
	MakeEmpty(_root);
	_root = NULL;
}

template<typename T>
void BinarySearchTree<T>::PreOrder(TreeNode<T> *node)
{
	if( node != NULL )
	{
		std::cout << node->_value << " ";
		PreOrder(node->_left);
		PreOrder(node->_right);		
	}
}

template<typename T>
void BinarySearchTree<T>::InOrder(TreeNode<T> *node)
{
	if( node != NULL )
	{
		InOrder(node->_left);
		std::cout << node->_value << " ";
		InOrder(node->_right);		
	}
}

template<typename T>
void BinarySearchTree<T>::PostOrder(TreeNode<T> *node)
{
	if( node != NULL )
	{
		PostOrder(node->_left);
		PostOrder(node->_right);		
		std::cout << node->_value << " ";
	}
}

template<typename T>
void BinarySearchTree<T>::NoPreOrder()
{
	TreeNode<T> *pnode = _root;
	std::stack<TreeNode<T>* > stack;

	while( pnode != NULL || !stack.empty() )
	{
		if( pnode != NULL )
		{
			std::cout << pnode->_value << " ";
			if( pnode->_right != NULL )
				stack.push(pnode->_right);
			pnode = pnode->_left;
		}
		else
		{
			pnode = stack.top();
			stack.pop();
		}
	}
}

template<typename T>
void BinarySearchTree<T>::NoInOrder()
{
	TreeNode<T> *pnode = _root;
	std::stack<TreeNode<T>* > stack;

	while( pnode != NULL || !stack.empty() )
	{
		if( pnode != NULL )
		{
			stack.push(pnode);
			pnode = pnode->_left;
		}
		else
		{
			pnode = stack.top();
			stack.pop();
			std::cout << pnode->_value << " ";
			pnode = pnode->_right;
		}
	}
	
}

template<typename T>
void BinarySearchTree<T>::NoPostOrder()
{
	TreeNode<T> *cur = NULL;
	TreeNode<T> *pre = NULL;
	std::stack<TreeNode<T>* > stack;
	stack.push(_root);

	while( !stack.empty() )
	{
		cur = stack.top();
		if( (cur->_left == NULL && cur->_right == NULL) || (pre && ((pre == cur->_left) || (pre == cur->_right))))
		{
			std::cout << cur->_value << " ";
			stack.pop();
			pre = cur;
		}
		else
		{
			if( cur->_right != NULL )
			{
				stack.push(cur->_right);
			}
			if( cur->_left != NULL )
			{
				stack.push(cur->_left);
			}
		}
	}
}

#endif /* __BINARYSEARCHTREE_H */