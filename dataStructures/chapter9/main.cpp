#include <iostream>
#include <stdlib.h>
#include <vector>

#define MAX_VALUE 65535

/*
   65535 8 32 65535 65535
   12 65535 16 15 65535
   65535 29 65535 65535 13
   65535 21 65535 65535 7
   65535 65535 27 19 65535
   */

using namespace std;

/* Dijkstra算法（单源最短路径算法）:时间复杂度O(N^2),空间复杂度O(N)
 * @n：顶点个数
 * @u：源点
 * @dist：最短路径长度
 * @p：最短路径
 * @c：带权邻接矩阵
 */
void Dijkstra(int n,int u,int dist[],int p[],vector<vector<int> > &c)
{
  bool s[n];
  for(int i = 0; i < n; ++i)
  {
    dist[i] = c[u][i];
    if( dist[i] == MAX_VALUE )
      p[i] = -1;
    else
      p[i] = u;

    s[i] = false;
  }
  dist[u] = 0;
  s[u] = true;

  for(int i = 0; i < n; ++i)
  {
    int tmp = MAX_VALUE,t = u;
    for(int j = 0; j < n; ++j)
    {
      if( !s[j] && dist[j] < tmp )
      {
        t = j;
        tmp = dist[j];
      }
    }

    if( t == u )
      break;

    s[t] = true;
    for(int j = 0; j < n; ++j)
    {
      if( !s[j] && c[t][j] < MAX_VALUE )
      {
        if( dist[j] > dist[t] + c[t][j] )
        {
          dist[j] = dist[t] + c[t][j];
          p[j] = t;
        }
      }
    }
  }
}

void PrintMin(int des,int p[])
{
  if( p[des] != -1 )
  {
    PrintMin(p[des],p);
  }
  cout << " " << des << " ";
}

int main(int argc,char *argv[])
{
  vector<vector<int> > vec;
  int num;
  for(int i = 0; i < 5; ++i)
  {
    vector<int> tmpvec;
    for(int j = 0; j < 5; ++j)
    {
      cin >> num;
      tmpvec.push_back(num);
    }
    vec.push_back(tmpvec);
  }

  int p[5];           //记录路径前缀
  int dist[5];      //记录最短路径
  Dijkstra(5,0,dist,p,vec);

  for(int i = 1; i < 5; ++i)
  {
    cout << 0 << " to " << i << " shortest path: ";
    PrintMin(i,p);
    cout << "shortest length: " << dist[i] << endl;
  }
  return EXIT_SUCCESS;
}

