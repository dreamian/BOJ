#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int n, m, k, tar_recept, tar_repair;
int res;

int recept_time[9];
int recept_desk[9];
int repair_time[9];
int repair_desk[9];

struct Z{
    int num;
    int time;
    int used_desk;
};

bool cmp_recept(const Z &i, const Z &j){
    if(i.time==j.time) return i.num < j.num;
    else return i.time < j.time;
}

bool cmp_repair(const Z &i, const Z &j){
    if(i.time==j.time) return i.used_desk < j.used_desk;
    else return i.time < j.time;
}

int main(){
    //freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        res=0;
        scanf("%d%d%d%d%d",&n,&m,&k,&tar_recept,&tar_repair);
        vector<Z> customer(k);
        for(int i=0;i<n;++i){
            scanf("%d",&recept_time[i]);
            recept_desk[i]=0;
        }
        for(int i=0;i<m;++i){
            scanf("%d",&repair_time[i]);
            repair_desk[i]=0;
        }
        for(int i=0;i<k;++i){
            customer[i].num=i+1;
            scanf("%d",&customer[i].time);
        }

        // In reception desk,
        sort(customer.begin(),customer.end(),cmp_recept);
        
        // first : time, second : desk #
        pii tar;

        for(int i=0;i<k;++i){
            bool get_desk=false;
            tar=mp(1e+9,-1);
            for(int j=0;j<n;++j){
                if(recept_desk[j]<=customer[i].time){
                    recept_desk[j]=customer[i].time+recept_time[j];
                    customer[i].time=recept_desk[j];
                    customer[i].used_desk=j+1;
                    get_desk=true;
                    break;
                }
                else{
                    if(tar.first>recept_desk[j]) tar=mp(recept_desk[j],j);  
                }
            }
            if(!get_desk){
                recept_desk[tar.second]+=recept_time[tar.second];
                customer[i].time=recept_desk[tar.second];
                customer[i].used_desk=tar.second+1;
            }
        }

        // in repair desk,

        sort(customer.begin(),customer.end(),cmp_repair);

        // first : time, second : desk #

        for(int i=0;i<k;++i){
            bool get_desk=false;
            tar=mp(1e+9,-1);
            for(int j=0;j<m;++j){
                if(repair_desk[j]<=customer[i].time){
                    repair_desk[j]=customer[i].time+repair_time[j];
                    get_desk=true;
                    if(customer[i].used_desk==tar_recept && j+1==tar_repair) res+=customer[i].num;
                    break;
                }
                else{
                    if(tar.first>repair_desk[j]) tar=mp(repair_desk[j],j);  
                }
            }
            if(!get_desk){
                repair_desk[tar.second]+=repair_time[tar.second];
                if(customer[i].used_desk==tar_recept && tar.second+1==tar_repair) res+=customer[i].num;
            }
        }

        if(res==0) --res;
        printf("#%d %d\n",tc,res);
    }
    return 0;
}