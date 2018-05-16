#include<stdio.h>
#define MAX 2000
void backtrack(int A[],int S[][2000],int n,int T,int i,int temp[],int counter){
				int temp1=T;
				int r;
				r=i;
				 while(r>0 && temp1>0){
					if(!S[r][temp1]){
						temp1+=A[r];
						counter--;
						continue;
					} 
					temp[counter++]=A[r-1];
					temp1-=A[r-1];
					if(temp1<=0)
					{
						break;
					}	
					r--;
					for(int y=1;y<=r;y++){
						//backtrack(A,S,n,T,r-y,temp,counter);
					}
					
				}
				printf("[");
				for (int l = counter-1; l >=0 ; l--)
				{ 	if(l==0)
					printf("%d",temp[0]);
					else
					printf("%d, ",temp[l]);
				}
				printf("]\n");
				
}
void subsetSum(int A[],int n,int T){
int S[n+1][2000],temp;
for (int i = 0; i <n+1 ; i++)
{
	for (int j = 0; j < T+1; j++)
	{
		S[i][j]=0;
	}
	
}

S[0][0]=1;
for (int i = 0; i <n+1 ; i++)
{
	S[i][0]=1;
}
for (int i = 1; i<=n; i++)
{
	for (int j = 1; j <=T ; j++)
	{	temp=S[i-1][j];
		if(j>=A[i-1])
		S[i][j]=S[i-1][j-A[i-1]];
		if(S[i][j] && j==T){
	int temp[T],counter=0;
				backtrack(A,S,n,T,i,temp,counter);
		}
		if(temp){
			S[i][j]=temp+S[i][j];
		}
	}
	
}
	
for (int i = 1; i <n+1 ; i++)
{	for (int j = 0; j < T+1; j++)
	{
		printf("%d ",S[i][j]);
	}
	printf("\n");
}

}
int main(){
	int A[]={10,7,6,5,3,2,1};
	int num=23;
	subsetSum(A,7,num);
}
