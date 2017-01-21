#include <iostream>
#include <cstdlib>
#include "NQueue.h"

using namespace std;

// N皇后问题：回溯法求解

int main(int argc,char *argv[])
{
	int length;
	while( cin >> length )
	{
		NQueue nqueue(length);
		nqueue.BackTrack(0);
		cout << "sum: " << nqueue.sum() << endl;
		nqueue.NBackTrack();
		cout << "sum: " << nqueue.sum() << endl;
	}
	return EXIT_SUCCESS;
}
