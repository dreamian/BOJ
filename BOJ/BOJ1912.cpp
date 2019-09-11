#include <stdio.h>

#define ARR_MAX_LEN 100000

int arr[ARR_MAX_LEN];
int ans;

int main()
{
	int n;
	scanf("%d", &n);

	for(int i=0; i<n;++i)
	{
		scanf("%d", &arr[i]);
	}
	ans = arr[0];

	for(int i=1;i<n;++i)
	{
		if(arr[i-1] + arr[i] > arr[i])
		{
			arr[i] += arr[i-1];
		}
		
		ans = ans < arr[i] ? arr[i] : ans;
	}

	printf("%d\n", ans);
}
