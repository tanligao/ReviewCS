#include <iostream>
#include <stdlib.h>
#include "myStack.h"

using namespace std;

int main(int argc,char *argv[])
{
	myStack<int> stack;
	for( int i = 0; i < 10; ++i )
	{
		stack.Push(i);
	}
	stack.Pop();
	cout << stack.Top() << endl;
  return EXIT_SUCCESS; 
}
