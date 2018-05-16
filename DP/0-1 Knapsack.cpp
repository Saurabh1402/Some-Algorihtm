#include<stdio.h>
#include<limits.h>
int max(int a,int b){
	if(a>b)return a;
	return b;
}
void knapsack(int n,int s[],int v[],int C){
		int i,j,M[n+1][C+1];
		for (int i = 0; i <=n; i++)
		{
			for (int j = 0; j <=C ; j++)
			{
				M[i][j]=0;
			}
			
		}
		
		for (i = 0; i <=n; i++)
		{	
			for (j = 0; j<=C ; j++)
			{	if(i==0||j==0)
					M[i][j]=0;
				else if(s[i-1]<=j)
					M[i][j]=max(M[i-1][j],M[i-1][j-s[i-1]]+v[i-1]);
				else
					M[i][j]=M[i-1][j];
			}
			
		}
		
		for (i = 0; i <=n ; i++)
		{
			for (int k = 0; k <=C ; k++)
			{
					printf("%3d ",M[i][k]);
			}
			printf("\n");
		}
			
}
int main(){
	int s[]={2,3,5,4,6,1};
	int v[]={25,21,45,50,70,8};
	knapsack(12,s,v,6);
}
