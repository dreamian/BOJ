#include <cstdio>
#include <vector>
using namespace std;

int min(int i, int j, int k){
    i=i<j?i:j;
    i=i<k?i:k;
    return i;
}

int b;
int key;

int search(vector<int> &v, int idx,int n,int sum){
    // Base case
    if(sum>=b) return sum-b;
    

    if(idx<n){
    // Recursive
        key=min(key,search(v,idx+1,n,sum+v[idx]));
        key=min(key,search(v,idx+1,n,sum));
    }
    return key;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){
        int n;
        scanf("%d %d",&n,&b);
        vector<int> v(n);
        int sum=0;
        key=(1 << 30);

        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            if(a==b) {printf("#%d %d\n",test,0); return 0;}
            v[i]=a;
        }

        int ans=search(v,0,n,sum);
        printf("#%d %d\n",test,ans);
    }
}