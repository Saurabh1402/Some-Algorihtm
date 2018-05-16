#include<stdio.h>
#include<limits.h>
int min(int a,int b){
		if(a>b)return b;
		else return a;
		
}
int makingChange(int n,int den[],int num_den){
	int i,temp,table[n+1],j;
	for (int i = 0; i <=n; i++)
	{
		table[i]=INT_MAX;
	}
	table[0]=0;
	if(n==0)return 0;
	for (i = 1; i <=n; i++)
	{	temp=INT_MAX;
			for (j = 0; j <num_den &&den[j]<=i; j++)
			{	
				temp=min(temp,table[i-den[j]]+1);
			}
		
		table[i]=temp;
		
	}
		
	return table[n];
}
int main(){
	int a[]={1,5,7,10};
	
	printf("%d",makingChange(4120,a,4));
return 0;	
}

