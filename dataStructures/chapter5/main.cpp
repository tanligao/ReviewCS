#include <iostream>
#include <stdlib.h>
#include "myHash.h"

using namespace std;

int main(int argc,char *argv[])
{
	myHashTable<int> hash;
	for( int i = 0; i < 20; ++i )
	{
		hash.Insert(i);
	}
	hash.Delete(13);
	TableNode<int> *find_node = hash.Find(13);
	if( find_node == NULL )
		cout << "not exsit" << endl;
	else
		cout << "exsit" << endl;
	
	return EXIT_SUCCESS;
}