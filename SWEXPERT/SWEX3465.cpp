#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll sum;

struct node{
    struct node* next;
    int val;
    int size;
    int head;
    int tail;
};

struct P{
    int boss;
    int son_size;
    int depth;
    node* mass;
    P () : boss(-1), son_size(0), mass(NULL), depth(0) {}
};

inline void update_db(int i, vector<P> &worker){
    int val_, boss;
    node* A=new node;
    A->head=i;
    A->tail=i;
    A->size=1;
    if(i==0){
        scanf("%d",&val_);
        A->val=val_;
        A->next=NULL;
    }
    else{
        scanf("%d %d",&val_,&boss);
        worker[i].boss=boss;
        A->val=val_;
        A->next=worker[boss].mass;
        worker[i].depth=worker[boss].depth+1;
        ++worker[boss].son_size;
    }
    worker[i].mass=A;
}

inline void split_test(int i, vector<P> &worker){
    // 해당 직원의 상사의 집단의 첫 번째가 그 상사를 참조하는 경우는 예외 처리
    if(worker[worker[i].boss].mass->head==worker[i].boss) return;
    // 그 외의 경우는 (boss 이전 노드) (boss 포함 이후 노드)의 두 집단으로 나눈다
    int head_depth=worker[worker[worker[i].boss].mass->head].depth;
    int boss_depth=worker[worker[i].boss].depth;
    int tail_depth=worker[worker[worker[i].boss].mass->tail].depth;
    /// boss 이전 노드
    node* A=new node;
    A->val=worker[worker[i].boss].mass->val;
    A->size=head_depth-boss_depth;
    A->next=worker[worker[i].boss].mass;
    A->head=worker[worker[i].boss].mass->head;
    for(int ii=head_depth, j=worker[worker[i].boss].mass->head;ii>boss_depth;--ii){
        worker[j].mass=A;
        if(worker[j].boss==worker[i].boss) A->tail=j;
        j=worker[j].boss;
    }

    // boss 이후 노드 (원래 노드 활용)
    worker[worker[i].boss].mass->size=tail_depth-boss_depth+1;
    worker[worker[i].boss].mass->head=worker[i].boss;

}

inline void merge_test(int i, vector<P> &worker){
    int prev=i;
    int next=worker[i].boss;
    while(worker[prev].mass->val > worker[next].mass->val){
        sum+=worker[next].mass->size;
        worker[next].mass->val=worker[prev].mass->val;
        int tmp=worker[worker[next].mass->tail].boss;
        // merge test
        if(worker[next].son_size==1){
            // mass 정보 갱신
            worker[prev].mass->tail=worker[next].mass->tail;
            worker[prev].mass->size+=worker[next].mass->size;
            worker[prev].mass->next=worker[next].mass->next;

            node* temp=worker[next].mass;
            int hh=worker[next].mass->head;
            int tt=worker[next].mass->tail;
            while(1){
                worker[hh].mass=worker[prev].mass;
                if(hh==tt) break;
                hh=worker[hh].boss;
            }
            delete temp;
        }

        prev=next;
        next=tmp;
        // 종료 조건
        if(next==-1) break;
    }

}

inline void delete_node(vector<P> &worker){
    for(int i=0;i<=n;++i){
        node* temp=worker[i].mass;
        if(temp!=NULL){
            temp=NULL;
            delete temp;
        }
    }
}

int main(){
    freopen("sample_input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        sum=0;
        scanf("%d",&n);
        vector<P> worker(n+1);
        // 다슬이
        update_db(0,worker);

        for(int i=1;i<=n;++i){
            update_db(i,worker);
            // 중간 참조의 경우
            split_test(i,worker);
            // 같은 연봉을 갖는 상사들을 merge하고 sum 값을 누적한다
            merge_test(i,worker);
        }
        printf("#%d %lld\n",tc,sum);
        delete_node(worker);
    }
    return 0;
}