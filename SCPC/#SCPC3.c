#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second){
    if(*(int*)first>*(int*)second){
        return -1;
    }
    else if(*(int*)first<*(int*)second){
        return 1;
    }
    else return 0;
}

int main(void)
{
	int T, test_case;

	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int n,k;
        int ans=0;
        scanf("%d %d",&n,&k);
        int* arr=(int *)malloc(sizeof(int)*n);

        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        qsort(arr,n,sizeof(int),compare);
        
        for(int j=0;j<k;j++){
            ans+=arr[j];
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", ans);
        free(arr);
	}

	return 0;
}