#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct DynArrayStack{
	int top;
	int capacity;
	int *array;
};
struct DynArrayStack* createStack(){
	struct DynArrayStack* stack=NULL;
	stack=(struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
	if(!stack)
		return NULL;
	stack->top = -1;
	stack->capacity = 1;
	stack->array=(int*)malloc(sizeof(int)*stack->capacity);
	if(!stack->array)
		return NULL;
	return stack;
}
void doubleStack(struct DynArrayStack* stack){
	stack->capacity*=2;
	stack->array = (int*)realloc(stack->array,stack->capacity);
}	
int isFullStack(struct DynArrayStack* stack){
	return stack->top==stack->capacity-1;
		
}
int isEmptyStack(struct DynArrayStack* stack){
	return stack->top==-1;
}
void pushStack(struct DynArrayStack* stack,int data){
	if(isFullStack(stack)){
		doubleStack(stack);
	}
	stack->array[++stack->top] = data; 
}
int popStack(struct DynArrayStack* stack){
	if(isEmptyStack(stack)){
		printf("\nUnderflow : Stack is Empty\n");
		return INT_MIN;
	}
	else{
		return stack->array[stack->top--];
	}
}
int topStack(struct DynArrayStack* stack){
	if(isEmptyStack(stack)){
		printf("\nUnderflow : Stack is Empty\n");
		return INT_MIN;
	}
	else{
		return stack->array[stack->top];
	}
}
void deleteStack(struct DynArrayStack* stack){
	if(stack){
		if(stack->array){
				free(stack->array);
		}
	free(stack);
	}
}
void displayStack(struct DynArrayStack* s){
	if(isEmptyStack(s)){
		printf("Stack is Empty");
		return;
	}
	printf("\n");
	for (int i = 0; i <=s->top; i++)
	{
		printf("%d --> ",s->array[i]);
	}
	printf("\n");

}
int main(){
	struct DynArrayStack* stack=NULL;
	int data,choice,pop;
	
	stack=createStack();
	if(stack==NULL){
		printf("Unable to allocate memory for stack");
		return 0;
	}
	while(1){
	printf("\n1-->Push to Stack\n2-->Pop from Stack\n3-->Display Stack \n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Data to Push");
				scanf("%d",&data);
				pushStack(stack,data);
				break;
			case 2:
				pop=popStack(stack);
				if(pop==INT_MIN){
					break;
				}else{
					printf("popped:  %d",pop);
				}
				break;
			case 3:
				displayStack(stack);
				break;
		}
	}
	return 0;
}
