#include <iostream>
#include <stdlib.h>
#include <string>

#define MAX_DOUBLE 65534.99999

using namespace std;

typedef struct
{
  double weight;
  int parent;
  int lchild,rchild;
} HtNode;

typedef struct
{
  HtNode *nodes;
  int root;
} HtTree;

/*
 * 哈夫曼编码树生成：总共需要2*n-1个结点存储，
 * 每次选取最小的两个结点组合成新的结点放到n+i位置
 * @weight：权重数组
 * @n：数组元素个数
 */
HtTree* Huffman(double weight[],int n)
{
  HtTree *ht = new HtTree();
  ht->nodes = new HtNode[2*n-1];

  for(int i = 0; i < 2*n-1; ++i)
  {
    if( i < n )
    {
      ht->nodes[i].weight = weight[i];
    }
    else
    {
      ht->nodes[i].weight = 0;
    }
    ht->nodes[i].parent = 0;
    ht->nodes[i].lchild = 0;
    ht->nodes[i].rchild = 0;
  }
  int min1,min2,min1_index,min2_index;
  for(int i = 0; i < n - 1; ++i)
  {
    min1 = MAX_DOUBLE;
    min2 = MAX_DOUBLE;
    min1_index = 0;
    min2_index = 0;
    for(int j = 0; j < n + i; ++j)
    {
      if( ht->nodes[j].parent == 0 )
      {
        if( ht->nodes[j].weight < min1 )
        {
          min2 = min1;
          min2_index = min1_index;
          min1 = ht->nodes[j].weight;
          min1_index = j;
        }
        else if( ht->nodes[j].weight < min2 )
        {
          min2 = ht->nodes[j].weight;
          min2_index = j;
        }
      }
    }
    ht->nodes[n+i].weight = min1 + min2;
    ht->nodes[n+i].lchild = min1_index;
    ht->nodes[n+i].rchild = min2_index;
    ht->nodes[min1_index].parent = n + i;
    ht->nodes[min2_index].parent = n + i;
  }
  ht->root = 2*n - 2;
  return ht;
}

/*
 * 哈夫曼编码生成函数，根据孩子结点与父结点之间的关系，知道父结点为root
 * @codes：编码存储数组
 * @n：数组元素个数
 * @ht：哈夫曼树
 */
void HuffmanCode(string *codes,int n,HtTree *ht)
{
  for(int i = 0; i < n; ++i)
  {
    int cur = i;
    int parent = ht->nodes[i].parent;
    // 当到达root时，parent为0
    while( parent != 0 )
    {
      if( ht->nodes[parent].lchild == cur )
      {
        codes[i] = '0' + codes[i];
      }
      else
      {
        codes[i] = '1' + codes[i];
      }
      cur = parent;
      parent = ht->nodes[parent].parent;
    }
  }
}

int main(int argc,char *argv[])
{
  char str[] = {'a','b','c','d','e','f','g','h'};
  double weight[] = {5,29,7,8,14,23,3,11};

  int length = sizeof(weight)/sizeof(*weight);
  string *hc = new string[length];

  HtTree *ht = Huffman(weight,length);
  HuffmanCode(hc,length,ht);

  for(int i = 0; i < length; ++i)
  {
    cout << str[i] << " : " << hc[i] << endl; 
  }

  delete[] ht->nodes;
  delete ht;
  delete[] hc;
  return EXIT_SUCCESS;
}
