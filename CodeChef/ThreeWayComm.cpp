#include<stdio.h>
#include<math.h>
int main(){
	int r,a[2],count,b[2],c[2],testCase;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d%d%d%d%d%d%d",&r,&a[0],&a[1],&b[0],&b[1],&c[0],&c[1]);
		count=0;
		if(ceil(sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])))<=r)
			count++;
		if(ceil(sqrt((a[0]-c[0])*(a[0]-c[0])+(a[1]-c[1])*(a[1]-c[1])))<=r)
			count++;
		if(ceil(sqrt((b[0]-c[0])*(b[0]-c[0])+(b[1]-c[1])*(b[1]-c[1])))<=r)
			count++;
		if(count>=2){
			printf("yes\n");
		}else 
			printf("no\n");
		
	}
	return 0;
}
