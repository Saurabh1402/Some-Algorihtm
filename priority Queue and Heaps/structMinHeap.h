#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "adjList.h"
struct StructMinHeap* createHeapStructMinHeap(int);
int parentStructMinHeap(struct StructMinHeap*,int);
int leftChildStructMinHeap(struct StructMinHeap*,int);
int rightChildStructMinHeap(struct StructMinHeap* ,int);
struct AdjListInt* getMinStructMinHeap(struct StructMinHeap* h);
struct AdjListInt* ExtractMinStructMinHeap(struct StructMinHeap* h);
void perlocateDownStructMinHeap(struct StructMinHeap *,int);
void insertInHeapStructMinHeap(struct StructMinHeap*,struct AdjListInt *);
void resizeHeapSizeStructMinHeap(struct StructMinHeap *);
void insertFromGraphToMinHeap(struct StructMinHeap *,struct GraphAdjListInt *);
void displayStructMinHeap(struct StructMinHeap *);
struct StructMinHeap{
	 struct AdjListInt **array;
	int count;
	int capacity;
};
	/*
		int main(){
					int i=0;
					struct GraphAdjListInt *G=NULL;
					struct StructMinHeap *h=NULL;
					G=initializeGraphAdjListInt();
					displayGraphAdjListInt(G);
					h=createHeapStructMinHeap(G->V);
					insertFromGraphToMinHeap(h,G);
					printf("\n---------------------------------------\n");
					for(i=0;i<h->count;i++){
						printf("%d::%d  ",h->array[i]->data,h->array[i]->distance);
					}
					printf("\n%d ",getMinStructMinHeap(h)->distance);
					printf("\n%d ",ExtractMinStructMinHeap(h)->distance);
					printf("\n%d ",ExtractMinStructMinHeap(h)->distance);
					printf("\n---------------------------------------\n");
					for(i=0;i<h->count;i++){
						printf("%d::%d  ",h->array[i]->data,h->array[i]->distance);
					}

					return 0;
		}
	*/

struct StructMinHeap* createHeapStructMinHeap(int capacity){
	struct StructMinHeap* h=(struct StructMinHeap*)malloc(sizeof(struct StructMinHeap));
	if(h==NULL){
		printf("Memory Error: line: 14");
		return NULL;
	}
	h->count=0;
	h->capacity=capacity;
	h->array=(struct AdjListInt **)malloc(sizeof(struct  AdjListInt)*capacity);
	if(h->array==NULL){
		printf("Memory Error: line: 14");
		//return NULL;
	}
	return h;
}
int isEmptyStructMinHeap(struct StructMinHeap *h){
	return h->count==0;
}
int parentStructMinHeap(struct StructMinHeap *h,int c){
	int p=(c-1)/2;
	if(p<0||c<=0||c>=h->count)
		return -1;
	return p;

}
int leftChildStructMinHeap(struct StructMinHeap *h,int p){
	int c=p*2+1;
	if(h->count<=c)
		return -1;
	return c;

}
int rightChildStructMinHeap(struct StructMinHeap* h,int p){
	int c=2*p+2;
	if(h->count<=c){
		return -1;
	}
	return c;
	}
struct AdjListInt* getMinStructMinHeap(struct StructMinHeap *h){
	if(h==NULL){
		printf("line:42	|  NULL EXCEPTION");
		return NULL;
	}
	if(h->count==0){
	printf("line: 46 |  No Element");
	return NULL;
	}
	return h->array[0];
}

struct AdjListInt* ExtractMinStructMinHeap(struct StructMinHeap *h){
	struct AdjListInt *data;
	if(h==NULL){
		printf("line: 54 |  NULL Exception");
		return NULL;
	}

	if(h->count==0){
		printf("line : 59|    	No Element");
		return NULL;
	}
	data=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	perlocateDownStructMinHeap(h,0);
	return data;
}

void perlocateDownStructMinHeap(struct StructMinHeap *h,int index){
int l,r,min=-1;
struct AdjListInt *temp=NULL;
l=leftChildStructMinHeap(h,index);
r=rightChildStructMinHeap(h,index);
	if(l!=-1 && h->array[index]->distance > h->array[l]->distance){
		min=l;
	}
	else{
	min=index;
	}
	if(r!=-1 && h->array[min]->distance > h->array[r]->distance){
		min=r;
	}
	if(min!=index){
		temp=h->array[index];
		h->array[index]=h->array[min];
		h->array[min]=temp;
		
		perlocateDownStructMinHeap(h,min);
	}

}

void insertInHeapStructMinHeap(struct StructMinHeap *h,struct AdjListInt *data){
	int i;
	if(h->count==h->capacity){
		resizeHeapSizeStructMinHeap(h);
	}
	h->count++;
	i=h->count-1;
	h->array[i]=data;
	while(i>0 && data->distance < h->array[(i-1)/2]->distance){
	     h->array[i]=h->array[(i-1)/2];
	     i=(i-1)/2;
	}
	h->array[i]=data;

}
void resizeHeapSizeStructMinHeap(struct StructMinHeap *h){
	int i,new_capacity,old_capacity;
	struct AdjListInt **array=h->array;
	old_capacity=h->capacity;
	new_capacity=old_capacity*2;
	h->array=(struct AdjListInt **)malloc(sizeof(struct AdjListInt)*new_capacity);
	for(i=0;i<old_capacity;i++)
		h->array[i]=array[i];
	h->capacity=new_capacity;
	free(array);
}

void insertFromGraphToMinHeap(struct StructMinHeap *h,struct GraphAdjListInt *G){
	struct AdjListInt *temp=NULL;
	if(h==NULL){
		h=createHeapStructMinHeap(G->V);
	}
	int i;	
	printf("\n");
	for(i=0;i<G->V;i++){
		temp=G->adj[i];
		insertInHeapStructMinHeap(h,temp);
		printf("\n");
	}
}
void displayStructMinHeap(struct StructMinHeap *h){
	int i;
	if(isEmptyStructMinHeap(h)){
		printf("\nheap is Empty\n");
		return;
	}
	for (i = 0; i < h->count; i++)
	{
		printf("%d ",h->array[i]->data);
	}
	
}
