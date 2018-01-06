#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int static compare(const void *first, const void *second){
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int n=0;
        scanf("%d",&n);
        int* arr=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        qsort(arr,n,sizeof(int),compare);
        int max=0;

      int ans=0;
        for(int i=0;i<n;i++){
            if (arr[i]+n>=max) ans++;
        }
    

		printf("Case #%d\n", test_case+1);
        printf("%d\n", ans);
        free(arr);

	}

	return 0;
}