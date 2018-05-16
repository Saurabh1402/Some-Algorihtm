#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>
#define TRUE 1
#define FALSE 0

void quickSortChar(char *,int ,int );
int partitionQuickSortChar(char *,int ,int);
void printCharArray(int [],int);
void quickSortInt(int *,int ,int );
int partitionQuickSortInt(int *,int ,int);
void printIntArray(int [],int);
void quickSortChar(char *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSortChar(ar,p,r);
		quickSortChar(ar,p,q-1);
		quickSortChar(ar,q+1,r);
	}
}
int partitionQuickSortChar(char *a,int p,int r){
	int i=p-1,j;
	char temp,pivot=a[r];
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
void printIntArray(int ar[],int n){
	    int i;
	    for(i=0;i<n;i++)printf("%d ",ar[i]);
}
void printCharArray(char ar[],int n){
	    int i;
	    for(i=0;i<n;i++)printf("%c ",ar[i]);
}
int main(){
	char ar[]="saurabh vishwakarma";
	int a[]={1,2,4,3,1,5,1};
	clrscr();
	quickSortInt(a,0,6);
	quickSortChar(ar,0,18);
	printIntArray(a,7);
	printCharArray(ar,19);
	getch();
	return 0;
}
