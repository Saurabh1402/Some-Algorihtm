#include<stdio.h>
#include<malloc.h>
#include "bstint.h"
struct DynQueueBTNode* createDynQueueBTNode();
int enqueueDynQueueBTNode(struct DynQueueBTNode *,struct BTNodeInt *);
struct DynQueueBTNode* resizeDynQueueBTNode(struct DynQueueBTNode *);
int isEmptyDynQueueBTNode(struct DynQueueBTNode *);
int isFullDynQueueBTNode(struct DynQueueBTNode *);
int sizeDynQueueBTNode(struct DynQueueBTNode *);
void displayDynQueueBTNode(struct DynQueueBTNode *);
struct BTNodeInt * dequeueDynQueueBTNode(struct DynQueueBTNode *);
struct BTNodeInt* getTopDynQueueBTNode(struct DynQueueBTNode *);
void deleteQueue(struct DynQueueBTNode *);
struct DynQueueBTNode{
	struct BTNodeInt **array;
	int capacity;
	int front,rear;
};

/*
	int main(){
	struct DynQueueBTNode *Q=createDynQueueBTNode();
	struct BTNodeInt *root=NULL,*temp=NULL;
	int i,arr[]={34,2,32,23,76,12,787,45,235,6565,45,341,122,222,333};
	for(i=0;i<15;i++){
		insertInBSTInt(&root,arr[i]);
	}
	//inOrderTraversalInt(root);
	for(i=0;i<15;i++){
		temp=findNodeInt(root,arr[i]);
		enqueueDynQueueBTNode(Q,temp);
		//printf("%d %d\t",sizeDynQueueBTNode(Q),Q->capacity);
	}
	displayDynQueueBTNode(Q);
	printf("\n%d\t%d",dequeueDynQueueBTNode(Q)->data,getTopDynQueueBTNode(Q)->data);
	displayDynQueueBTNode(Q);
	return 0;
}
 */
struct DynQueueBTNode* createDynQueueBTNode(){
		struct DynQueueBTNode *temp=NULL;
		temp=(struct DynQueueBTNode*)malloc(sizeof(struct DynQueueBTNode));
		if(!temp){
			printf("Memory Error:Line 13");
			return NULL;
		}
		temp->capacity=1;
		temp->front=temp->rear=-1;
		temp->array=(struct BTNodeInt **)malloc(sizeof(struct BTNodeInt)*temp->capacity);
		if(!temp->array){
			printf("Memory Error:Line 13");
			return NULL;
		}
		return temp;

}

int isEmptyDynQueueBTNode(struct DynQueueBTNode *Q){
	if(Q!=NULL)
		return Q->front==-1;
	return -1;
}
int isFullDynQueueBTNode(struct DynQueueBTNode *Q){
	if(Q!=NULL){
		if((Q->rear+1)%Q->capacity==Q->front)return 1;
		else return 0;
	}
	return -1;
}
int sizeDynQueueBTNode(struct DynQueueBTNode *Q){
	if(Q==NULL) return -1;
	if(isEmptyDynQueueBTNode(Q)==1){
		return 0;
		}
	if(isFullDynQueueBTNode(Q)==1){
			return Q->capacity;
	}
	else{
		
		return (Q->capacity+Q->rear-Q->front+1)%Q->capacity;
		}

}

int enqueueDynQueueBTNode(struct DynQueueBTNode *Q,struct BTNodeInt *node){
	if(Q==NULL) return -1;
	if(isFullDynQueueBTNode(Q)==1){
		Q=resizeDynQueueBTNode(Q);
	}
	
	if(isEmptyDynQueueBTNode(Q)==1)
		Q->front=Q->rear=0;
	else
		Q->rear=(Q->rear+1)%Q->capacity;
	Q->array[Q->rear]=node;
	return 1; 

}
struct DynQueueBTNode* resizeDynQueueBTNode(struct DynQueueBTNode *Q){
		int new_capacity,old_capacity,i;
		
		struct BTNodeInt **arr=NULL;
		old_capacity=Q->capacity;
		new_capacity=old_capacity*2;
		arr=Q->array;
		Q->array=(struct BTNodeInt**)malloc(sizeof(struct BTNodeInt)*new_capacity);
		for(i=0;i<old_capacity;i++){
				Q->array[i]=arr[i];
		}
		Q->capacity=new_capacity;
		return Q;
		
}
void displayDynQueueBTNode(struct DynQueueBTNode *Q){
		int i;
		if(Q==NULL){
			printf("NULL Exception: LINE:: 87");
			return;
		}
		i=Q->front;
		printf("\nQueue: ");
		if(sizeDynQueueBTNode(Q)==1){
			if(Q->array[Q->front]!=NULL){
			printf("%d ",Q->array[Q->front]->data);
			}else{
				printf("1= ");
			}
			return;
		}
		do{
			if(Q->array[i]!=NULL)
			printf("%d ",Q->array[i]->data);
			else
			printf("2= ");
			i=(i+1+Q->capacity)%Q->capacity;
		}while(i!=Q->rear);
			if(Q->array[Q->rear]!=NULL)
			printf("%d ",Q->array[Q->rear]->data);
			else
			printf("3= ");
		
}
struct BTNodeInt * dequeueDynQueueBTNode(struct DynQueueBTNode *Q){
		if(Q==NULL){
			printf("NULL Pointer Exception:LINE::112");
			return NULL;
			}
		if(isEmptyDynQueueBTNode(Q)==1){
			printf("Queue UnderFlow: LINE:: 112");
			return NULL;
		}
		struct BTNodeInt *node=Q->array[Q->front];
		if(Q->front==Q->rear)Q->front=Q->rear=-1;
		else Q->front=(Q->front+1)%Q->capacity;
		return node;
}
struct BTNodeInt* getTopDynQueueBTNode(struct DynQueueBTNode *Q){
		if(Q==NULL){
			printf("NULL Pointer Exception:LINE::112");
			return NULL;
		}
		if(isEmptyDynQueueBTNode(Q)==1){
			printf("Queue UnderFlow: LINE:: 112");
			return NULL;
		}
		struct BTNodeInt *node=Q->array[Q->front];
		return node;
}
void deleteQueue(struct DynQueueBTNode *Q){
	if(Q){
		if(Q->array)
			free(Q->array);
		free(Q);
	}
}
