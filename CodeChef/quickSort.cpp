#include<stdio.h>
void quickSortInt(int *,int ,int );
int partitionQuickSortInt(int *,int ,int);
void printIntArray(int [],int);
int main(){
	int no;
	scanf("%d",&no);
	int el[no];
	for (int i = 0; i <no ; i++)
	{
		scanf("%d",&el[i]);
	}
	quickSortInt(el,0,no-1);
	printIntArray(el,no);
}
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
	for(i=p-1,j=p;j<r;j++)
	{
		if(a[j]<=pivot)
		{
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
void printIntArray(int ar[],int n){
	    int i;
	    for(i=0;i<n;i++)printf("%d\n",ar[i]);
}

