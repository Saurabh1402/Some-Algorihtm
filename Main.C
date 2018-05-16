#include<stdio.h>
#include<malloc.h>
#include "DQueBT.h"
int main(){
	struct DynQueueBTNode *Q=createDynQueueBTNode();
	struct BTNodeInt *root=NULL,*temp=NULL;
	int i,arr[]={34,2,32,23,76,12,787,45,235,6565,45,341,122,222,333};
	for(i=0;i<15;i++){
		insertInBSTInt(&root,arr[i]);
	}
	//inOrderTraversalInt(root);
	for(i=0;i<15;i++){
		temp=findNodeInt(root,arr[i]);
		enqueueDynQueueBTNode(Q,temp);
		//printf("%d %d\t",sizeDynQueueBTNode(Q),Q->capacity);
	}
	displayDynQueueBTNode(Q);
	printf("\n%d\t%d",dequeueDynQueueBTNode(Q)->data,getTopDynQueueBTNode(Q)->data);
	displayDynQueueBTNode(Q);
	return 0;
}
