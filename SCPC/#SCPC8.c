#include <stdio.h>
#include <memory.h>

int block[100001];

int min(int i, int j){
    return i<j?i:j;
}
int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        int n;
        scanf("%d",&n);
        int max=1;
        memset(block,0,sizeof(block));

        for(int i=0;i<n;i++){
            scanf("%d",&block[i+1]); // 높이 정보 저장
        }

        for(int i=1;i<=n;i++){
            block[i]=min(block[i-1]+1,block[i]);
        }
        
        for(int i=n;i>=1;i--){
            block[i]=min(block[i+1]+1,block[i]);
            max=max>block[i]?max:block[i];
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", max);
        
	}

	return 0;
}