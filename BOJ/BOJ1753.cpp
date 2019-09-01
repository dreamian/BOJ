#include <stdio.h>

#define   EDGE_MAX    300000
#define   VERTEX_MAX  20000
#define   INF         1e+9

int dist[VERTEX_MAX + 1];

struct Edge
{
  int dest;
  int weight;
  Edge* next;
};
Edge edge[EDGE_MAX];
int eCnt;

struct AdjList
{
  Edge* head;
};
AdjList adj[VERTEX_MAX + 1];

struct Pair
{
  int v;
  int d;
};

void _swap(Pair *i, Pair *j)
{
  Pair temp;
  temp.d = i->d;
  temp.v = i->v;

  i->d = j->d;
  i->v = j->v;

  j->d = temp.d;
  j->v = temp.v;

  return;
}

struct P_QUE
{
  int size;
  const int root = 1;
  Pair arr[EDGE_MAX + 1];

  void push(Pair elem)
  {
    arr[++size] = elem;

    int son_idx = size;

    while(son_idx != root)
    {
      int par_idx = son_idx >> 1;

      if(arr[par_idx].d > arr[son_idx].d)
      {
        _swap(&arr[par_idx], &arr[son_idx]);
        son_idx >>= 1;
      }
      else
      {
        break;
      }
    }
  }
  Pair pop()
  {
    Pair ret = arr[root];

    arr[root] = arr[size--];

    int par_idx = root;

    while( (par_idx << 1) <= size )
    {
      int son_idx = (par_idx << 1);

      if(son_idx + 1 <= size)
      {
        if(arr[son_idx+1].d < arr[son_idx].d)
        {
          ++son_idx;
        }
      }

      if(arr[par_idx].d > arr[son_idx].d)
      {
        _swap(&arr[par_idx], &arr[son_idx]);
        par_idx = son_idx;
      }
      else
      {
        break;
      }
    }

    return ret;
  }
  bool IsEmpty()
  {
    if(size == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
P_QUE p_que
{
  .size = 0,
};

void make_Edge(int _u, int _v, int _w)
{
  edge[eCnt].dest = _v;
  edge[eCnt].weight = _w;

  edge[eCnt].next = adj[_u].head;
  adj[_u].head = &edge[eCnt];
  ++eCnt;
}

int main()
{
  int v, e, k;
  //scanf("%d", &t);
  //for(int tc=1;tc<=t;++tc)
  //{
    scanf("%d %d", &v, &e);
    scanf("%d", &k);
    // init
    for(int i=1;i<=v;++i)
    {
      dist[i] = INF;
    }
    eCnt = 0;
    for(int i=1;i<=v;++i)
    {
      adj[i].head = 0;
    }

    // get edge info.
    for(int i=0;i<e;++i) 
    {
      int _u, _v, _w;
      scanf("%d %d %d", &_u, &_v, &_w);
      make_Edge(_u, _v, _w);
    }

    // process
    p_que.push({k, 0});

    while(!p_que.IsEmpty())
    {
      Pair it = p_que.pop();
      if(it.d < dist[it.v])
      {
        dist[it.v] = it.d;

        Edge* iter = adj[it.v].head;

        while(iter != 0)
        {
          int _d = dist[it.v] + iter->weight;
          if(_d < dist[iter->dest]){
            p_que.push({iter->dest, _d});
          }
          iter = iter->next;
        }
      }
    }

    // print output
    for(int i=1;i<=v;++i)
    {
      if(dist[i] == INF)
      {
        printf("INF\n");
      }
      else
      {
        printf("%d\n", dist[i]);
      }
    }
  //}
}
