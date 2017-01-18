#ifndef __MYQUEUE_H
#define __MYQUEUE_H

#include <iostream>
#include <assert.h>

#define QUEUE_NUM 10
#define INVALID_VALUE -1

template<typename T>
class myQueue
{
public:
	myQueue(int queue_length = QUEUE_NUM);
	~myQueue();

	bool IsEmpty();
	bool IsFull();
	void Enqueue(T value);
	void Dequeue();
	T       Front();
	T       FrontAndDequeue();

	void MakeEmpty();
private:
	T *_queue;
	int _front;
	int _rear;
	int _queue_capacity;
	int _size;
};

template<typename T>
myQueue<T>::myQueue(int queue_length):_front(1),
		_rear(0),_queue_capacity(queue_length),_size(0)
{
	assert( _queue_capacity > 0 );
	_queue = new T[_queue_capacity];
	for(int i = 0; i < _queue_capacity; ++i )
	{
		_queue[i] = INVALID_VALUE;
	}
}

template<typename T>
myQueue<T>::~myQueue()
{
	delete[] _queue;
	_queue = NULL;
}

template<typename T>
bool myQueue<T>::IsEmpty()
{
	return _size == 0;
}

template<typename T>
bool myQueue<T>::IsFull()
{
	return _size == _queue_capacity;
}

template<typename T>
void myQueue<T>::Enqueue(T value)
{
	assert( !IsFull() );
	++_size;
	_rear = ((_rear+1) != _queue_capacity)?(_rear+1):0;
	_queue[_rear] = value;
}

template<typename T>
void myQueue<T>::Dequeue()
{
	assert( !IsEmpty() );
	--_size;
	_queue[_front] = INVALID_VALUE;
	_front = ((_front+1) != _queue_capacity)?(_front+1):0;
}

template<typename T>
void myQueue<T>::MakeEmpty()
{
	_size = 0;
	_front = 1;
	_rear = 0;
}

template<typename T>
T myQueue<T>::Front()
{
	assert( !IsEmpty() );
	return _queue[_front];
}
	
template<typename T>
T myQueue<T>::FrontAndDequeue()
{
	assert( !IsEmpty() );
	--_size;
	T value = _queue[_front];
	_queue[_front] = INVALID_VALUE;
	_front = ((_front+1) != _queue_capacity)?(_front+1):0;
	return value;
}

#endif /* __MYQUEUE_H */