#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    scanf("%d",&n);
    char word[n][51];

    for(int i=0;i<n;i++){
        scanf("%s",word[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=(i+1);j<n;j++){
            char temp[51];
            int i_len=strlen(word[i]);
            int j_len=strlen(word[j]);
            if(i_len>j_len) {strcpy(temp,word[i]);strcpy(word[i],word[j]);strcpy(word[j],temp);}
            else if (i_len==j_len) {
                  int cnt=0;
                while(cnt<=i_len-1){  
                    if(word[i][cnt]>word[j][cnt])
                         { strcpy(temp,word[i]);strcpy(word[i],word[j]);strcpy(word[j],temp); break;}
                    else if (word[i][cnt]==word[j][cnt]) {cnt++;}
                    else {break;}
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(strcmp(word[i],word[i+1])) {printf("%s\n",word[i]);}
    }

}