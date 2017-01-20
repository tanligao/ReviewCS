#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

/*
 * 最长递增子序列：动态规划
 * @vec_num： 存放所有数组元素
 * @vec_dp： 动态规划数组
 * return_value：返回动态规划后中dp数组中最大元素的下标
 */
void LongestIncSubsequence(vector<int> &vec_num,vector<int> &vec_dp)
{
  int vec_size = vec_num.size();
  for(int i = 0; i < vec_size; ++i)
  {
    vec_dp[i] = 1;
  }

  for(int i = 1; i < vec_size; ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      if( vec_num[i] > vec_num[j] && vec_dp[i] < vec_dp[j] + 1 )
      {
        vec_dp[i] = vec_dp[j] + 1;
      }
    }
  }

  int max_value = vec_dp[0],max_index = 0;

  for(int k = 1; k < vec_size; ++k)
  {
    if( vec_dp[k] > max_value )
    {
      max_index = k;
      max_value = vec_dp[k];
    }
  }

  list<int> print_list;
  print_list.push_front(vec_num[max_index]);
  int cur_num = vec_num[max_index];
  int cur_index = max_index - 1;
  while( max_value > 0 && cur_index > 0)
  {
    if( vec_dp[cur_index] == max_value - 1 )
    {
      print_list.push_front(vec_num[cur_index]);
      --max_value;
    }
    --cur_index;
  }

  cout << "Longest length: " << vec_dp[max_index] << " Sub sequence: ";
  for(list<int>::iterator it = print_list.begin(); it != print_list.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

int main(int argc,char *argv[])
{
  vector<int> vec_num;

  int num;
  while( cin >> num )
    vec_num.push_back(num);

  vector<int> vec_dp(vec_num.size());

  LongestIncSubsequence(vec_num,vec_dp);

  return EXIT_SUCCESS;
}
