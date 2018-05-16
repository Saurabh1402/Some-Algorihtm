#include<stdio.h>
#include<malloc.h>
#include "structMinHeap.h"
void dijkstra(struct GraphAdjListInt *,int );
void initializeSingleSource();
int main(){
	struct  GraphAdjListInt *G=NULL;
	G=initializeGraphAdjListInt();
	int i=0;
	dijkstra(G,2);
	for (i = 0; i <G->V ; i++){
		printf("|  %c  ||  %d  |  %c  |\n",65+G->adj[i]->data,G->adj[i]->distance,G->adj[i]->parent+65);
		
	}
	return 0;
}
void dijkstra(struct GraphAdjListInt *G,int s){
	 struct StructMinHeap *priority_queue=createHeapStructMinHeap(G->V);
	 struct AdjListInt *temp=NULL;
	 struct SimpleLinkedListInt* tempList=NULL;
	 int i,distance,flagForheap=0;
	 initializeSingleSource(G);
	 G->adj[s]->distance=0;
	 insertInHeapStructMinHeap(priority_queue,G->adj[s]);
	 displayWeightOfGraph(G);
	 while(!(isEmptyStructMinHeap(priority_queue))){
		temp=ExtractMinStructMinHeap(priority_queue);
		tempList=temp->list;
		while(tempList!=NULL){
			distance=temp->distance +  *(G->weight+temp->data*G->V+tempList->data);
			if(distance < G->adj[tempList->data]->distance){
				G->adj[tempList->data]->distance=distance;
				G->adj[tempList->data]->parent=temp->data;
				flagForheap=1;
				for (i = 0; i <priority_queue->count ; i++){
					if(G->adj[tempList->data]->data==priority_queue->array[i]->data){
						flagForheap=0;
					}
				}
				if(flagForheap==1){
						insertInHeapStructMinHeap(priority_queue,G->adj[tempList->data]);
				}
					
			}
			tempList=tempList->next;
		}
		
	 }
}


