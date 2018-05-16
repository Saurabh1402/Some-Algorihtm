#include<stdio.h>
#include "SimLList.h"
#define INT_MAX 32000
struct GraphAdjListInt* initializeGraphAdjListInt(int,int,int,int);
void displayGraphAdjListInt(struct GraphAdjListInt *);
void initializeSingleSource(struct GraphAdjListInt *);
void displayWeightOfGraph(struct GraphAdjListInt *);
struct AdjListInt{
	struct SimpleLinkedListInt *list;
	int data;
	int distance;
	int parent;
};
struct AdjMatInt{
		int data;
		int distance;
		int *list;
};
struct GraphAdjListInt{
		int V;
		int *weight;
		int E;
		struct AdjListInt **adj;
};

struct GraphAdjListInt* initializeGraphAdjListInt(int vertices,int oldCities,int weightOfOldCities,int newCities){
	int i,j,x,y,weight;	
	struct GraphAdjListInt* G=NULL;
	G=(struct GraphAdjListInt*)malloc(sizeof(struct GraphAdjListInt));
	G->V=vertices;
	G->E=oldCities*(oldCities-1)/2+newCities;
	G->adj=(struct AdjListInt**)malloc(sizeof(struct AdjListInt)*G->V);
	for(i=0;i<G->V;i++){
		G->adj[i]=(struct AdjListInt*)malloc(sizeof(struct AdjListInt));
	}
	G->weight=(int *)malloc(sizeof(int) * G->V*G->V);
	
	for (i = 0; i < G->V; i++)
		{
			for (j = 0; j <G->V ; j++)
			{
				*(G->weight + G->V*i+j)=-1;
			}	
		}
		
	initializeSingleSource(G);
	for(i=0;i<oldCities;i++){
		for (j = 0; j <oldCities ; j++)
		{
		if(i==j)continue;
		*(G->weight+G->V*i+j)=weightOfOldCities;
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[i]->list,j);
		}
	}
	for (i = 0; i <newCities ; i++)
	{
		scanf("%d%d%d",&x,&y,&weight);
		x--;
		y--;
		*(G->weight+G->V*x+y)=weight;
		*(G->weight+G->V*y+x)=weight;
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[x]->list,y);
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[y]->list,x);
		
	}
	
	
	return G;
}
void initializeSingleSource(struct GraphAdjListInt *G){
	int i;
		for(i=0;i<G->V;i++){
		G->adj[i]->data=i;
		G->adj[i]->parent=-1;
		G->adj[i]->distance=INT_MAX;
	}
	
}
void displayGraphAdjListInt(struct GraphAdjListInt *G){
	struct SimpleLinkedListInt *temp=NULL;
	int i;	
	printf("\n");
	for(i=0;i<G->V;i++){
		printf("%d :: ",i+1);
		temp=G->adj[i]->list;
		while(temp!=NULL){
			printf("->%d",temp->data+1);
			temp=temp->next;
		}
		printf("\n");
	}
	printf("\n-------------------------------\n");
}
void displayWeightOfGraph(struct GraphAdjListInt *G){
		int i,j;
		printf("\n-----------------Display Weight----------------------\n");
		for (i = 0; i < G->V; i++)
		{
			for (j = 0; j <G->V ; j++)
			{
				printf("%2d ",*(G->weight + G->V*i+j));
			}
			printf("\n");	
		}
		printf("\n-----------------------------------------------------\n");
}
