#ifndef __MYHASH_H
#define __MYHASH_H

#include <iostream>
#include <assert.h>


#define MinTableSize 10

// default hash function
static unsigned int default_hash(void *key,int key_size,int table_size)
{
	char *str = (char *)key;
	unsigned int index = 0;

	for( int i = 0; *str && i < key_size; ++i )
	{
		index = *str + 4*index;
		++str;
	}
	return index % table_size;
}

template<typename T>
struct TableNode
{
public:
	TableNode(T value) : _value(value),_next(NULL) { }
public:
	T _value;
	TableNode<T> *_next;
};

template<typename T>
class myHashTable
{
public:
	typedef unsigned int (*hash_func)(void*,int,int);
	myHashTable(int table_size = MinTableSize,hash_func func = default_hash):_hash_func(func),
			_table_size(table_size) 
	{
		_lists = new TableNode<T>*[_table_size];
		for(int i = 0; i < _table_size; ++i)
		{
			_lists[i] = NULL;
		}
	}
	~myHashTable() { Destory(); }

	void Insert(T value);
	TableNode<T>* Find(T value);
	void Delete(T value);
protected:
	void Destory();
private:
	hash_func _hash_func;
	int _table_size;
	TableNode<T> **_lists;
};

template<typename T>
void myHashTable<T>::Insert(T value)
{
	TableNode<T> *find_node = Find(value);
	if( find_node != NULL )
		return;

	unsigned int index = (*_hash_func)(&value,sizeof(T),_table_size);
	assert(index < _table_size);

	TableNode<T> *pnew_node = new TableNode<T>(value);
	TableNode<T> *bucket_node = _lists[index];
	if( bucket_node == NULL )
	{
		bucket_node = pnew_node;
	}
	else
	{
		pnew_node->_next = bucket_node->_next;
		bucket_node = pnew_node;
	}
}

template<typename T>
TableNode<T>* myHashTable<T>::Find(T value)
{
	unsigned int index = (*_hash_func)(&value,sizeof(T),_table_size);
	assert(index < _table_size);

	TableNode<T> *bucket_node = _lists[index];

	while( bucket_node != NULL && bucket_node->_value != value )
	{
		bucket_node = bucket_node->_next;
	}
	return bucket_node;
}

template<typename T>
void myHashTable<T>::Delete(T value)
{
	TableNode<T> *cur = NULL,*pre = NULL;
	TableNode<T> *bucket;
	
	unsigned int index = (*_hash_func)(&value,sizeof(T),_table_size);
	assert(index < _table_size);
	bucket = _lists[index];

	if( bucket == NULL )
		return;

	cur = bucket->_next;
	pre = bucket;
	while( cur != NULL && cur->_value != value )
	{
		pre = cur;
		cur = cur->_next;
	}
	if( cur != NULL )
	{
		pre = cur->_next;
		delete cur;
		cur = NULL;
	}
}

template<typename T>
void myHashTable<T>::Destory()
{
	TableNode<T> *bucket = NULL,*ptmp = NULL;
	for( int i = 0; i < _table_size; ++i )
	{
		bucket = _lists[i];
		while( bucket != NULL )
		{
			ptmp = bucket->_next;
			delete bucket;
			bucket = ptmp;
		}
	}
	delete[] _lists;
}

#endif /* __MYHASH_H */