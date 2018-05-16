#include<stdio.h>
#include<malloc.h>
#include "adjList.h"

void DFS(struct GraphAdjListInt *);
void DFS_VISIT(struct GraphAdjListInt *,int );
int *color;//0->WHITE::1->GRAY::2->BLACK
int timeDFS;
int main(){
	int i=0;
	struct GraphAdjListInt *G=initializeGraphAdjListInt();
	if(G!=NULL){
		DFS(G);
		
	}
	
	for(i=0;i<G->V;i++){
			printf("D-> %2d || F-> %2d \n",G->adj[i]->discovery,G->adj[i]->finish);
	}
	for(i=0;i<G->V;i++){
			if(G->adj[i]->parent==-1)
			printf("%c || -- \n",G->adj[i]->data+65+18);
			else
			printf("%c || %c \n",G->adj[i]->data+65+18,G->adj[i]->parent+65+18);
	}
	return 0;
}
void DFS(struct GraphAdjListInt *G){
	int i;
	color=(int *)malloc(sizeof(int) *G->V);
		for ( i = 0; i < G->V; i++)
		{
			color[i]=0;//WHITE
		}	
	initializeSingleSource(G);
	timeDFS=0;
	for (i = 0; i <G->V; i++)
	{
		if(color[i]==0){
				DFS_VISIT(G,i);
		}
	}
	
}
void DFS_VISIT(struct GraphAdjListInt *G,int u){
	struct SimpleLinkedListInt *v=NULL;
	color[u]=1;
	timeDFS++;
	G->adj[u]->discovery=timeDFS;
	v=G->adj[u]->list;
	while(v!=NULL){
		if(color[v->data]==0){
			G->adj[v->data]->parent=u;
			DFS_VISIT(G,v->data);
		}
		v=v->next;
	}
	color[u]=2;//BLACK
	timeDFS++;
	G->adj[u]->finish=timeDFS;
	

}
void displayParenthesiStructure(){
	
}
