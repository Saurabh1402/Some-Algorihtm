#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

void quickSortInt(int *,int*,int *,int ,int );
int partitionQuickSortInt(int*,int*,int *,int ,int);
void printIntArray(int [],int);

/*
				 int main(){
					char ar[]="saurabh vishwakarma";
					int a[]={1,2,4,3,1,5,1};
					quickSortInt(a,0,6);
					quickSortChar(ar,0,18);
					printIntArray(a,7);
					printCharArray(ar,19);

					return 0;
				}

 
 
 */

void quickSortInt(int *src,int *dst,int *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSortInt(src,dst,ar,p,r);
		quickSortInt(src,dst,ar,p,q-1);
		quickSortInt(src,dst,ar,q+1,r);
	}
}
int partitionQuickSortInt(int *src,int *dst,int *a,int p,int r){
	int i=p-1,j;
	int temp,pivot=a[r];
	for(i=p-1,j=p;j<r;j++){

		if(a[j]<=pivot){
		  i++;
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;
		  temp=src[i];
		  src[i]=src[j];
		  src[j]=temp;
		  temp=dst[i];
		  dst[i]=dst[j];
		  dst[j]=temp;
		  
		}

	}
	i++;
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	temp=src[i];
	src[i]=src[j];
	src[j]=temp;
	temp=dst[i];
	dst[i]=dst[j];
	dst[j]=temp;
		  
	return i;
}
void printIntArray(int ar[],int n){
	    int i;
	    for(i=0;i<n;i++)
			printf("%d ",ar[i]);
}
