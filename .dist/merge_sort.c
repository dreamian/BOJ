//Merge Sort
#include <stdio.h>

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
	int len=sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	Split(arr,0,len-1);
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}


