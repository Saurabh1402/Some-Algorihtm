#include<stdio.h>
int main(){
	int n,k,temp,max=0,testCase;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d%d",&n,&k);
		max=0;
		while(k>1){
			temp=n%k;
			if(temp>max)
				max=temp;
			k--;
		}
		printf("%d\n",max);
	}
	return 0;
}
