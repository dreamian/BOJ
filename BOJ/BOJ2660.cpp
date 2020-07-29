#include <stdio.h>

#define	MAX_NUM	50

int dist[MAX_NUM][MAX_NUM];
int max_dist[MAX_NUM];
int candidate[MAX_NUM];

int main()
{
	int n;
	int min_val = 1e+9;
	int candidate_count = 0;

	for(int i=0;i<MAX_NUM;++i)
	{
		max_dist[i] = -1;

		for(int j=0;j<MAX_NUM;++j)
		{
			if( i == j )
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = 1e+9;
			}
		}
	}

	scanf("%d", &n);
	while(1)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		if(a == -1 && b == -1)
		{
			break;
		}
		dist[a-1][b-1] = 1;
		dist[b-1][a-1] = 1;
	}

	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if ( i == j )
				{
					continue;
				}
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = 0;
		for (int j = 0; j < n; j++) {
			if (mx < dist[i][j]) mx = dist[i][j];
		}
		max_dist[i] = mx;
		min_val = min_val < max_dist[i] ? min_val : max_dist[i];
	}

	for(int i=0;i<n;++i)
	{
		if(max_dist[i] == min_val)
		{
			candidate[candidate_count++] = i;
		}
	}

	printf("%d %d\n", min_val, candidate_count);

	for(int i=0;i<candidate_count;++i)
	{
		printf("%d ", candidate[i] + 1);
	}
	printf("\n");
}
