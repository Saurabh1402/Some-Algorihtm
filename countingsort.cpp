#include<stdio.h>
void counting_sort(int A[],int n,int B[],int k){
		int C[k+1],i;
		for (int i = 0; i < n; i++)
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
		for (int i = 1; i <=k ; i++)
		{
			C[i]+=C[i-1];
		}
		for (int i = 0; i <=k ; i++)
		{
			C[i]--;
		}
		//for (int i = 0; i <=k ; i++)
		//{
		//	printf("%d ",C[i]);
		//}
		//printf("\n");
		for (int i = n-1; i >=0 ; i--)
		{
			B[C[A[i]]]=A[i];
			C[A[i]]--;
		}
		for (int i = 0; i <n ; i++)
		{
			printf("%d ",B[i]);
		}
}
int main(){
		int A[]={1,0,6,4,3,8,3,5,4,1,22,111};
		int B[12];
		counting_sort(A,12,B,111);
}
