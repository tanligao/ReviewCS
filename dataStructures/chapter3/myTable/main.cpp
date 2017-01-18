#include <iostream>
#include <stdlib.h>
#include "myList.h"
#include "myDoubleList.h"

using namespace std;

int main(int argc,char *argv[])
{
   myList<int> mylist;
   for( int i = 0; i < 10; ++i )
   {
   	mylist.Insert(i);
   }

   mylist.Delete(5);
   mylist.PrintList();
   mylist.Reverse();
   mylist.PrintList();
   
   myDoubleList<int> mylist1;
   for( int i = 0; i < 10; ++i )
   {
   	mylist1.Insert(i);
   }
   mylist1.PrintList();
   mylist1.Delete(5);
   mylist1.PrintList();

   return EXIT_SUCCESS;
}
