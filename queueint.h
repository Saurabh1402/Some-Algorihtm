#include<stdio.h>
#include<malloc.h>
#include "bstint.h"
struct DynQueueInt* createDynQueueInt();
int enqueueDynQueueInt(struct DynQueueInt *,int );
struct DynQueueInt* resizeDynQueueInt(struct DynQueueInt *);
int isEmptyDynQueueInt(struct DynQueueInt *);
int isFullDynQueueInt(struct DynQueueInt *);
int sizeDynQueueInt(struct DynQueueInt *);
void displayDynQueueInt(struct DynQueueInt *);
int  dequeueDynQueueInt(struct DynQueueInt *);
int  getTopDynQueueInt(struct DynQueueInt *);
void deleteQueue(struct DynQueueInt *);
struct DynQueueInt{
	int *array;
	int capacity;
	int front,rear;
};

			/*
				int main(){
				struct DynQueueInt *Q=createDynQueueInt();
				int i,arr[]={34,2,32,23,76,12,787,45,235,6565,45,341,122,222,333,1212,555,4232,12,353};
				for(i=0;i<20;i++){
					enqueueDynQueueInt(Q,arr[i]);
					printf("%d %d \n",sizeDynQueueInt(Q),Q->capacity);
				}
				displayDynQueueInt(Q);
				printf("\n%d\t%d",dequeueDynQueueInt(Q),getTopDynQueueInt(Q));
				displayDynQueueInt(Q);
				return 0;
				}
			*/
struct DynQueueInt* createDynQueueInt(){
		struct DynQueueInt *temp=NULL;
		temp=(struct DynQueueInt*)malloc(sizeof(struct DynQueueInt));
		if(!temp){
			printf("Memory Error:Line 13");
			return NULL;
		}
		temp->capacity=1;
		temp->front=temp->rear=-1;
		temp->array=(int *)malloc(sizeof(int)*temp->capacity);
		if(!temp->array){
			printf("Memory Error:Line 13");
			return NULL;
		}
		return temp;

}

int isEmptyDynQueueInt(struct DynQueueInt *Q){
	if(Q!=NULL)
		return Q->front==-1;
	return -1;
}
int isFullDynQueueInt(struct DynQueueInt *Q){
	if(Q!=NULL){
		if((Q->rear+1)%Q->capacity==Q->front)return 1;
		else return 0;
	}
	return -1;
}
int sizeDynQueueInt(struct DynQueueInt *Q){
	if(Q==NULL) return -1;
	if(isEmptyDynQueueInt(Q)==1){
		return 0;
		}
	if(isFullDynQueueInt(Q)==1){
			return Q->capacity;
	}
	else{
		
		return (Q->capacity+Q->rear-Q->front+1)%Q->capacity;
	}

}

int enqueueDynQueueInt(struct DynQueueInt *Q,int node){
	if(Q==NULL) return -1;
	if(isFullDynQueueInt(Q)==1){
		Q=resizeDynQueueInt(Q);
	}
	
	if(isEmptyDynQueueInt(Q)==1)
		Q->front=Q->rear=0;
	else
		Q->rear=(Q->rear+1)%Q->capacity;
	Q->array[Q->rear]=node;
	return 1; 

}
struct DynQueueInt* resizeDynQueueInt(struct DynQueueInt *Q){
		int new_capacity,old_capacity,i;
		
		int *arr=NULL;
		old_capacity=Q->capacity;
		new_capacity=old_capacity*2;
		arr=Q->array;
		Q->array=(int *)malloc(sizeof(struct BTNodeInt)*new_capacity);
		for(i=0;i<old_capacity;i++){
				Q->array[i]=arr[i];
		}
		Q->capacity=new_capacity;
		return Q;
		
}
void displayDynQueueInt(struct DynQueueInt *Q){
		int i;
		if(Q==NULL){
			printf("NULL Exception: LINE:: 87");
			return;
		}
		i=Q->front;
		printf("\nQueue: ");
		if(sizeDynQueueInt(Q)==1){
			printf("%d",Q->array[Q->front]);
			return;
		}
		do{
			printf("%d ",Q->array[i]);
			i=(i+1+Q->capacity)%Q->capacity;
		}while(i!=Q->rear);
			printf("%d ",Q->array[Q->rear]);
				
}
int  dequeueDynQueueInt(struct DynQueueInt *Q){
		if(Q==NULL){
			printf("NULL Pointer Exception:LINE::112");
			return -1;
			}
		if(isEmptyDynQueueInt(Q)==1){
			printf("Queue UnderFlow: LINE:: 112");
			return -1;
		}
		int node=Q->array[Q->front];
		if(Q->front==Q->rear)Q->front=Q->rear=-1;
		else Q->front=(Q->front+1)%Q->capacity;
		return node;
}
int getTopDynQueueInt(struct DynQueueInt *Q){
		if(Q==NULL){
			printf("NULL Pointer Exception:LINE::112");
			return -1;
		}
		if(isEmptyDynQueueInt(Q)==1){
			printf("Queue UnderFlow: LINE:: 112");
			return -1;
		}
		int node=Q->array[Q->front];
		return node;
}
void deleteQueue(struct DynQueueInt *Q){
	if(Q){
		if(Q->array)
			free(Q->array);
		free(Q);
	}
}
