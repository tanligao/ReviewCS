#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;

// 用于测试chapter2的代码

// 计算n的阶乘
long int Factorial(int n)
{
  if( n <= 1 )
  {
    return 1;
  }
  else
  {
    return n * Factorial(n - 1);
  }
}

// 计算Fib数列第n项
long int Fib(int n)
{
  if( n <= 1 )
    return 1;
  else
    return Fib(n - 1) + Fib(n - 2 );
}

// 计算最大子序列和,复杂度为O(N^2)
int MaxSubSequenceSum(vector<int> &vec)
{
  int max_sum = 0;
  int this_sum = 0;
  vector<int>::iterator it1,it2;
  for( it1 = vec.begin(); it1 != vec.end(); ++it1 )
  {
    this_sum = 0;
    for( it2 = it1; it2 != vec.end(); ++it2 )
    {
      this_sum += *it2;
      if( this_sum > max_sum )
        max_sum = this_sum;
    }
  }
  return max_sum;
}

int MaxSubSum(vector<int> &vec,int left,int right)
{
  int max_left_sum,max_right_sum;
  int max_left_border_sum,max_right_border_sum;
  int left_border_sum,right_border_sum;

  int middle,i;
  if( left >= right )
  {
    if( vec[left] > 0 )
      return vec[left];
    else
      return 0;
  }

  middle = left + (right - left ) / 2;
  max_left_sum = MaxSubSum(vec,left,middle);
  max_right_sum = MaxSubSum(vec,middle + 1,right);

  max_left_border_sum = 0;
  left_border_sum = 0;
  for( i = middle; i >= left; --i )
  {
    left_border_sum += vec[i];
    if( left_border_sum > max_left_border_sum )
      max_left_border_sum = left_border_sum;
  }

  max_right_border_sum = 0;
  right_border_sum = 0;
  for( i = middle + 1; i <= right; ++i )
  {
    right_border_sum += vec[i];
    if( right_border_sum > max_right_border_sum )
      max_right_border_sum = right_border_sum;
  }

  return max(max_left_border_sum + max_right_border_sum,max(max_right_sum,max_left_sum));
}

// 计算最大子序列和,复杂度为O(NlogN),运用分治和递归的思想
// 分治的最大子序列和分为3种情况：1.左边部分的最大子序列的和
// 2.右边部分的最大子序列的和，3.左边包含最后一个元素与右边包含
// 第一个元素的最大和的和
int MaxSubSequenceSum1(vector<int> &vec)
{
  return MaxSubSum(vec,0,vec.size() - 1 );
}

// 计算最大子序列和,复杂度为O(N)
int MaxSubSequenceSum2(vector<int> &vec)
{
  int this_sum = 0;
  int max_sum = 0;
  for( int i = 0 ; i < vec.size() ; ++i )
  {
    this_sum += vec[i];
    if( this_sum > max_sum )
      max_sum = this_sum;
    else if( this_sum < 0 )
      this_sum = 0;
  }
  return max_sum;
}

// 二分查找
int BinarySearch(vector<int> &vec,int search_num)
{
  int low,mid,high;
  low = 0;
  high = vec.size() - 1;
  while( low < high )
  {
    mid = low + (high - low) / 2;
    if( search_num > vec[mid] )
    {
      low = mid + 1;
    }
    else if( search_num < vec[mid] )
    {
      high = mid;
    }
    else
      return mid;
  }
  return -1;
}

// 欧几里得算法求最大公因数
int Gcd(unsigned int num1,unsigned int num2)
{
  unsigned int rem;
  while(num2 > 0)
  {
    rem = num1 % num2;
    num1 = num2;
    num2 = rem;
  }
  return num1;
}

// 判断是否为偶数
bool IsEven(int n)
{
  if( n%2 == 0 )
    return true;
  else
    return false;
}

// 求幂运算，如果n为偶数，则为num^n = num^(n/2) * num^(n/2)
// 若为奇数，则num^n = num^(n/2) * num^(n/2) * num
long int Pow(int num,unsigned int n)
{
  if( n == 0 )
    return 1;
  else if( n == 1 )
    return num;
  if( IsEven(n) )
    return Pow(num * num,n/2);
  else
    return Pow(num * num,n/2) * num;
}

int main(int argc,char *argv[])
{
  //int num;
  //cout << "10! = " << Factorial(10) << endl;
  /*
  while(1)
  {
    cout << "Please input the num: ";
    cin >> num;
    cout << "Fib(" << num << ") = " << Fib(num) << endl;
  }
  */

  /*
  int length,num1;
  cout << "input the array length: ";
  cin >> length;
  cout << "input array: ";

  vector<int> vec;
  for( int i = 0 ; i < length; ++i )
  {
    cin >> num1;
    vec.push_back(num1);
  }

  cout << "MaxSubSequenceSum： " << MaxSubSequenceSum(vec) << endl;
  cout << "MaxSubSequenceSum1: " << MaxSubSequenceSum1(vec) << endl;
  cout << "MaxSubSequenceSum2: " << MaxSubSequenceSum2(vec) << endl;
  */
 
  /*
  int length,num1;
  cout << "input the array length: ";
  cin >> length;
  cout << "input sorted array: ";

  vector<int> vec;
  for( int i = 0 ; i < length; ++i )
  {
    cin >> num1;
    vec.push_back(num1);
  }

  while(1)
  {
    int num2;
    cout << "input the search_num: ";
    cin >> num2;
    cout << "search result: " << BinarySearch(vec,num2) << endl;
  }
  */

  /*
  int num1,num2;
  cout << "input two num: ";

  cin >> num1 >> num2;
  cout << "two num gcd: " << Gcd(num1,num2) << endl;
  */

  int num1,num2;
  cout << "input two num: ";

  cin >> num1 >> num2;
  cout << num1 << "^" << num2 << ": " << Pow(num1,num2) << endl;

  return EXIT_SUCCESS;
}
