#include<stdio.h>
#include<malloc.h>
int *L;
int LongestIncreasingSequence(int A[], int size){
		int i,j,max=0;
		for (i = 0; i <size ; i++)
		{
			L[i]=1;
		}
		for (i = 0; i <size; i++)
		{
			for (j = 0; j < i; j++)
			{
				if(A[i]>A[j] && L[i]<L[j]+1){
					L[i]=L[j]+1;
				}
			}
			
		}
		for (int i = 0; i <size ; i++)
		{
			if(L[max]<L[i])
				max=i;
		}
	for (int i = 0; i < size; i++)
	{
		printf("%d ",L[i]);
	}
	
	return max;
		
}
int main(){
	int A[]={5,6,7,8,2,3,4,1,9,10,5,6,15,16,17};
	int max,num;
	L=(int *)malloc(sizeof(int)*15);
	max=LongestIncreasingSequence(A,15);
	printf("\n");
	num=L[max];
	for (int i = max; i >=0; i--)
	{	
		if(L[i]==num){
		printf("%d ",A[i]);
		num--;
		}
	
	}
	
	return 0;
}
