#include <stdio.h>

int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        int Answer=0;
		int n,a;
		scanf("%d",&n);
		while(n--){
		    scanf("%d",&a);
		    Answer^=a;
		}
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;
}