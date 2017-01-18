#ifndef __MYSTACK_H
#define __MYSTACK_H

#include <iostream>
#include <assert.h>

template<typename T>
class stackNode
{
public:
	stackNode(){}
	stackNode(T value):_value(value),_next(NULL) {}
public:
	T _value;
	stackNode *_next;
};

template<typename T>
class myStack
{
public:
	myStack(){ S = new stackNode<T>(); }
	~myStack(){ Destory(); }

	bool IsEmpty();

	void MakeEmpty();
	void Push(T value);
	void Pop();
	T       Top();
protected:
	void Destory();
private:
	stackNode<T> *S;
};

template<typename T>
bool myStack<T>::IsEmpty()
{
	return S->_next == NULL;
}

template<typename T>
void myStack<T>::MakeEmpty()
{
	assert(S != NULL);
	while( !IsEmpty() )
		Pop();
}

template<typename T>
void myStack<T>::Push(T value)
{
	stackNode<T> *pnew_node = new stackNode<T>(value);
	pnew_node->_next = S->_next;
	S->_next = pnew_node;
}

template<typename T>
void myStack<T>::Pop()
{
	assert( !IsEmpty() );
	stackNode<T> *pnode = S->_next;
	S->_next = S->_next->_next;
	delete pnode;
}

template<typename T>
T myStack<T>::Top()
{
	assert( !IsEmpty() );
	stackNode<T> *pnode = S->_next;
	return pnode->_value;
}

template<typename T>
void myStack<T>::Destory()
{
	MakeEmpty();
	delete S;
	S = NULL;
}

#endif /* __MYSTACK_H */