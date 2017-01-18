#ifndef __MYLIST_H
#define __MYLIST_H

#include <iostream>

template<typename T>
class listNode
{
public:
  listNode(){};
  ~listNode(){};
  listNode(T value):_value(value),_next(NULL) {}

  T _value;
  struct listNode *_next;
};

template<typename T>
class myList
{
public:
  typedef listNode<T>* pList;

  myList();
  ~myList();

  bool  IsEmpty();
  bool  IsLast(listNode<T>* p);

  listNode<T>* Find(T value);
  listNode<T>* FindPre(T value);

  void  Insert(T value,listNode<T>* position = NULL);

  void  Delete(T value);

  void  PrintList();

  void  Reverse();
protected:
  void  Destory();
private:
  pList header;
};

template<typename T>
myList<T>::myList()
{
  header = new listNode<T>();
}

template<typename T>
myList<T>::~myList()
{
  Destory();
}

template<typename T>
bool myList<T>::IsEmpty()
{
  return header->_next == NULL;
}

template<typename T>
bool myList<T>::IsLast(listNode<T>* p)
{
  return p->_next == NULL;
}

template<typename T>
listNode<T>* myList<T>::Find(T value)
{
  listNode<T>* pnode = header->_next;
  while( pnode != NULL && pnode->_value != value )
  {
    pnode = pnode->_next;
  }

  return pnode;
}

template<typename T>
listNode<T>* myList<T>::FindPre(T value)
{
  if( header->_next == NULL )
    return NULL;

  listNode<T>* pnode = header;
  
  while( pnode->_next != NULL && pnode->_next->_value != value )
  {
    pnode = pnode->_next;
  }

  return pnode;
}

template<typename T>
void myList<T>::Insert(T value,listNode<T>* position)
{
  if( position == NULL )
  {
    // 默认为头插
    listNode<T>* pnode = new listNode<T>(value);
    pnode->_next = header->_next;
    header->_next = pnode;
  }
  else
  {
    listNode<T>* pnode = new listNode<T>(value);
    pnode->_next = position->_next;
    position->_next = pnode;
  }
}

template<typename T>
void myList<T>::Delete(T value)
{
  listNode<T> *pnode = FindPre(value);
  if( !IsLast(pnode) )
  {
    listNode<T>* delete_pnode = pnode->_next;

    pnode->_next = delete_pnode->_next;

    delete delete_pnode;
    pnode = NULL;
  }
}

template<typename T>
void myList<T>::Destory()
{
  listNode<T> *pnode,*ptmp;
  pnode = header->_next;

  header->_next = NULL;

  while(pnode != NULL )
  {
    ptmp = pnode->_next;
    delete pnode;
    pnode = ptmp;
  }
}

template<typename T>
void  myList<T>::PrintList()
{
  listNode<T>* pnode = header->_next;
  while( pnode != NULL )
  {
    std::cout << pnode->_value << " ";
    pnode = pnode->_next;
  }
  std::cout  << std::endl;
}

template<typename T>
void  myList<T>::Reverse()
{
  if( header->_next == NULL || header->_next->_next == NULL )
    return;
  listNode<T> *pnode = header->_next;
  listNode<T> *next_node,*pre_node;
  next_node = pnode->_next;
  pre_node = NULL;
  
  while( next_node != NULL )
  {
    pnode->_next = pre_node;
    pre_node = pnode;
    pnode = next_node;
    next_node = next_node->_next;
  }
  
  pnode->_next = pre_node;
  header->_next = pnode;
}

#endif /* __MYLIST_H */
