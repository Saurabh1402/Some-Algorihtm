#include<stdio.h>
#include "SimLList.h"
#include<limits.h>
struct GraphAdjListInt* initializeGraphAdjListInt();
void displayGraphAdjListInt(struct GraphAdjListInt *);
void initializeSingleSource(struct GraphAdjListInt *);
void displayWeightOfGraph(struct GraphAdjListInt *,int[],int[],int[]);
struct AdjListInt{
	struct SimpleLinkedListInt *list;
	int data;
};
struct GraphAdjListInt{
		int V;
		int E;
		int directed;//1-->For directed 2-->for Undirected
		struct AdjListInt **adj;
};

struct GraphAdjListInt* initializeGraphAdjListInt(){
	int i,x,y,weight,flagDirected;	
	struct GraphAdjListInt* G=NULL;
	G=(struct GraphAdjListInt*)malloc(sizeof(struct GraphAdjListInt));
	if(G==NULL){
			printf("Memory Error: LINE::30");
			return NULL;
	}
	printf("Enter the no. of Vertice:  ");
	scanf("%d",&G->V);
	printf("\nEnter the no. of Edges:  ");
	scanf("%d",&G->E);
	G->adj=(struct AdjListInt**)malloc(sizeof(struct AdjListInt*)*G->V);
	if(G->adj==NULL){
			printf("Memory Error: LINE::39");
			return NULL;
	}
	for(i=0;i<G->V;i++){
		G->adj[i]=(struct AdjListInt*)malloc(sizeof(struct AdjListInt));
		if(G->adj[i]==NULL){
			printf("Memory Error: LINE::50");
			return NULL;
		}
	}
	
	for (i = 0; i <G->V ; i++)
	{
		G->adj[i]->data=i;
	}
	
	
	
	printf("\n1->For Directed\n2->For Undirected\nPress Key..	");
	scanf("%d",&flagDirected);
	
	G->directed=flagDirected;
	
	for(i=0;i<G->E;i++){
			printf("Enter the vertices at the end of %d Edges with Weight",i+1);
			scanf("%d %d %d",&x,&y,&weight);
		if(x>G->V||y>G->V){
			printf("Wrong Input. Please Try Again:");
			i--;
			continue;
		}
		x--;
		y--;
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[x]->list,y,weight);
		if(flagDirected==2)
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[y]->list,x,weight);
	}
	return G;
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
void displayWeightOfGraph(struct GraphAdjListInt *G,int source[],int destination[],int weight[]){
		int j;
		printf("\n-----------------Display Weight----------------------\n");
			for (j = 0; j <G->E ; j++)
			{
				printf("%2d %2d %2d",source[j],destination[j],weight[j]);
			}
		printf("\n-----------------------------------------------------\n");
}
