#include<stdio.h>
#include<string.h>
int LargestRecursive(int[],int,int);
int max(int,int);
int count=0;
int main(){
	int a[]={23,45,23353,53,234,531,1,564,-34,5533};
	printf("%d\t%d\n",count,LargestRecursive(a,0,9));
	return 0;
}
int LargestRecursive(int a[],int start,int end){
	count++;
	int mid;
	if(start<end){
		mid=start+(end-start)/2;
		return max(LargestRecursive(a,start,mid),LargestRecursive(a,mid+1,end));
	}
	return a[start];
	
}
int max(int a,int b){
	if(a>b)return a;
	else return b;
}
