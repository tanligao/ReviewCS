#include <iostream>
#include <stdlib.h>

using namespace std;

// Fibonacci数列
int Fibonacci(int N)
{
  int i,last,next_to_last,answer;
  if( N <= 1 )
  {
    return 1;
  }
  
  last = next_to_last = 1;

  for(int i = 2; i <= N; ++i)
  {
    answer = last + next_to_last;
    next_to_last = last;
    last = answer;
  }
  return answer;
}

int main(int argc,char *argv[])
{
  for(int i = 0; i < 20; ++i)
  {
    cout << Fibonacci(i) << " ";
  }
  cout << endl;
  return EXIT_SUCCESS;
}

