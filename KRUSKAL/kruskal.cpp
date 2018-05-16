#include<stdio.h>
#include<malloc.h>
#include "adjList.h"
#include "qsort.h"
#include "disset.h"
void kruskal_mst(struct GraphAdjListInt *);
void setWeight(struct GraphAdjListInt* G, int *source,int *destination,int *weight){
	int i,counter=0;	
	struct SimpleLinkedListInt *temp=NULL;
	for(i=0;i<G->V;i++){
		temp=G->adj[i]->list;
		while(temp!=NULL)
		{
			weight[counter]=temp->weight;
			source[counter]=i;
			destination[counter]=temp->data;
			counter++;
			temp=temp->next;
		}
	}
}
int main(){
	struct GraphAdjListInt *G=NULL;
	G=initializeGraphAdjListInt();
	kruskal_mst(G);
	return 0;
}

void kruskal_mst(struct GraphAdjListInt *G){
	int *sp_edge,counter=0;
	int *S,*source,*destination,*weight;
	S=(int*)malloc(sizeof(int)*G->V);
	sp_edge=(int*)malloc(sizeof(int)*(G->V-1));
	if(G->directed==1){
		source=(int*)malloc(sizeof(int)*G->E);
		destination=(int*)malloc(sizeof(int)*G->E);
		weight=(int*)malloc(sizeof(int)*G->E);
	}else {
		source=(int*)malloc(sizeof(int)*G->E*2);
		destination=(int*)malloc(sizeof(int)*G->E*2);
		weight=(int*)malloc(sizeof(int)*G->E*2);
	}
	setWeight(G,source,destination,weight);
	if(G->directed==1)
		quickSortInt(source,destination,weight,0,G->E-1);
	else if(G->directed==2)
		quickSortInt(source,destination,weight,0,G->E*2-1);
	makeSet(S,G->V);
	
	if(G->directed==1){
		for (int i = 0; i <G->E ; i++)
		{
			if(findSet(S,G->V,source[i])!=findSet(S,G->V,destination[i])){
				unionSet(S,G->V,source[i],destination[i]);
				sp_edge[counter]=i;
				counter++;
			}
		}
	}else{
		for (int i = 0; i <G->E*2 ; i++)
		{	
			if(findSet(S,G->V,source[i])!=findSet(S,G->V,destination[i])){
				unionSet(S,G->V,source[i],destination[i]);
				sp_edge[counter]=i;
				counter++;
			}
		}
	}
		
	for (int i = 0; i <G->V-1 ; i++)
	{
		printf("%c || %c\n",65+source[sp_edge[i]],65+destination[sp_edge[i]]);
	}
			
}
