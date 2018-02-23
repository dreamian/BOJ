#include <cstdio>
using namespace std;

inline void print_year(int yy){
    if(yy>=1000){
        printf("%d",yy);
    }
    else if(yy>=100){
        printf("0%d",yy);
    }
    else if(yy>=10){
        printf("00%d",yy);
    }
    else if(yy>=1){
        printf("000%d",yy);
    }
    else printf("0000");

    printf("/");
}

inline void print_month(int mm){
    if(mm>=10){
        printf("%d",mm);
    }
    else{
        printf("0%d",mm);
    }
    printf("/");
}

inline void print_day(int dd){
    if(dd>=10){
        printf("%d",dd);
    }
    else printf("0%d",dd);
    printf("\n");
}

inline void print_good(int yy, int mm, int dd){
    print_year(yy);
    print_month(mm);
    print_day(dd);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        printf("#%d ",tc);
        int addr;
        scanf("%d",&addr);
        int year=addr/10000;
        addr%=10000;
        int month=addr/100;
        if(month<1 || month>12){
            printf("-1\n");
            continue;
        }
        int day=addr%100;
        if (day>31){
            printf("-1\n");
            continue;
        }
        else if(month==2){
            if(day<=28){
                print_good(year,month,day);
            }
            else printf("-1\n");
            continue;
        }
        else if(month<=7){
            if(month%2==1 && day<=31) print_good(year,month,day);
            else if(month%2==0 && day<=30) print_good(year,month,day);
            else printf("-1\n");
        }
        else{
            if(month%2==0 && day<=31){
                print_good(year,month,day);
            }
            
            else if(month%2==1 && day<=30){
                print_good(year,month,day);
            } 
            else printf("-1\n");
        }
    }
    return 0;
}