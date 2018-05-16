#include<stdio.h>
#include<malloc.h>
#include "structMinHeap.h"
void dijkstra(struct GraphAdjListInt *,int );
void initializeSingleSource();
int main(){
	int testCase;
	scanf("%d",&testCase);
	while(testCase--){
	struct  GraphAdjListInt *G=NULL;
	//printf("Enter the no. of Vertice:  ");
	int V;
	scanf("%d",&V);
	//printf("\nEnter the no. of Edges:  ");
	int noOfOldCities;
	scanf("%d",&noOfOldCities);
	int weightOfOldRoad;
	scanf("%d",&weightOfOldRoad);
	int noOfNewRoads;
	scanf("%d",&noOfNewRoads);
	int source;
	scanf("%d",&source);
	G=initializeGraphAdjListInt(V,noOfOldCities,weightOfOldRoad,noOfNewRoads);
	dijkstra(G,source);
	printf("\n");
	for (int i = 0; i <G->V ; i++){
		printf("%d  ",G->adj[i]->distance);
		
	}
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


