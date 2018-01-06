#include <stdio.h>
#include <math.h>
#define pi 3.141592

int score[20]={6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10};

int main(void){
	int T, test_case;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        a=a*a; b=b*b; c=c*c; d=d*d; e=e*e;
        int n;
        scanf("%d",&n);
        int ans=0;
        double x,y;
        while(n--){
            int org=0;
            scanf("%lf%lf",&x,&y);
            double len=x*x+y*y;
            double deg=atan2(y,x)*180/pi;
            if(deg<0){
                deg+=360;
            }
            int num=((deg+9)/18);
            num%=20;
            org=score[num];

            if(0<=len && len<a){
                org=50;
            }
            else if(b<len && len<c){
                org*=3;
            }
            else if(d<len && len<e){
                org*=2;
            }
            else if(e<len){
                org=0;
            }
            ans+=org;
            
        }
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", ans);
        
	}

	return 0;
}