#include "DQueBT.h"
int FindHeightBinaryTreeNonRecursive(struct BTNodeInt *);

int FindHeightBinaryTreeNonRecursive(struct BTNodeInt *root){
		int level=-1;
		if(root==NULL)return 0;
		struct DynQueueBTNode *Q=NULL;
		Q=createDynQueueBTNode();
		enqueueDynQueueBTNode(Q,root);
		while(!isEmptyDynQueueBTNode(Q)){
			displayDynQueueBTNode(Q);
			root=dequeueDynQueueBTNode(Q);
			if(root==NULL){
				printf("NULL");
				if(!isEmptyDynQueueBTNode(Q)){
					enqueueDynQueueBTNode(Q,NULL);
				}
				level++;
			}
			else{
			
				if(root->left){
					enqueueDynQueueBTNode(Q,root->left);
					//displayDynQueueBTNode(Q);
				}
				//printf("D:%d",Q->array[Q->rear]->data);
				if(root->right){
					enqueueDynQueueBTNode(Q,root->right);
				}
				//printf(" D:%d\n",Q->array[Q->rear]->data);
				
			}
		}
	//deleteQueue(Q);
	return level;
}
int main(){
	
	int i,arr[]={34,2,32,23,786,12,787,45,235,6565,45,341,122,222,333};
	struct BTNodeInt *root=NULL;
	for(i=0;i<15;i++){
		insertInBSTInt(&root,arr[i]);
	}
	//inOrderTraversalInt(root);
	int height=FindHeightBinaryTreeNonRecursive(root);
	printf("\n%d",height);
}
