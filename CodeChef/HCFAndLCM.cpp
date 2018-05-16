#include<stdio.h>
#include<math.h>
#include<malloc.h>
void primeFactor(int);
int *prime,*pw_num;
int main(){
	int sqrt_num;
	int testCase,hcf=1,mul;
	scanf("%d",&testCase);
	int a,b;
	while(testCase--){
		scanf("%d%d",&a,&b);
		mul=a*b;
		sqrt_num=sqrt(a);
		primeFactor(a);
		hcf=1;
		for (int i = 0; i <=sqrt_num; i++)
		{	if(a==1||b==1)break;
			if(pw_num[i]==0){
				continue;
			}
			if(b%prime[i]==0){
				hcf*=prime[i];
				a/=prime[i];
				b/=prime[i];
				pw_num[i]--;
				i--;
			}
		}
		printf("%d %d\n",hcf,mul/hcf);
		
	
	}
	return 0;
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
