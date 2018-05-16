#include<stdio.h>
#include<malloc.h>
struct SimpleLinkedListInt* insertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **, int,int);
struct SimpleLinkedListInt* insertAtBeginningSimpleLinkedListInt(struct SimpleLinkedListInt **, int,int);
struct SimpleLinkedListInt* insertAfterPosSimpleLinkdListInt(struct SimpleLinkedListInt **,int,int,int);
struct SimpleLinkedListInt * uniqueInsertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **,int );

int deleteFromEndSimpleLinkedListInt(struct SimpleLinkedListInt **);
int deleteFromBeginningSimpleLinkedListInt(struct SimpleLinkedListInt **);
int deleteDataSimpleLinkdListInt(struct SimpleLinkedListInt **,int);
void deleteSimpleLinkedListInt(struct SimpleLinkedListInt **);

struct SimpleLinkedListInt * reverseSimpleLinkedListInt(struct SimpleLinkedListInt **);
void displaySimpleLinkedListInt(struct SimpleLinkedListInt*);

struct SimpleLinkedListInt{
	int data;
	int key;
	struct SimpleLinkedListInt *next;
};
/*

	int main(){
		struct SimpleLinkedListInt *root=NULL;
		int i,a[]={4,12,45,1223,35,23,46,68,87,100};
		for(i=0;i<10;i++)
		insertAtEndSimpleLinkedListInt(&root,a[i]);
		displaySimpleLinkedListInt(root);	
		printf("\nreverse: ");
		root=reverseSimpleLinkedListInt(&root);
		displaySimpleLinkedListInt(root);	
			
		
		return 0;	
	}
*/ 
struct SimpleLinkedListInt * insertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **proot,int data,int key){
	struct SimpleLinkedListInt *newNode=(struct SimpleLinkedListInt *)malloc(sizeof(struct SimpleLinkedListInt));
	if(newNode==NULL){
			printf("Memory Error: LINE::35");
			return NULL;
	}
	struct SimpleLinkedListInt *root=*proot;
	newNode->data=data;
	newNode->key=key;
	newNode->next=NULL;
	if(root==NULL) *proot=newNode;
	else {
	while(root->next!=NULL)
		root=root->next;
	root->next=newNode;
	}
	return *proot;
}
struct SimpleLinkedListInt* insertAtBeginningSimpleLinkedListInt(struct SimpleLinkedListInt **proot,int data,int key){
	struct SimpleLinkedListInt *newNode=(struct SimpleLinkedListInt *)malloc(sizeof(struct SimpleLinkedListInt));
	if(newNode==NULL){
			printf("Memory Error: LINE::52");
			return NULL;
	}
	newNode->data=data;
	newNode->key=key;
	newNode->next=*proot;
	*proot=newNode;
	return *proot;
}
struct SimpleLinkedListInt* insertAfterPosSimpleLinkdListInt(struct SimpleLinkedListInt **proot,int data,int pos,int key){
	struct SimpleLinkedListInt *newNode=(struct SimpleLinkedListInt *)malloc(sizeof(struct SimpleLinkedListInt));
	if(newNode==NULL){
			printf("Memory Error: LINE::63");
			return NULL;
	}
	struct SimpleLinkedListInt *root=*proot;
	int i=1;
	newNode->data=data;
	newNode->key=key;
	if(!(root==NULL||pos<=0)){
		while(i<pos && root->next!=NULL){
			root=root->next;
			i++;	
		}
		newNode->next=root->next;
		root->next=newNode;
	}
	else if(pos==0){
		newNode->next=root;
		*proot=newNode;
		
	}
	return *proot;
}
struct SimpleLinkedListInt * uniqueInsertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **proot,int data){
	struct SimpleLinkedListInt *newNode=(struct SimpleLinkedListInt *)malloc(sizeof(struct SimpleLinkedListInt));
	if(newNode==NULL){
			printf("Memory Error: LINE::35");
			return NULL;
	}
	struct SimpleLinkedListInt *root=*proot;
	newNode->data=data;
	newNode->next=NULL;
	if(root==NULL) *proot=newNode;
	else {
	while(root->next!=NULL){
		if(root->data==data){
			printf("Duplicate Element-> %d",data);
			return *proot;
		}
		root=root->next;
			
	}
	root->next=newNode;
	}
	return *proot;
}

int deleteFromEndSimpleLinkedListInt(struct SimpleLinkedListInt **proot){
	int data;
	struct SimpleLinkedListInt *root=*proot,*temp=NULL;
	if(root==NULL){
		printf("Underflow to delete: LINE::71");
		return -1;
	}if(root->next==NULL){
		data=root->data;
		free(root);
		*proot=NULL;
		return data;
	}
	while(root->next->next!=NULL){
		root=root->next;
	}
	data=root->next->data;
	temp=root->next;
	root->next=NULL;
	free(temp);
	return data;
}
int deleteFromBeginningSimpleLinkedListInt(struct SimpleLinkedListInt **proot){
	int data;
	struct SimpleLinkedListInt *root=*proot;
	if(root==NULL){
		printf("Underflow to delete: LINE::92");
		return -1;
	}
	*proot=root->next;
	data=root->data;
	free(root);	
	return data;
}
int deleteDataSimpleLinkdListInt(struct SimpleLinkedListInt **proot,int data){
	struct SimpleLinkedListInt *root=*proot,*temp=NULL;
	if(root==NULL){
		printf("Underflow to delete: LINE::104");
		return -1;
	}
	while(root!=NULL&&root->data!=data){
		temp=root;
		root=root->next;	
	}
	if(root==NULL){
		printf("Data Not Found");
		return -1;
	}
	else if(temp==NULL&&root->data==data){
		*proot=root->next;
		free(root);
		return data;
	}
	else{
		temp->next=root->next;
		free(root);
		return data;
	}
	
}
void deleteSimpleLinkedListInt(struct SimpleLinkedListInt **proot){
	if(!(*proot)) return;
	deleteSimpleLinkedListInt(&(*proot)->next);
	free(proot);
}
struct SimpleLinkedListInt* reverseSimpleLinkedListInt(struct SimpleLinkedListInt **proot){
	struct SimpleLinkedListInt *node=*proot,*r=NULL,*p=NULL;
	if(node==NULL)return node;
	while(node->next!=NULL){
		r=node->next;
		node->next=p;
		p=node;
		node=r;
	}
	node->next=p;
	*proot=node;	
	return node;
}
void displaySimpleLinkedListInt(struct SimpleLinkedListInt *root){
		while(root!=NULL){
				printf("%d ",root->data);
				root=root->next;
		}
}
