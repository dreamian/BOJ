#include <stdio.h>

#define MAX_QUE_LEN  51

struct C_QUE
{
  int front;
  int rear;
  int ans;
  int arr[MAX_QUE_LEN];

  void init(int n)
  {
    front = rear = ans = 0;
    for(int i=0;i<n;++i)
    {
      push_back(i+1);
    }
  }

  void push_front(int x)
  {
    front = (front + MAX_QUE_LEN - 1)%(MAX_QUE_LEN);
    arr[front] = x;
  }
  void push_back(int x)
  {
    arr[rear] = x;
    rear = (rear+1)%MAX_QUE_LEN;
  }

  int pop_front()
  {
    int ret = arr[front];

    front = (front + 1)%MAX_QUE_LEN;

    return ret;
  }
  int pop_back()
  {
    rear = (rear - 1 + MAX_QUE_LEN)%MAX_QUE_LEN;
    return arr[rear];
  }

  int get_ldist(int tar)
  {
    int idx = front;
    //printf("arr[front] = %d\n", arr[front]);
    int cnt = 0;
    for(;; idx = (idx + 1)%MAX_QUE_LEN, ++cnt)
    {
      if(arr[idx] == tar)
      {
        break;
      }
    }

    return cnt;
  }

  int get_rdist(int tar)
  {
    int idx = (rear - 1 + MAX_QUE_LEN)%MAX_QUE_LEN;
    int cnt = 0;
    for(;; idx = (idx - 1 + MAX_QUE_LEN)%MAX_QUE_LEN, ++cnt)
    {
      if(arr[idx] == tar)
      {
        break;
      }
    }

    return cnt + 1;
  }

  void process(int tar)
  {
    int ldist = get_ldist(tar);
    int rdist = get_rdist(tar);

    //printf("ldist: %d, rdist: %d\n", ldist, rdist);

    if(ldist < rdist)
    {
      ans += ldist;
      while(ldist--)
      {
        push_back(pop_front());
      }
    }
    else
    {
      ans += rdist;
      while(rdist--)
      {
        push_front(pop_back());
      }
    }
	int ret = pop_front();
	if(ret != tar)
	{
		while(1)
		{
			printf("Err!\n");
		}
	}
  }
};
C_QUE que;

int main()
{
  int n, m;
  scanf("%d%d",&n,&m);
  que.init(n);
  for(int i=0;i<m;++i)
  {
    int tar;
    scanf("%d", &tar);
    que.process(tar);
  }
  printf("%d\n", que.ans);
}
