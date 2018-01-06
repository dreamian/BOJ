#include <stdio.h>

int main(void)
{
	int T, test_case;

    freopen("input.txt","r",stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{   int sum[400001]={0,};
        int cnt=0;
		int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);

            for(int k=0;k<i;k++){
                if(sum[arr[i]-arr[k]+200000]==1) 
                {cnt++; break;}
            }

            sum[2*arr[i]+200000]=1;

            for(int j=0;j<i;j++){ // 두 개의 항을 각각 더한 값을 sum에 저장
                sum[arr[i]+arr[j]+200000]=1;
            }


        }
		
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", cnt);
        
	}

	return 0;
}