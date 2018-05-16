#include<stdio.h>
#include<malloc.h>
struct Node1{
	int data;
	struct Node1 *next;
};
int main(){
		struct Node1 *p=NULL;
		p=(struct Node1*)malloc(sizeof(struct Node1));
		p->data=10;
		p->next=(struct Node1*)malloc(sizeof(struct Node1));
		p->next->data=30;
		p->next->next=(struct Node1*)malloc(sizeof(struct Node1));
		p->next->next->data=40;
		printf("%d ",p->data);
		p=p->next;
		printf("%d ",p->data);
		p=p->next;
		printf("%d ",p->data);
		
return 0;}
