#include<stdio.h>
void backtrack(int [],int[],int ,int,int);
int subsetSum(int N[],int size,int n){
	int S[n+1],temp;
	S[0]=1;
	for (int i = 1; i <=n ; i++)
	{
		S[i]=0;
	}
	
	for (int i = 0; i <size ; i++)
	{
		for (int j = n; j >=1 ; j--)
		{	temp=S[j];
			if(j<N[i])
			continue;
			S[j]=S[j-N[i]];
			if(S[j] && j==n){
				backtrack(N,S,size,n,i);
			}
			S[j]=S[j]||temp;
		}
		
	}
	
	return S[n];
	
}void backtrack(int A[],int S[],int n,int T,int i){
	int temp[n],temp1=T;
	int counter=0;
	
	printf("[");
	
	while(i>=0 && S[temp1] && temp1-A[i]>=0){
		printf("%d, ",A[i]);
		
		temp1-=A[i];
		i--;
	}
	printf("]\n");
}

int main(){
	int N[]={10,7,6,5,3,2,1};
	printf("\n%d ",subsetSum(N,7,23));
	return 0;
}
