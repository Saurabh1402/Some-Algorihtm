#include<stdio.h>
#include<string.h>

void FindWithPairComparison(int A[],int n){
	int i=0,large=1,small=4444;
	for(i=0;i<n-1;i+=2){
	
		if(A[i]<A[i+1]){
			
			if(A[i]<small){
				small=A[i];
				}
			if (A[i+1]>large)
			{
				large=A[i+1];
			}
			
			
			
		}
		else
		{
			if(A[i+1]<small){
				small=A[i+1];
				}
			if (A[i]>large)
			{
				large=A[i];
			}
		}
		
		
	}
	printf("Largest: %d\tSmallest: %d",large,small);
	
		
}

int main(){
	int a[]={45,6653,34,12,64,67,87,22,34,65};
	FindWithPairComparison(a,10);
	return 0;
}
