#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void printLinkedList(struct ListNode *);
struct ListNode* insertNodeAtBeginning(struct ListNode**,int);
struct ListNode* insertAtPosition(struct ListNode** ,int,int);
void insertAtLast(struct ListNode* ,int );
void deleteFirst(struct ListNode**);
void deleteAtPosition(struct ListNode**,int pos);
void deleteLast(struct ListNode**);
int lengthLinkedList(struct ListNode*);
void swapNodes(struct ListNode**,int ,int );
struct ListNode* reverseLinkedList(struct ListNode**);
struct ListNode* reverseRecursiveLinkedList(struct ListNode**);
void reverseInGroupLinkedList(struct ListNode**,int );
void rotateLinkedList(struct ListNode**,int);
int detectLoop(struct ListNode*);
struct ListNode* findBeginLoop(struct ListNode*);
int FindLoopLength(struct ListNode*);
struct ListNode{
	int data;
	struct ListNode *next;
};
/*
struct LinkedList{
	int ListNode *head;
	int count;
}
*/

int main(){
	struct ListNode* head = NULL;
	while(true){
		int choice;
		int data,pos;
		int sizeofGroup;
		int x,y;
		int flag,lengthofLoop;
		struct ListNode* node=NULL;
				
		printf("Press:- \n1 --> Insert at Beginning\n2 --> Insert at Position\n3 -->Reverse Linked List\n4-->Reverse Recursively\n5-->Display Linked List\n6 --> Insert At Last\n7 --> Delete First Node\n8 --> Delete At Position\n9 --> Delete Last Node\n10 --> SwapNodes\n11-> Length of LinkedList\n12-->Reverse In group\n14-->rotate Linked List\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter data :-\t");
				scanf("%d",&data);
				insertNodeAtBeginning(&head,data);
				break;
			case 2:
				printf("Enter Data :-\t");
				scanf("%d",&data);
				printf("Enter Position:- ");
				scanf("%d",&pos);
				insertAtPosition(&head,pos,data);
				break;
			case 3:
				reverseLinkedList(&head);
				break;
			case 4: 
				head=reverseRecursiveLinkedList(&head);
				break;
			case 5:
				printLinkedList(head);
				break;
			case 6:
				printf("Enter Data :-\t");
				scanf("%d",&data);
				insertAtLast(head,data);
				break;
			case 7:
				deleteFirst(&head);
				break;
			case 8:
				printf("Enter Position:-");
				scanf("%d",&pos);
				deleteAtPosition(&head,pos);
				break;
			case 9:
				deleteLast(&head);
				break;
			case 10: 
				printf("\nEnter datas' to be swapped : 	\n");
				scanf("%d%d",&x,&y);
				swapNodes(&head,x,y);
				break;
			case 11:
				printf("\nLength of LinkedList is : %d\n",lengthLinkedList(head));
				break;
			case 12:
				printf("\nEnter the size of group\n");
				scanf("%d",&sizeofGroup);
				reverseInGroupLinkedList(&head,sizeofGroup);
				break;
			case 13:
				flag=detectLoop(head);
				if(flag){
					lengthofLoop=FindLoopLength(head);
					node=findBeginLoop(head);
					printf("\nLoop Exits at %d of length %d \n",node->data,lengthofLoop);
				}else{
					printf("\nLoop does not exits\n");
				}
				break;
			case 14: 
				printf("\nEnter the size of group\n");
				scanf("%d",&sizeofGroup);
				rotateLinkedList(&head,sizeofGroup);
				break;
		default:
				exit(0);
		}
	}
	return 0;
}
 
void printLinkedList(struct ListNode *head){
	while(head!=NULL){
	 printf("%d -> ",head->data);
	 head=head->next;
	}
}


struct ListNode* insertNodeAtBeginning(struct ListNode** head,int data){
	struct ListNode *node= NULL;
		node=(struct ListNode*)malloc(sizeof(struct ListNode));
		node->next=(*head);
		node->data=data;
		(*head)=node;
		
		
		return (*head);
}

struct ListNode* insertAtPosition(struct ListNode** head,int pos,int data){
	
	struct ListNode* node = (*head);
	if(pos==1){
	
		struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->data=data;
		newNode->next=node;
		(*head)=newNode;
		return (*head);
	}
	
	while(node!=NULL && --pos> 1){
		node=node->next;
	}
	if(node==NULL){
		printf("There are less number of element in linked List to insert");
		
	}else{
	struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->data=data;
	newNode->next=node->next;
	node->next=newNode;
	}
	return (*head);
}

void insertAtLast(struct ListNode* node,int data){
	while(node->next == NULL){
		node = node->next;
	}
	struct ListNode* newNode=NULL;
	newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->data=data;
	newNode->next = NULL;
	node->next=newNode;
}
void deleteFirst(struct ListNode **head){
	if((*head)==NULL) return;
	struct ListNode *temp=(*head);
	(*head)=(*head)->next;
	free(temp);
}

void deleteAtPosition(struct ListNode **head,int pos){
	if((*head)==NULL) return;
	struct ListNode* temp=NULL;
	struct ListNode* prev=NULL;
	struct ListNode* current=(*head);
	int k=1;
	if(pos==k){
		temp=(*head);
		(*head)=(*head)->next;
	}else{
		while(k++<pos && current!=NULL){
			prev=current;
			current=current->next;
		}
		if(current==NULL){
			printf("\n------------There are insufficient of element to delete at given position-------------------\n");
		}
		temp=current;
		prev->next=current->next;
	}
	free(temp);
}
void deleteLast(struct ListNode** head){
	struct ListNode* prev=NULL;
	struct ListNode* temp=(*head);
	if((*head)==NULL) return;
	if((*head)->next==NULL){ 
		temp=(*head);
		(*head)=NULL;
	}else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		prev=temp;
		temp=temp->next;
		prev->next=NULL;
		
	}
	free(temp);
}

