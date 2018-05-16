#include<stdio.h>
#include<malloc.h>
struct stackChar* createStack();
int isEmptyStackChar(struct stackChar *);
int isFullStackChar(struct stackChar *);
void pushStackChar(struct stackChar **,char);
char popStackChar(struct stackChar **);
struct stackChar* resizeStack(struct stackChar **);
struct stackChar{
	char *array;
	int top;
	int capacity;
};
/*
int main(){
	struct stackChar * stack=createStack();
	int i;
	char *a="Saurabh";
	for (i = 0; i <7 ; i++)
	{
		pushStackChar(&stack,a[i]);
		printf("%d\n",stack->capacity);
	}
	for (i = 0; i <8 ; i++)
	{
		printf("%c\n",popStackChar(&stack));
	}
	return 0;
}
*/
struct stackChar* createStack(){
		struct stackChar *stack=NULL;
		stack=(struct stackChar*)malloc(sizeof(struct stackChar));
		if(!stack){
			printf("Memory Error Line::11");
			return NULL;
		}
		stack->top=-1;
		stack->capacity=1;
		stack->array=(char*)malloc(sizeof(char)*stack->capacity);
		return stack;
}
int isEmptyStackChar(struct stackChar *stack){
	return stack->top==-1;
}
int isFullStackChar(struct stackChar *stack){
	return stack->top+1==stack->capacity;
}
void pushStackChar(struct stackChar **stack,char data){
	if(isFullStackChar(*stack)){
		resizeStack(stack);
	}
	(*stack)->top++;
	(*stack)->array[(*stack)->top]=data;
}
char popStackChar(struct stackChar **stack){
	char data;
	if(isEmptyStackChar(*stack)){
		printf("UnderFlow Error:LINE::33");
		return -1;
	}else{
		data=(*stack)->array[(*stack)->top];
		(*stack)->top--;
		return data;
	}
		
}
struct stackChar* resizeStack(struct stackChar **stack){
	char *arr=(*stack)->array;
	int i;
	int old_capacity=(*stack)->capacity;
	int new_capacity=old_capacity*2;
	(*stack)->capacity=new_capacity;
	(*stack)->array=(char *)malloc(sizeof(char)*new_capacity);
	for (i = 0; i < old_capacity; i++)
	{
		(*stack)->array[i]=arr[i];
	}
	free(arr);
	return *stack;
}
