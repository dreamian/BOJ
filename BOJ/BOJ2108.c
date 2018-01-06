#include <stdio.h>

void numeric(int arr[],int len){
    double sum=0;
    int n=len;
    while(len--){
        sum+=arr[len];
    }
    sum/=n;
   printf("%.0lf\n",sum);
}

void median(int arr[],int len){
    int mid=(len/2)+1;
    printf("%d\n",arr[mid-1]);
}

void frequent(int arr[],int len){
    int freq[8001]={0}; // -4000~+4000이 각각 대응
    int max[2]={0};
    
    for(int i=0;i<len;i++){
        freq[arr[i]+4000]+=1;        
    }
    int cnt=0;
    for(int i=1;i<8001;i++){
        if(freq[i]>cnt) {cnt=freq[i]; max[0]=i; max[1]=0;}
        else if (freq[i]==cnt && (max[1]>i||max[1]==0)) {max[1]=i;}
    }
    if (max[1]!=0) {printf("%d\n",max[1]-4000);}
    else {printf("%d\n",max[0]-4000);}
}

void range(int arr[],int len){
    
    printf("%d\n",arr[len-1]-arr[0]);
}

void Merge(int arr[],int first, int mid,int last){
	int f=first, m=mid+1, cnt=0;
	int tmp[last-first+1];
	
	while(f<=mid && m<=last){
		if(arr[f]>arr[m]) tmp[cnt++]=arr[m++];
		else tmp[cnt++]=arr[f++]; 
	}
	while(f<=mid){
		tmp[cnt++]=arr[f++]; 
	}
	while(m<=last){
		tmp[cnt++]=arr[m++];
	}
	int t=0;
	f=first;
	while(f<=last){
		arr[f++]=tmp[t++];
	}
}

void Split(int arr[],int first,int last){
	if(last>first){
		int mid=(first+last)/2;
		Split(arr,first,mid);
		Split(arr,mid+1,last);
		Merge(arr,first,mid,last);
	}
}

int main(void){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int len=sizeof(arr)/sizeof(int);
    Split(arr,0,len-1);
    numeric(arr,len);
    median(arr,len);
    frequent(arr,len);
    range(arr,len);
}