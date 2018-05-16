#include<stdio.h>
#include<limits.h>
long long min(long long,long long);
int main(){
	long long n,k;
	scanf("%Ld",&n);
	scanf("%Ld",&k);
	long long a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%Ld",&a[i]);
	}
	for(int i=0;i<n;i++){
		b[i]=LONG_MAX;
	}
	b[0]=a[0];
	for(int i=1;i<n;i++){
		for(int j=1;j<=k &&i-j>=0;j++){
			b[i]=min(b[i],a[i]*b[i-j]);
		}
		
	}
	//for (int i = 0; i <n ; i++)
	//{
		//printf("%ld ",b[i]);
	//}
	
	printf("%Ld",b[n-1]%1000000007);
	return 0;
}
long long min(long long a,long long b){
		return a>b?b:a;
}
