#include <stdio.h>

#define ARR_ELEMENT_MAX	101

// -1 : no cycle, 0 : not checked, 1 : cycle
int cycle[ARR_ELEMENT_MAX];
bool visit[ARR_ELEMENT_MAX];

int arr[ARR_ELEMENT_MAX];
int ans;

void _process(int node)
{
	int next = arr[node];

	// visit check
	visit[node] = true;

	if(cycle[node] != 0)
	{
		return;
	}

	// cycle found
	if(visit[next] && cycle[next] == 0)
	{
		int start = next;

		while(1)
		{
			++ans;
			cycle[start] = 1;
			start = arr[start];
			if(start == next)
			{
				break;
			}
		}

		return;
	}

	// continue process if cycle was not found.
	_process(next);

	if(cycle[node] == 0)
	{
		cycle[node] = -1;
	}
	return;
}

int main()
{
	int n;
	ans = 0;
	scanf("%d", &n);

	// get array information
	for(int i=1;i<=n;++i)
	{
		int tar;
		scanf("%d", &tar);
		arr[i] = tar;
	}

	// process
	for(int i=1;i<=n;++i)
	{
		if(cycle[i] != 0)
		{
			continue;
		}
		_process(i);
	}

	printf("%d\n", ans);
	for(int i=1;i<=n;++i)
	{
		if(cycle[i] == 1)
		{
			printf("%d\n", i);
		}
	}
}
