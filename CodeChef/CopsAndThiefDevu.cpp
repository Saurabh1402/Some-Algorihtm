#include<stdio.h>
#include<malloc.h>
struct Node{
	int start;
	int end;
	struct Node *next;
};
struct Node* insert(struct Node **proot,int start,int end){
	struct Node *root=*proot,*temp1=NULL,*temp=NULL,*newNode=(struct Node*)malloc(sizeof(struct Node));
	if(!root){
		newNode->start=start;
		newNode->end=end;
	}
	temp=root;
	while(root->start<start){
		temp=root;
		root=root->next;
	}
	root=temp;
	if(root->start>start||root->end>start){
		
		temp=root;
		if(root->start>start)
			root->start=start;
		temp1=root;
		if(root->end<end)
		root->end=end;
		while(root->start < end &&root){
			temp=root;
			root=root->next;
		}
		temp1->next=root;
		if(temp->end<end)
			temp->end=end;
		else
			temp1->end=temp->end;
		return *proot;
	}
	else{
		
		while(root->end < start && root!=NULL){
			temp=root;
			root=root->next;
			
		}
		
		if(!root){
		newNode->start=start;
		newNode->end=end;
		newNode->next=NULL;
		temp->next=newNode;
		return *proot;
		}
		else if(root->start>start){
			newNode->start=start;
			newNode->end=end;
			newNode->next=root;
			temp->next=newNode;
			return *proot;
		}else{
			
		}
	}
			
}
int main(){
		int testCase;
		int *cop,n,x,y;
		while(testCase--){
			scanf("%d",&n,&x,&y);
			cop=(int *)malloc(sizeof(int));
		}
}
