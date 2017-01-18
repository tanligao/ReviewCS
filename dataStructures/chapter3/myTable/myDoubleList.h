#ifndef __MYDOUBLELIST_H
#define __MYDOUBLELIST_H

#include <iostream>

template<typename T>
class DoubleListNode
{
public:
	DoubleListNode():_pre(NULL),_next(NULL) {}
	DoubleListNode(T value):_value(value),_pre(NULL),_next(NULL) {}
public:
	T _value;
	DoubleListNode *_pre;
	DoubleListNode *_next;
};

template<typename T>
class myDoubleList
{
public:
	myDoubleList();
	~myDoubleList();

	bool IsEmpty();
	bool IsLast(DoubleListNode<T>* pnode);

	DoubleListNode<T>* Find(T value);
	void Insert(T value,DoubleListNode<T>* position = NULL);
	void Delete(T value);
	void PrintList();
protected:
	void Destory();
private:
	DoubleListNode<T>* _header;
};

template<typename T>
myDoubleList<T>::myDoubleList()
{
	_header = new DoubleListNode<T>();
	_header->_pre = NULL;
	_header->_next = NULL;
}

template<typename T>
myDoubleList<T>::~myDoubleList()
{
	Destory();
}

template<typename T>
bool myDoubleList<T>::IsEmpty()
{
	if( _header->pre == NULL && _header->_next == NULL )
		return true;
	return false;
}

template<typename T>
bool myDoubleList<T>::IsLast(DoubleListNode<T>* pnode)
{
	if( pnode->_next == NULL )
		return true;
	return false;
}

template<typename T>
DoubleListNode<T>* myDoubleList<T>::Find(T value)
{
	DoubleListNode<T>* pnode = _header->_next;
	while( pnode != NULL && pnode->_value != value )
	{
		pnode = pnode->_next;
	}
	return pnode;
}

template<typename T>
void myDoubleList<T>::Insert(T value,DoubleListNode<T>* position)
{
	DoubleListNode<T>* pnew_node = new DoubleListNode<T>(value);

	if( position == NULL )
	{
		// insert _header back
		pnew_node->_next = _header->_next;
		pnew_node->_pre = _header;
		if( _header->_next != NULL )
		{
			_header->_next->_pre = pnew_node;
		}
		
		_header->_next = pnew_node;
	}
	else
	{
		// insert to position back
		pnew_node->_next = position->_next;
		pnew_node->_pre = position;
		position->_next = pnew_node;
		if( pnew_node->_next != NULL )
		{
			pnew_node->_next->_pre = pnew_node;
		}
	}
}

template<typename T>
void myDoubleList<T>::Delete(T value)
{
	DoubleListNode<T>* pfind_node = Find(value);
	if( pfind_node != NULL )
	{
		DoubleListNode<T>* pre_node = pfind_node->_pre;
		DoubleListNode<T>* next_node = pfind_node->_next;

		pre_node->_next = next_node;
		if( next_node != NULL )
		{
			next_node->_pre = pre_node;
		}

		delete pfind_node;
		pfind_node = NULL;
	}
}

template<typename T>
void myDoubleList<T>::Destory()
{
	DoubleListNode<T>* pnode = _header->_next;
	DoubleListNode<T>* ptmp;

	while( pnode != NULL )
	{
		ptmp = pnode->_next;
		delete pnode;
		pnode = ptmp;
	}

	delete _header;
	_header = NULL;
}

template<typename T>
void myDoubleList<T>::PrintList()
{
	DoubleListNode<T> *pnode = _header->_next;
	while( pnode != NULL )
	{
		std::cout  << pnode->_value << " ";
		pnode = pnode->_next;
	}
	std::cout << std::endl;
}

#endif /* __MYDOUBLELIST_H */