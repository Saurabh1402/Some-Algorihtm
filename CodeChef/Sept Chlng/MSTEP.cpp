#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void insert(struct LinkedList ,int ,int );
struct LinkedList{
	int x;
	int y;
};
int main(){
	int ans=0,data,size,testCase;
	scanf("%d",&testCase);
	while(testCase--){
		scanf("%d",&size);
	struct LinkedList list[size*size];
	ans=0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <size ; j++)
		{
			scanf("%d",&data);
			list[data-1].x=i;
			list[data-1].y=j;
		}
		
	}
	for (int i = 1; i <size*size ; i++)
	{	
		ans+=abs(list[i].x-list[i-1].x)+abs(list[i].y-list[i-1].y);
	}
	printf("%d\n",ans);
		
	}
	return 0;
}
void insert(struct LinkedList list,int x,int y){
	
}
