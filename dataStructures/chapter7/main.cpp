#include <iostream>
#include <stdlib.h>
#include <time.h>

// 复习排序算法

using namespace std;

// 输出数组所有元素
void PrintArray(int array[],int array_length)
{
  for(int i = 0; i < array_length; ++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

// 完美洗牌算法，用于每个排序后打乱数组元素
void PerfectShuffle(int array[],int array_length)
{
  int index,tmp;
  srand(time(NULL));
  for( int i = 0; i < array_length; ++i )
  {
    index = i + rand()%(array_length-i);
    tmp = array[i];
    array[i] = array[index];
    array[index] = tmp;
  }
}

// 选择排序：每次把最小的放到前面
void SelectSort(int array[],int array_length)
{
  for(int i = 0; i < array_length; ++i)
  {
    int min_value = array[i];
    int min_index = i;
    for(int j = i+1; j < array_length; ++j)
    {
      if( array[j] < min_value )
      {
        min_value = array[j];
        min_index = j;
      }
    }
    swap(array[i],array[min_index]);
  }
}

// 插入排序：数组前面的为有序，后面元素逐个插入
void InsertSort(int array[],int array_length)
{
  int tmp,j;
  for(int i = 1; i < array_length; ++i)
  {
    tmp = array[i];
    for(j = i; j > 0 && array[j-1] > tmp; --j)
    {
      array[j] = array[j-1];
    }
    array[j] = tmp;
  }
}

// 冒泡排序
void BubbleSort(int array[],int array_length)
{
  for(int i = 0; i < array_length; ++i)
  {
    for(int j = 0; j < array_length - i - 1; ++j)
    {
      if( array[j] > array[j+1] )
      {
        swap(array[j],array[j+1]);
      }
    }
  }
}

// 冒泡排序改进，双向冒泡
void DoubleBubbleSort(int array[],int array_length)
{
  int low = 0,high = array_length - 1;
  int k;

  while(low < high)
  {
    for(k = low; k < high; ++k)
    {
      if( array[k] > array[k+1] )
        swap(array[k],array[k+1]);
    }
    for(k = high; k > low; --k)
    {
      if( array[k] < array[k-1] )
        swap(array[k],array[k-1]);
    }
    ++low;
    --high;
  }
}

// 希尔排序
void ShellSort(int array[],int array_length)
{
  int i,j,increment;
  int tmp;

  for( increment = array_length/2; increment > 0; increment/=2 )
  {
    for( i = increment; i < array_length; ++i )
    {
      tmp = array[i];
      for( j = i; j >= increment; j-=increment )
      {
        if( tmp < array[j-increment] )
          array[j] = array[j-increment];
        else
          break;
      }
      array[j] = tmp;
    }
  }

}

// 堆排序辅助函数
void ModifyHeap(int array[],int s,int array_length)
{
  int lchild = 2*s+1,rchild = 2*s+2;

  int max_index = s;
  if( lchild < array_length && array[lchild] > array[max_index] )
  {
    max_index = lchild;
  }
  if( rchild < array_length && array[rchild] > array[max_index] )
  {
    max_index = rchild;
  }

  if( max_index != s )
  {
    swap(array[s],array[max_index]);
    ModifyHeap(array,max_index,array_length);
  }
}

// 建堆
void BuildHeap(int array[],int array_length)
{
  for(int i = (array_length-1)/2; i >= 0; --i)
  {
    ModifyHeap(array,i,array_length);
  }
}

// 堆排序
void HeapSort(int array[],int array_length)
{
  BuildHeap(array,array_length);

  for(int i = array_length-1; i >= 1; --i)
  {
    swap(array[i],array[0]);
    ModifyHeap(array,0,i);
  }
}

// 归并排序辅助函数1
void Merge(int array[],int arraytmp[],int lpos,int rpos,int right_end)
{
  int i,left_end,num_elements,tmp_pos;

  left_end = rpos - 1;
  tmp_pos = lpos;
  num_elements = right_end - lpos + 1;

  while( lpos <= left_end && rpos <= right_end )
  {
    if( array[lpos] <= array[rpos] )
      arraytmp[tmp_pos++] = array[lpos++];
    else
      arraytmp[tmp_pos++] = array[rpos++];
  }

  while( lpos <= left_end )
    arraytmp[tmp_pos++] = array[lpos++];
  while( rpos <= right_end )
    arraytmp[tmp_pos++] = array[rpos++];

  for( i = 0; i < num_elements; ++i,--right_end )
  {
    array[right_end] = arraytmp[right_end];
  }
}

// 归并排序辅助函数2
void Msort(int array[],int arraytmp[],int left,int right)
{
  int mid;
  if( left < right )
  {
    mid = left + (right - left)/2;
    Msort(array,arraytmp,left,mid);
    Msort(array,arraytmp,mid+1,right);
    Merge(array,arraytmp,left,mid+1,right);
  }
}

// 归并排序
void MergeSort(int array[],int array_length)
{
  int *arraytmp;

  arraytmp = new int[array_length];

  Msort(array,arraytmp,0,array_length - 1);

  delete[] arraytmp;
}

// 快速排序
void QuickSort(int array[],int array_length)
{
}

// 桶排序
void BucketSort(int array[],int array_length)
{

}

int main(int argc,char *argv[])
{
  int array_length;
  cout << "input the array length: ";
  cin >> array_length;

  int array[array_length];
  int read_num;
  for( int i = 0; i < array_length; ++i )
  {
    cin >> read_num;
    array[i] = read_num;
  }

  SelectSort(array,array_length);
  cout << "Select sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  InsertSort(array,array_length);
  cout << "Insert sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  BubbleSort(array,array_length);
  cout << "Bubble sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  DoubleBubbleSort(array,array_length);
  cout << "Double bubble sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  ShellSort(array,array_length);
  cout << "Shell sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  HeapSort(array,array_length);
  cout << "Heap sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);
  MergeSort(array,array_length);
  cout << "Merge sort: ";
  PrintArray(array,array_length);

  PerfectShuffle(array,array_length);

  return EXIT_SUCCESS;
}
