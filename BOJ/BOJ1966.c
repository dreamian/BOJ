#include <stdio.h>

int main(void){
    int t=0;
    scanf("%d",&t);
    while(t--){
        int queue[1001]={0};
        int chk[1001]={0};
        int n=0,m=0;
        scanf("%d %d",&n,&m); 
        chk[m]=1;
        int head=0, tail=n-1;
        int cnt=0;

        for(int i=0;i<n;i++){scanf("%d",&queue[i]);getchar();}
        while(head<=tail){
            if (head==tail) {cnt++; if(chk[head]==1) head++; printf("%d\n",cnt); break;}

            for(int i=head+1;i<=tail;i++){
                if(queue[head]<queue[i]) { chk[tail+1]=chk[head];
                                            queue[++tail]=queue[head++]; i=head;}
            }
            if(chk[head]==1) {printf("%d\n",++cnt); break;}
                       else  {cnt++; head++;}
        }
        
    }    
}