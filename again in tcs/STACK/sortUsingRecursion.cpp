#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct DynArrayStack{
	int top;
	int capacity;
	int *array;
};
struct DynArrayStack* createStack(int size){
	struct DynArrayStack* stack=NULL;
	stack=(struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
	if(!stack)
		return NULL;
	stack->top = -1;
	stack->capacity = size;
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
void insertSorted(struct DynArrayStack* s,int data){
	if(isEmptyStack(s)){
		pushStack(s,data);
		return;
	}else{
		int temp=popStack(s);
		if(temp > data){
			insertSorted(s,data);
			pushStack(s,temp);
		}else{
			pushStack(s,temp);
			pushStack(s,data);
		}
	}
}
void sortStackUsingRecursion(struct DynArrayStack*s ){
	int temp;
	if(isEmptyStack(s)==true)
		return;
	else
		temp=popStack(s);
	sortStackUsingRecursion(s);
	insertSorted(s,temp);
}
int main(){
	struct DynArrayStack* s=createStack(10);
	
	int arr[10]={23,35,12,56,344,65,66,123,44,55};
	for (int i = 0; i < 10; i++)
	{
			pushStack(s,arr[i]);
	}
	displayStack(s);
	sortStackUsingRecursion(s);
	displayStack(s);
	return 0;
}
