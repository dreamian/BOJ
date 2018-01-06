#include <cstdio>

int board[2200][2200];
int chk[3]={0,}; // 0->-1 1->0 2->1
int mem=-2;
bool flag;

bool Calc(int x, int y, int size){
    mem=board[x][y];
    flag=true;
        for(int i=x;i<=x+(size/3)-1;i++){
            for(int j=y;j<=y+(size/3)-1;j++){
                if(mem==board[i][j]) continue;
                else {flag=false; break;}
            }
            if(!flag) break;
        }
    return flag;
}

void Search(int x, int y, int size){

        // 1st
        flag=Calc(x,y,size);
        if(!flag) Search(x,y,size/3);
        else chk[mem+1]+=1;

        // 2nd
        flag=Calc(x,y+(size/3),size);
        if(!flag) Search(x,y+(size/3),size/3);
        else chk[mem+1]+=1;

        // 3rd
        flag=Calc(x,y+2*(size/3),size);
        if(!flag) Search(x,y+2*(size/3),size/3);
        else chk[mem+1]+=1;

        // 4th
        flag=Calc(x+(size/3),y,size);
        if(!flag) Search(x+(size/3),y,size/3);
        else chk[mem+1]+=1;

        // 5th
        flag=Calc(x+(size/3),y+(size/3),size);
        if(!flag) Search(x+(size/3),y+(size/3),size/3);
        else chk[mem+1]+=1;

        // 6th
        flag=Calc(x+(size/3),y+2*(size/3),size);
        if(!flag) Search(x+(size/3),y+2*(size/3),size/3);
        else chk[mem+1]+=1;

        // 7th
        flag=Calc(x+2*(size/3),y,size);
        if(!flag) Search(x+2*(size/3),y,size/3);
        else chk[mem+1]+=1;

        // 8th
        flag=Calc(x+2*(size/3),y+(size/3),size);
        if(!flag) Search(x+2*(size/3),y+(size/3),size/3);
        else chk[mem+1]+=1;

        // 9th
        flag=Calc(x+2*(size/3),y+2*(size/3),size);
        if(!flag) Search(x+2*(size/3),y+2*(size/3),size/3);
        else chk[mem+1]+=1;

}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){ // 숫자 정보 저장
        for(int j=1;j<=n;j++){
            scanf("%d",&board[i][j]);
        }
    }

    // test for spliting
    mem=board[1][1];
    flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mem==board[i][j]) continue;
            else {flag=false; break;}
        }
        if(!flag) break;
    }
    if(flag) chk[mem+1]+=1;
    else{
        Search(1,1,n);
    }

    printf("%d\n%d\n%d\n",chk[0],chk[1],chk[2]);

}