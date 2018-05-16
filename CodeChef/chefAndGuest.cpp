#include<stdio.h>
#include<math.h>
#include<malloc.h>
void primeFactor(int);
int *prime,*pw_num;
int main(){
	int sqrt_num,flag=0;
	int testCase,temp;
	scanf("%d",&testCase);
	int *arr[testCase];
	int num[testCase];
	for (int i = 0; i <testCase ; i++)
	{	
		scanf("%d",&num[i]);
		arr[i]=(int *)malloc(sizeof(int)*num[i]);
		for (int j = 0; j <num[i]; j++)
		{	
				scanf("%d",&arr[i][j]);
		}
		
	}
	for (int i = 0; i <testCase; i++)
	{
		temp=arr[i][0];
		sqrt_num=sqrt(temp);
		primeFactor(temp);	
		for (int  j= 0; j <=sqrt_num ; j++)
		{	if(pw_num[j]==0){
				continue;
			}
			flag=0;
			for (int k = 1; k <num[i]; k++)
			{
				if(arr[i][k]%prime[j]!=0){
				flag=1;
				}
			}
			if(flag==0){
				for (int k = 0; k <num[i] ; k++)
				{	
					arr[i][k]=arr[i][k]/prime[j];
				}
				pw_num[j]--;
				j--;	
			}
		}
		for (int j = 0; j <num[i]; j++)
		{	if(j!=num[i]-1)
				printf("%d ",arr[i][j]);
			else
				printf("%d\n",arr[i][j]);
		}
	}
}
void primeFactor(int p_num){
	int num=p_num,sqrt_num=(int)sqrt(num);
	int counter=0;
	prime=(int *)malloc(sizeof(int)*(sqrt_num+1));
	pw_num=(int *)malloc(sizeof(int)*(sqrt_num+1));
	for (int i = 0; i <=sqrt_num; i++)
	{
		prime[i]=0;
		pw_num[i]=0;
	}	
	for(int i=2;i<=sqrt_num;i++){
		if(num%i==0){
			num/=i;
			prime[counter]=i;
			pw_num[counter]++;
			if(num%i!=0){
				counter++;
				continue;
			}
			i--;
			continue;
		}
	}
	if(num!=0){
		prime[counter]=num;
		pw_num[counter]++;
	}
	
}
