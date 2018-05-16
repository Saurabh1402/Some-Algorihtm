#include<stdio.h>
#include<limits.h>
int matrixChainMultiplication(int P[],int n){
	int i,j,k,L,M[n][n],S[n][n],temp;
	for (int i = 0; i <n ; i++)
	{
		M[i][i]=0;
	}
	for (L = 2; L <n ; L++)
	{
		for (i = 1; i <n-L+1; i++)
		{	j=i+L-1;
			M[i][j]=INT_MAX;
			for (k = i; k <=j-1 ; k++)
			{
				temp=M[i][k]+M[k+1][j]+P[i-1]*P[k]*P[j];
				if(temp<M[i][j])
					M[i][j]=temp;
					S[i][j]=k;
			}
			
		}
		
	}
	for (i = 0; i <n ; i++)
	{
		for (int j = 0; j <n ; j++)
		{
			printf("%10d ",M[i][j]);
		}
			printf("\n");
	}
	printf("\n");
	printf("\n");
	
	for (i = 0; i <n ; i++)
	{
		for (int j = 0; j <n ; j++)
		{
			printf("%10d ",S[i][j]);
		}
			printf("\n");
	}
	return M[1][n-1];
}
int main(){
	int p[]={2,2,6,4,8,4,6,2};
	int size=sizeof(p)/sizeof(p[0]);
	int min=matrixChainMultiplication(p,size);
	printf("MCM: %d",min);
}
