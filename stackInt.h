#include<stdio.h>
#include<malloc.h>
struct stackInt* createStack();
int isEmptyStackInt(struct stackInt *);
int isFullStackInt(struct stackInt *);
void pushStackInt(struct stackInt **,int);
int popStackInt(struct stackInt **);
struct stackInt* resizeStack(struct stackInt **);
struct stackInt{
	int *array;
	int top;
	int capacity;
};
/*
		int main(){
			struct stackInt * stack=createStack();
			int i,a[]={1,34,11,53,12,53,53,114,76,23,52};
			for (i = 0; i <11 ; i++)
			{
				pushStackInt(&stack,a[i]);
				printf("%d\n",stack->capacity);
			}
			for (i = 0; i <11 ; i++)
			{
				printf("%d\n",popStackInt(&stack));
			}
			return 0;
		}
*/
struct stackInt* createStack(){
		struct stackInt *stack=NULL;
		stack=(struct stackInt*)malloc(sizeof(struct stackInt));
		if(!stack){
			printf("Memory Error Line::11");
			return NULL;
		}
		stack->top=-1;
		stack->capacity=1;
		stack->array=(int*)malloc(sizeof(int)*stack->capacity);
		return stack;
}
int isEmptyStackInt(struct stackInt *stack){
	return stack->top==-1;
}
int isFullStackInt(struct stackInt *stack){
	return stack->top+1==stack->capacity;
}
void pushStackInt(struct stackInt **stack,int data){
	if(isFullStackInt(*stack)){
		resizeStack(stack);
	}
	(*stack)->top++;
	(*stack)->array[(*stack)->top]=data;
}
int popStackInt(struct stackInt **stack){
	int data;
	if(isEmptyStackInt(*stack)){
		printf("UnderFlow Error:LINE::33");
		return -1;
	}else{
		data=(*stack)->array[(*stack)->top];
		(*stack)->top--;
		return data;
	}
		
}
struct stackInt* resizeStack(struct stackInt **stack){
	int *arr=(*stack)->array,i;
	int old_capacity=(*stack)->capacity;
	int new_capacity=old_capacity*2;
	(*stack)->capacity=new_capacity;
	(*stack)->array=(int *)malloc(sizeof(int)*new_capacity);
	for (i = 0; i < old_capacity; i++)
	{
		(*stack)->array[i]=arr[i];
	}
	free(arr);
	return *stack;
}
