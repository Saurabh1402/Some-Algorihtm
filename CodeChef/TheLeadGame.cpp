#include<stdio.h>
int main(){
	int test,score=-1,player=0;
	scanf("%d",&test);
	int A[test],B[test],a=0,b=0;
	for (int i = 0; i <test; i++)
	{
		scanf("%d %d",&A[i],&B[i]);
		a+=A[i];
		b+=B[i];
		if(a>b){
			if(a-b>score){
				player=1;
				score=a-b;
			}
		}
		else{
			if(b-a>score){
				player=2;
				score=b-a;
			}
		}
	}
	printf("%d %d",player,score);
	return 0;
}
