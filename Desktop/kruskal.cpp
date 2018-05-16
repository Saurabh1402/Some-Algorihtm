#include<stdio.h>
#include<malloc.h>
struct SimpleLinkedListInt * uniqueInsertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **,int,int );

void quickSortInt(int *,int*,int *,int ,int );
int partitionQuickSortInt(int*,int*,int *,int ,int);

void kruskal_mst(struct GraphAdjListInt *);
void setWeight(struct GraphAdjListInt*, int *,int *,int *);

void makeSet(int[],int );
int findSet(int[],int,int);
void unionSet(int[],int,int,int);
struct GraphAdjListInt* initializeGraphAdjListInt();

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


struct SimpleLinkedListInt{
	int data;
	int weight;
	struct SimpleLinkedListInt *next;
};
int main(){
	struct GraphAdjListInt *G=NULL;
	G=initializeGraphAdjListInt();
	kruskal_mst(G);
	return 0;
}
void makeSet(int S[],int size){
		int i;
		for (i = 0; i <size; i++)
		{
			S[i]=i;
		}
}
int findSet(int S[],int size,int x){
	if(!(x>=0 && x <size))
		return -1;
	if(S[x]==x)
		return x;
	else
		return findSet(S,size,S[x]);
}
void unionSet(int S[],int size,int index1,int index2){
	if(findSet(S,size,index1)==findSet(S,size,index2))
		return;
	if(!((index1>=0 && index1<size) && (index2>=0 && index2<size)))
		return;
	S[findSet(S,size,index1)]=findSet(S,size,index2);
	
}

struct SimpleLinkedListInt * uniqueInsertAtEndSimpleLinkedListInt(struct SimpleLinkedListInt **proot,int data,int weight){
	struct SimpleLinkedListInt *newNode=(struct SimpleLinkedListInt *)malloc(sizeof(struct SimpleLinkedListInt));
	if(newNode==NULL){
			return NULL;
	}
	struct SimpleLinkedListInt *root=*proot;
	newNode->data=data;
	newNode->weight=weight;
	newNode->next=NULL;
	if(root==NULL) *proot=newNode;
	else {
	while(root->next!=NULL){
		if(root->data==data){
			return *proot;
		}
		root=root->next;
			
	}
	root->next=newNode;
	}
	return *proot;
}
void quickSortInt(int *src,int *dst,int *ar,int p,int r){
	int q;
	if(p<r){
		q=partitionQuickSortInt(src,dst,ar,p,r);
		quickSortInt(src,dst,ar,p,q-1);
		quickSortInt(src,dst,ar,q+1,r);
	}
}
int partitionQuickSortInt(int *src,int *dst,int *a,int p,int r){
	int i=p-1,j;
	int temp,pivot=a[r];
	for(i=p-1,j=p;j<r;j++){

		if(a[j]<=pivot){
		  i++;
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;
		  temp=src[i];
		  src[i]=src[j];
		  src[j]=temp;
		  temp=dst[i];
		  dst[i]=dst[j];
		  dst[j]=temp;
		  
		}

	}
	i++;
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	temp=src[i];
	src[i]=src[j];
	src[j]=temp;
	temp=dst[i];
	dst[i]=dst[j];
	dst[j]=temp;
		  
	return i;
}
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
	int sum=0;
	for (int i = 0; i <G->V-1 ; i++)
	{
		sum+=weight[sp_edge[i]];
	}
	printf("%d",sum);	
		
}
struct GraphAdjListInt* initializeGraphAdjListInt(){
	int i,x,y,weight;	
	struct GraphAdjListInt* G=NULL;
	G=(struct GraphAdjListInt*)malloc(sizeof(struct GraphAdjListInt));
	if(G==NULL){
			return NULL;
	}
	scanf("%d",&G->V);
	scanf("%d",&G->E);
	G->adj=(struct AdjListInt**)malloc(sizeof(struct AdjListInt*)*G->V);
	if(G->adj==NULL){
			return NULL;
	}
	for(i=0;i<G->V;i++){
		G->adj[i]=(struct AdjListInt*)malloc(sizeof(struct AdjListInt));
		if(G->adj[i]==NULL){
			return NULL;
		}
	}
	
	for (i = 0; i <G->V ; i++)
	{
		G->adj[i]->data=i;
	}
	
	
	G->directed=1;
	
	for(i=0;i<G->E;i++){
			scanf("%d %d %d",&x,&y,&weight);
		if(x>G->V||y>G->V){
			i--;
			continue;
		}
		x--;
		y--;
		uniqueInsertAtEndSimpleLinkedListInt(&G->adj[x]->list,y,weight);
		}
	return G;
}
