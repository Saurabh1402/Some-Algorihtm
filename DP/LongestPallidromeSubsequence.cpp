#include<stdio.h>
int MAX(int ,int);
int LongestPallidromeSubsequence(char c[],int size){
	int L[size][size],max=1,k;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size;j++)
		{
			L[i][j]=0;
		}
	}
	L[0][0]=1;
	for (int i = 1; i <size ; i++)
	{
		L[i][i]=1;
		if(c[i]==c[i-1]){
			L[i-1][i]=2;
			max=2;
		}
		else
			L[i-1][i]=0;
	}
	
	for (int i = 2; i <=size; i++)
	{
		for (int j = 0; j <size-i+1; j++)
		{
			k=j+i-1;
			if(c[j]==c[k]){
				L[j][k]=2+L[j+1][k-1];
				if(max<L[j][k]){
					max=L[j][k];
				}
			}
			else{
				L[j][k]=MAX(L[j+1][k],L[j][k-1]);
			}
		}
		
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size;j++)
		{
			printf("%d ",L[i][j]);
		}
		printf("\n");
	}
	
	return max;
}

int MAX(int a,int b){
	return a>b?a:b;
}
int main(){
	char *c="DFEREGHGDSDFDDSDSS";
	printf("%d",LongestPallidromeSubsequence(c,18));
	
}
