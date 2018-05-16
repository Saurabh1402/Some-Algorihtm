#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<math.h>
#define TRUE 1
#define FALSE 0

int checkDuplicateBruteForce(char [],int );
int checkDuplicateSort(char ar[],int n);
void quickSort(char *,int ,int );
int partitionQuickSort(char *,int ,int);
void printArray(int [],int);
void checkDuplicateInteger(int [],int );
int checkDuplicateBruteForce(char ar[],int n){
  int i,j;
  for(i=0;i<n-1;i++){
	for(j=i+1;j<n;j++){
		if(ar[i]==ar[j]){
			printf("Duplicate Element Found: %d",ar[i]);
			return TRUE;
		}
	}
  }
  return FALSE;
}
int checkDuplicateSort(char arr[],int n){
	int i;
	char *ar=(char*)malloc(sizeof(char)*n);
	for(i=0;i<n;i++)
	ar[i]=arr[i];
	quickSort(ar,0,n-1);
	for(i=0;i<n-1;i++){
	 if(ar[i]==ar[i+1]){
		printf("Duplicate Found: %s",arr);
		return i;
	 }
	}
	printf("No Duplicate Element Found!");
	return -1;
}
void quickSort(char *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSort(ar,p,r);
		quickSort(ar,p,q-1);
		quickSort(ar,q+1,r);
	}
}
int partitionQuickSort(char *a,int p,int r){
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
void printArray(int ar[],int n){
	    int i;
	    for(i=0;i<n;i++)printf("%d ",ar[i]);
}
void checkDuplicateInteger(int ar[],int n){
	int i=0;
	while(i<n){
		if(ar[abs(ar[i])] < 0){
		printf("a%d\t",abs(ar[i]));
		printf("Duplicate Exit! %d",ar[i]);
		return;
		}
		else{
		ar[ar[i]]*=-1;
		}
		 i++;
	}
	printf("No Duplicate Element!");
}
int main(){
	char ar[]="saurabh vishwakarma";
	int a[]={1,2,4,3,1,5,1};
	clrscr();
	//checkDuplicateSort(ar,19);
	checkDuplicateInteger(a,7);
	printArray(a,7);
	getch();
	return 0;
}
