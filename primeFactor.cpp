#include<stdio.h>
#include<math.h>
void primeFactor(int );
int main(){
	primeFactor(932451);
	return 0;
	}

void primeFactor(int p_num){
	int num=p_num,sqrt_num=(int)sqrt(num);
	int counter=0;
	int prime[sqrt_num+1],pw_num[sqrt_num+1];
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
	for (int i = 0; i <= sqrt_num; i++)
	{
		if(pw_num[i]!=0){
			printf(" %d^%d x",prime[i],pw_num[i]);
		}
	}
	
}
