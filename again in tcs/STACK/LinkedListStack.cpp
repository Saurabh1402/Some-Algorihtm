#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct LinkedListStack{
	int data;
	struct LinkedListStack *next;
};
struct LinkedListStack* createStack(){
	return NULL;
}
int isEmptyStack(struct LinkedListStack* stack){
	return stack==NULL;
}
void pushStack(struct LinkedListStack** stack,int data){
	struct LinkedListStack* newNode=(struct LinkedListStack*)malloc(sizeof(struct LinkedListStack));
	if(!newNode){
		printf("\n-----------Unable to push data due to insufficient Storage----------\n");
		return;
	}
	newNode->data=data;
	newNode->next=(*stack);
	(*stack)=newNode;
}
int popStack(struct LinkedListStack** stack){
	if(isEmptyStack((*stack))){
		printf("\nUnderflow: Stack is Empty\n");
		return INT_MIN;
	}
	else{
		struct LinkedListStack* temp=(*stack);
		int data=temp->data;
		(*stack)=(*stack)->next;
		free(temp);
		return data;
	}
}
int topStack(struct LinkedListStack* stack){
	if(isEmptyStack(stack)){
		printf("\nUnderflow: Stack is Empty\n");
		return INT_MIN;
	}
	else{
		
		return stack->data;
	}
}
void deleteStack(struct LinkedListStack** stack){
	struct LinkedListStack* temp=NULL;
	while((*stack)!=NULL){
		temp=(*stack);
		(*stack)=(*stack)->next;
		free(temp);
	}
}
void displayStack(struct LinkedListStack* stack){
	if(stack==NULL)return;
	displayStack(stack->next);
	printf("%d-->",stack->data);
}
int main(){
	struct LinkedListStack* stack=NULL;
	int data,choice,pop;
	
	stack=createStack();
	while(1){
	printf("\n1-->Push to Stack\n2-->Pop from Stack\n3-->Display Stack \n4-->Delete Stack\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Data to Push");
				scanf("%d",&data);
				pushStack(&stack,data);
				break;
			case 2:
				pop=popStack(&stack);
				if(pop==INT_MIN){
					break;
				}else{
					printf("popped:  %d",pop);
				}
				break;
			case 3:
				displayStack(stack);
				break;
			case 4:
				deleteStack(&stack);
				break;
		}
	}
	return 0;
}
