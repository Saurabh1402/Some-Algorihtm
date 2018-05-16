#include<stdio.h>
#include<malloc.h>
#include<math.h>
void divisibleBy(int num){
int sqrt_num=sqrt(num);
int number[sqrt_num];
int counter=0;
for (int i = 0; i < sqrt_num; i++)
{
	number[i]=0;
}

for (int i = 1; i <=sqrt_num ; i++)
{
	if(num%i==0){
			number[counter]=i;
			if(i!=num/i)
			number[sqrt_num-1-counter]=num/i;
			counter++;
	}
}
for (int i = 0; i < sqrt_num; i++)
{	if(number[i]!=0)
	printf("%d, ",number[i]);
}

}
int main(){
	divisibleBy(36);
	return 0;
	}
