#include<stdio.h>
int main(){
		int a;
		float b;
		scanf("%d",&a);
		scanf("%f",&b);
		if(a+0.5f>b || a%5!=0|| a<=0){
			printf("%.2f", b);
		}
		else{
			b-=a+0.5f;
			printf("%.2f",b);
		}
	return 0;
}