struct ListNode* reverseLinkedList(struct ListNode** head){
	struct ListNode* p=NULL;
	struct ListNode* q=NULL;
	struct ListNode* r=NULL;
	p=r=(*head);
	if(p==NULL)return NULL;
	q=p->next;
	while(q!=NULL){
		p->next=q->next;
		q->next=r;
		r=q;
		q=p->next;
	}
	(*head)=r;	
	return (*head);
}
struct ListNode* reverseRecursiveLinkedList(struct ListNode** head){
		struct ListNode* temp=NULL;
		struct ListNode* next=NULL;
		if((*head)==NULL) return NULL;
		if((*head)->next==NULL) return (*head);
		next=(*head)->next;
		(*head)->next=NULL;
		temp=reverseRecursiveLinkedList(&next);
		next->next=(*head);
		return temp;
}

// It is assumed that all the nodes in the linked list are different. Swap is done by comparing value of each node...x and y are values of node.
void swapNodes(struct ListNode **head,int x,int y){
	struct ListNode* prev=NULL;
	struct ListNode* prev2=NULL;
	struct ListNode* current=(*head);
	struct ListNode* current2=(*head);
	if(x==y) return;
	if(x==current->data){
		while(current!=NULL && current->data!=y){
			prev=current;
			current=current->next;
		}
		if(current==NULL){
			printf("\n--------There is no node with data %d   ------------------",y);
			return;
		}else if(x==prev->data){
			prev->next=current->next;
			current->next=prev;
			(*head)=current;
		}
		else{
			prev->next=current->next;
			current->next=(*head)->next;
			(*head)->next=prev->next;
			prev->next=(*head);
			(*head)=current;
		}
	}else if(y==current->data){
		while(current!=NULL && current->data!=x){
			prev=current;
			current=current->next;
		}
		if(current==NULL){
			printf("\n--------There is no node with data %d   ------------------\n",x);
			return;
		}else if(y==prev->data){
			prev->next=current->next;
			current->next=prev;
			(*head)=current;
		}else{
			prev->next=current->next;
			current->next=(*head)->next;
			(*head)->next=prev->next;
			prev->next=(*head);
			(*head)=current;
		}
		
		
	}else{
		while(current!=NULL && current->data!=x){
			prev=current;
			current = current->next;
		}
		if(current==NULL){
			printf("\n   There is no node with value %d",x);
			return;
		}
		while(current2!=NULL && current2->data!=y){
			prev2=current2;
			current2=current2->next;
		}
		if(current2==NULL){
			printf("\n   There is no node with value %d",y);
			return;
		}
		if(current==prev2){
			current->next=current2->next;
			current2->next=current;
			prev->next=current2;
		}else if(current2==prev){
			current2->next=current->next;
			current->next=current2;
			prev2->next=current;
		}
		else{
			prev->next=current->next;
			current->next=current2->next;
			current2->next=prev->next;
			prev->next=current2;
			prev2->next=current;
		}
	}
}

int lengthLinkedList(struct ListNode* head){
	int temp;
	if(head==NULL)return 0;
	else{
		temp=lengthLinkedList(head->next);
		return temp+1;
	}
}
void reverseInGroupLinkedList(struct ListNode** head,int k){
	struct ListNode* current=(*head);
	struct ListNode*prev=NULL;
	struct ListNode* next=NULL;
	struct ListNode* tempHead=(*head);
	struct ListNode* tempHeadPrev=NULL;
	while(tempHead){
		for(int i=0;i<k && current;i++){
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
		}
		if(!tempHeadPrev){
			(*head)=prev;
			
		}else if(tempHead!=current){
			tempHeadPrev->next=prev;
		}
		if(tempHead!=current){
			tempHeadPrev=tempHead;
			tempHead=current;
			tempHeadPrev->next=tempHead;
		}
	}
}

int detectLoop(struct ListNode* head){
	
	struct ListNode* slowPtr=head;
	struct ListNode* fastPtr=head;
	while(slowPtr && fastPtr && fastPtr->next){
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr)
			return 1;
	}
	return 0;
}
struct ListNode* findBeginLoop(struct ListNode* head){
	struct ListNode *slowPtr=head,*fastPtr=head;
	int loopExist=0;
	while(fastPtr && slowPtr && fastPtr->next){
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr){
			loopExist=1;
			break;
		}
	}
	if(loopExist){
		slowPtr=head;
		while(slowPtr==fastPtr){
			slowPtr=slowPtr->next;
			fastPtr=fastPtr->next;
		}
		return slowPtr;
	}
	return NULL;
}

int FindLoopLength(struct ListNode* head){
	struct ListNode *slowPtr=head,*fastPtr=head;
	int loopExist=0,counter=1;
	while(fastPtr && slowPtr && fastPtr->next){
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
		if(slowPtr==fastPtr){
			loopExist=1;
			break;
		}
	}
	if(loopExist){
		fastPtr=fastPtr->next;
		while(slowPtr==fastPtr){
			fastPtr=fastPtr->next;
				counter++;
		}
		return counter;
	}
	return 0;
}
void rotateLinkedList(struct ListNode** head,int size){
	int count=0;
	if(size==0)return;
	struct ListNode* current=(*head);
	struct ListNode* oldCurrent=(*head);
	while(current && count<size){
		oldCurrent=current;
		current=current->next;
		count++;
	}
	
	if(current){
		oldCurrent->next=NULL;
		oldCurrent=(*head);
		(*head)=current;
		while(current->next){
			current=current->next;
		}
		current->next=oldCurrent;
	}
	
}
