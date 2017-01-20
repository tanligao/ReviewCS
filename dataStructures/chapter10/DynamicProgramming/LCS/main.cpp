#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 * 最长公共子序列求解：动态规划
 * @str1：序列1
 * @str2: 序列2
 * @b： 用来存储c[i][j]的来源
 * @c： 动态规划存储
 */
void LCSLength(string &str1,string &str2,int **b,int **c)
{
   int i,j;
   int size_str1 = str1.size();
   int size_str2 = str2.size();

   for(i = 0; i < size_str1+1; ++i)
     c[i][0] = 0;
   for(j = 0; j < size_str2+1; ++j)
     c[0][j] = 0;

   for(i = 1; i < size_str1+1; ++i)
   {
     for(j = 1; j < size_str2+1; ++j)
     {
       if( str1[i-1] == str2[j-1] )
       {
         b[i][j] = 1;
         c[i][j] = c[i-1][j-1] + 1;
       }
       else if( c[i-1][j] > c[i][j-1] )
       {
         b[i][j] = 2;
         c[i][j] = c[i-1][j];
       }
       else
       {
         b[i][j] = 3;
         c[i][j] = c[i][j-1];
       }
     }
   }
}

void LCS(int **b,string &str1,int x,int y)
{
  if( x == 0 || y == 0 )
    return;

  if( b[x][y] == 1 )
  {
    LCS(b,str1,x-1,y-1);
    cout << str1[x-1];
  }
  else if( b[x][y] == 2 )
  {
    LCS(b,str1,x-1,y);
  }
  else
  {
    LCS(b,str1,x,y-1);
  }
}

int main(int argc,char *argv[])
{
  cout << "input two string: ";

  string str1,str2;
  cin >> str1 >> str2;

  int size_str1,size_str2;
  size_str1 = str1.size();
  size_str2 = str2.size();

  int **b,**c;
  b = new int*[size_str1+1];
  c = new int*[size_str1+1];
  for(int i = 0; i < size_str1+1; ++i)
  {
    b[i] = new int[size_str2+1];
    c[i] = new int[size_str2+1];
  }

  LCSLength(str1,str2,b,c);
  LCS(b,str1,size_str1,size_str2);

  cout << endl;

  for(int i = 0; i < size_str1+1; ++i)
  {
    delete[] b[i];
    delete[] c[i];
  }

  delete[] b;
  delete[] c;

  return EXIT_SUCCESS;
}
