#include <iostream>
#include <stdlib.h>
#include "myQueue.h"

using namespace std;

int main(int argc,char *argv[])
{
	myQueue<int> queue;
	for( int i = 0; i < 10; ++i )
	{
		queue.Enqueue(i);
	}
	queue.Dequeue();
	for( int i = 0; i < 9; ++i )
	{
		cout << queue.FrontAndDequeue() << " ";
	}
	cout << endl;
  return EXIT_SUCCESS;
}
