#include<stdio.h>
void counting_sort(int[],int,int[],int);
void counting_sort(int A[],int n,int B[],int k){
		int C[k+1],i;
		for (i = 0; i < n; i++)
		{
			B[i]=-1;
		}
		
		for (i = 0; i <= k; i++)
		{
			C[i]=0;
		}
		for (i = 0; i < n; i++)
		{
			C[A[i]]++;
		}
		for (i = 1; i <=k ; i++)
		{
			C[i]+=C[i-1];
		}
		for (i = 0; i <=k ; i++)
		{
			C[i]--;
		}
		for (i = n-1; i >=0 ; i--)
		{
			B[C[A[i]]]=A[i];
			C[A[i]]--;
		}
		for (i = 0; i <n ; i++)
		{
			printf("%d\n",B[i]);
		}
}
int main(){
		
		int num,max=-1;
		scanf("%d",&num);
		int A[num];
		for (int i = 0; i <num ; i++)
		{
			scanf("%d",&A[i]);
			if(A[i]>max)
				max=A[i];
		}
		
		int B[num];
		counting_sort(A,num,B,max);
		return 0;
	}
