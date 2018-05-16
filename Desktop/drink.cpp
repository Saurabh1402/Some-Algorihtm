#include<stdio.h>
int partitionQuickSortInt(int *,int,int);
void quickSortInt(int *,int ,int);
void quickSortInt(int *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSortInt(ar,p,r);
		quickSortInt(ar,p,q-1);
		quickSortInt(ar,q+1,r);
	}
}
int partitionQuickSortInt(int *a,int p,int r){
	int i=p-1,j;
	int temp,pivot=a[r];
	for(i=p-1,j=p;j<r;j++){

		if(a[j]<=pivot){
		  i++;
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;

		}

	}
	i++;
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	return i;
}

int makeDrink(int A[],int size,int X){
	quickSortInt(A,0,size-1);
	
	
	for (int k = 0; k <size ; k++)
	{
		for (int i = k,j=size-1; i <j ; )
		{
			if(A[k]+A[i]+A[j]==X){
			return 1;
			}
			else if(A[k]+A[i]+A[j]<X){
				i++;
			}else j--;
		}
		
	}
	return 0;
	
}
int main(){
		int size,X;
		scanf("%d",&size);
		int d[size];
		for (int i = 0; i < size; i++)
		{
			scanf("%d",&d[i]);
		}
		scanf("%d",&X);
	int boolean=makeDrink(d,size,X);
	if(boolean){
	printf("True");
	}
	else {
		printf("False");
		}
}
