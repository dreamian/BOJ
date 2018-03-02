#define N 4
#define NULL 0 

bool chk[10];

typedef struct {
    int strike;
    int ball;
}Result;

struct node{
    struct node* prev;
    struct node* next;
    int info[4];
    node (): prev(NULL), next(NULL) {}
};

struct list{
    struct node* head;
    struct node* tail;
    list (): head(NULL), tail(NULL) {}
}; 

// API

extern Result query(int guess[]);

inline list* make_list(){
    list* LIST=new list;
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(j==i) continue;
            for(int k=0;k<10;++k){
                if(k==j || k==i) continue;
                for(int l=0;l<10;++l){
                    if(l==k || l==j || l==i) continue;
                    node* assigned=new node;
                    assigned->info[0]=i;
                    assigned->info[1]=j;
                    assigned->info[2]=k;
                    assigned->info[3]=l;
                    if(LIST->head==NULL){
                        LIST->head=assigned;
                        LIST->tail=assigned;
                    }
                    else{
                        LIST->tail->next=assigned;
                        assigned->prev=LIST->tail;
                        LIST->tail=assigned;
                    }
                }
            }
        }
    }
    return LIST;
}

inline void delete_list(list* L){
    
    while(1){
        auto temp=L->tail->prev;
        delete L->tail;
        
        if(temp==NULL) break;
        else L->tail=temp;
    }
    delete L;
}

Result myquery(int guess[], int compared[]) {
	Result result;
	
	result.strike = 0;
	result.ball = 0;

	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == compared[idx])
			result.strike++;
		else if (chk[compared[idx]])
			result.ball++;

	return result;
}

bool delete_condition1(Result cmp_res, Result result){
    return result.strike+result.ball==0 && cmp_res.strike+cmp_res.ball>0;
}

bool delete_condition2(Result cmp_res, Result result){
    return cmp_res.strike<result.strike;
}

bool delete_condition3(Result cmp_res, Result result){
    return cmp_res.strike+cmp_res.ball!=result.strike+result.ball;
}

inline void delete_process(node* tmp, node* pt, list* list){
    // 해당 탐색 과정이 tail이 아닌 경우
    if(pt!=NULL){
        pt->prev=tmp->prev;
        // head가 아닌 경우
        if(tmp->prev!=NULL) tmp->prev->next=pt;
        else list->head=pt;
    }
    // tail인 경우
    else{
        list->tail=list->tail->prev;
        list->tail->next=NULL;
    }
    delete tmp;
    if(pt!=NULL && pt->prev==NULL) list->head=pt;
}

void doUserImplementation(int guess[]) {
    // make list memory
    auto list=make_list();

    while(1){
        // Init
        for(int i=0;i<10;++i) chk[i]=false;
        for(int i=0;i<N;++i) guess[i]=list->head->info[i];
        auto result=query(guess);
        if(result.strike==4) break;
        for(int i=0;i<N;++i) chk[guess[i]]=true;

        // list minimization
        node* pt=list->head->next;
        pt->prev=NULL;
        delete list->head;
        list->head=pt;
        while(pt!=NULL){
            auto cmp_res=myquery(guess,pt->info);
            auto tmp=pt;
            pt=pt->next;
            // 삭제되어야 하는 경우
            if(delete_condition1(cmp_res,result)){
                delete_process(tmp,pt,list);
            }
            else if(delete_condition2(cmp_res,result)){
                delete_process(tmp,pt,list);
            }
            else if(delete_condition3(cmp_res,result)){
                delete_process(tmp,pt,list);
            }
            else continue;
        }
    }

    // delete list memory
    delete_list(list);
}