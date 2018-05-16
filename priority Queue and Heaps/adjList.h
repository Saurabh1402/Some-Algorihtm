#include<stdio.h>
#include "SimLList.h"
#define INT_MAX 32000
struct GraphAdjListInt* initializeGraphAdjListInt();
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

struct GraphAdjListInt* initializeGraphAdjListInt(){
	int i,j,x,y,weight,flagWeighted,flagDirected;	
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
	G->adj=(struct AdjListInt**)malloc(sizeof(struct AdjListInt)*G->V);
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
	
	
	
	G->weight=(int *)malloc(sizeof(int) * G->V*G->V);
	
	if(G->weight==NULL){
			printf("Memory Error: LINE::44");
			return NULL;
	}
	for (i = 0; i < G->V; i++)
		{
			for (j = 0; j <G->V ; j++)
			{
				*(G->weight + G->V*i+j)=-1;
			}	
		}
		
	initializeSingleSource(G);
	printf("\n1->For Weighted\n2->For Unweighted\nPress Key..	");
	scanf("%d",&flagWeighted);
	printf("\n1->For Directed\n2->For Undirected\nPress Key..	");
	scanf("%d",&flagDirected);
	
	for(i=0;i<G->E;i++){
		if(flagWeighted==2){
			printf("Enter the vertices at the end of %d Edges ",i+1);
			scanf("%d %d",&x,&y);
		}
		else if(flagWeighted==1){
			printf("Enter the vertices at the end of %d Edges with Weight",i+1);
		scanf("%d %d %d",&x,&y,&weight);
		
		}
		else{
			printf("LINE 59::Wrong Input For Weighted OR Unweighted");
			return NULL;
		}
		if(x>G->V||y>G->V){
			printf("Wrong Input. Please Try Again:");
			i--;
			continue;
		}
		x--;
		y--;
		
		if(flagWeighted==1){
			*(G->weight+G->V*x+y)=weight;
			if(flagDirected==2){
				*(G->weight+G->V*y+x)=weight;
			}
		}
		
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[x]->list,y);
		if(flagDirected==2)
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
