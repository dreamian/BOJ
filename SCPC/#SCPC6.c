#include <stdio.h>

typedef long long ll;

ll simul(int x,int y,int n){
    int line=x+y-1;
    ll ans;
    if(line<=n){
        if(line%2==0){
            ans=(line*(line-1)/2)+x;
        }
        else{
            ans=(line*(line-1)/2)+y;
        }
    }
    else{
        x=n+1-x;
        y=n+1-y;
        line=x+y-1;
        if(line%2==0){
            ans=(line*(line-1)/2)+x;
        }
        else{
            ans=(line*(line-1)/2)+y;
        }
        ans=n*n-ans+1;
    }
    return ans;
}

int main(void)
{
	int T, test_case;
     setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		ll ans=1;
		int n,k;
        int x=1, y=1;
        scanf("%d %d\n",&n,&k);
        for(int i=0;i<k;i++){
            char func;
            scanf("%c\n",&func);
            if(func=='U'){
                x--;
                ans+=simul(x,y,n);
            }
            else if(func=='D'){
                x++;
                ans+=simul(x,y,n);
            }
            else if(func=='L'){
                y--;
                ans+=simul(x,y,n);
            }
            else if(func=='R'){
                y++;
                ans+=simul(x,y,n);
            }

        }
        


		printf("Case #%d\n", test_case+1);
        printf("%lld\n", ans);
        
	}

	return 0;
}