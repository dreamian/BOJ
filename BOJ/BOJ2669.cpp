#include <stdio.h>

#define LEN_MAX	101

bool check[LEN_MAX][LEN_MAX];

int main()
{
	int ans = 0;
	int cnt = 4;
	int ax, ay, bx, by;
	while(cnt--)
	{
		scanf("%d %d %d %d", &ax, &ay, &bx, &by);
		for(int i = ax; i<bx; ++i)
		{
			for(int j= ay; j<by; ++j)
			{
				if(check[i][j]) continue;
				check[i][j] = true;
				++ans;
				//printf("DEB %d\n", ans);
			}
		}
	}

	printf("%d\n", ans);
}
