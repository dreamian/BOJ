#include <cstdio>
using namespace std;

int main(){
    int idx=0;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(j==idx) printf("#");
            else printf("+");
        }
        ++idx;
        printf("\n");
    }
}