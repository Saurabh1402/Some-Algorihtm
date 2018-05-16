#include<stdio.h>
int LongestPallidromeSubString(char A[],int size){
	
	int L[size],max=1,j,k;
	L[0]=1;
	for (int i = 1; i < size; i++)
	{
		L[i]=1;
		if(A[i]==A[i-1]){
			L[i-1]=2;
			max=2;
		}
	}
	for (int i = 0; i < size; i++)
	{	j=i+1;
		k=i-1;
		int temp,temp1=i;
		while(A[i]==A[j]){
			j++;
		}
		temp=j-i;
		i=i+(j-i)/2;
		L[i]=temp;
		while(j<size&& k>=0&&A[j]==A[k]){
				L[i]+=2;
				j++;
				k--;
		}
		i=temp1;
				
	}
	for (int i = 0; i <size ; i++)
	{
		if(max<L[i])
			max=L[i];
		printf("%d ",L[i]);
	}
	
	return max;
}
int main(){
	char *c="asdfghjklllkjhgfdsaaaaaaaaaaaaa";
	LongestPallidromeSubString(c,34);
}
