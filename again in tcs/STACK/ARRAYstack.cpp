#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct ArrayStack{
	int top;
	int capacity;
	int *array;
};
struct ArrayStack* createStack(int capacity){
	struct ArrayStack* S=(struct ArrayStack*)malloc(sizeof(struct ArrayStack));
	if(S==NULL)return NULL;
	S->capacity=capacity;
	S->top=-1;
	S->array=(int *)malloc(sizeof(int)*S->capacity);
	if(S->array==NULL)return NULL;
	return S;
}
int isFullStack(struct ArrayStack* stack){
	return stack->capacity-1==stack->top;
}
int isEmptyStack(struct ArrayStack* stack){
	return stack->top==-1;
}
int popStack(struct ArrayStack* stack){
	if(isEmptyStack(stack)) {
		printf("\n------------Underflow: stack is empty------------------------------\n");
		return INT_MIN;
	}else{
		return stack->array[stack->top--];
	}
}
void pushStack(struct ArrayStack* stack,int data){
	if(isFullStack(stack)){
		printf("\n------------Overflow: Stack is full----------------------\n");
		return;
	}else{
		stack->array[++stack->top]=data;
		return;
	}	
}
int getTopElement(struct ArrayStack* s){
	if(isEmptyStack(s)){
		printf("Stack is Empty");
		return INT_MIN;
	}
	return s->array[s->top];
}
void displayStack(struct ArrayStack* s){
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
	struct ArrayStack* stack=NULL;
	int size=0,data,choice,pop;
	
	printf("Enter the size of stack:  "); 
	scanf("%d",&size);
	stack=createStack(size);
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
