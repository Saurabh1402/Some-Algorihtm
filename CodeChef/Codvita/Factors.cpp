#include<stdio.h>
#include<math.h>
#include<malloc.h>

int primeFactor(int);
int *prime,*pw_num;
int main(){
	int sqrt_num,testCase,no,counter;
	scanf("%d",&testCase);
	while (testCase--)
	{
		scanf("%d",&no);
		sqrt_num=primeFactor(no);
		counter=0;
		for (int i = 0; i <=sqrt_num; i++)
		{
			counter+=pw_num[i];
		}
		printf("%d\n",counter);
	}
	
}
int primeFactor(int p_num){
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
	
	return sqrt_num;
}
