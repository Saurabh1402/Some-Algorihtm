#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct DynArrayStack{
	int top;
	int capacity;
	int *array;
};
struct DynArrayStack* createStack(){
	struct DynArrayStack* s=(struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
	if(s==NULL) {
		printf("\nLINE: 9:: Unable to allocate memory for stack");
		return NULL;
	}
	s->top=-1;
	s->capacity=1;
	s->array=(int*)malloc(s->capacity*sizeof(int));
	if(!s->array){
		printf("\nLINE: 17::  Unable to allocate memory for Stack Array");
		return NULL;
	}
	
	return s;
}
int isEmptyStack(struct DynArrayStack* s){
	return s->top==-1;
}
int isFullStack(struct DynArrayStack* s){
	return s->capacity-1==s->top;
}
void doubleStack(struct DynArrayStack* s){
		s->capacity=s->capacity*2;
		s->array=(int*)realloc(s->array,s->capacity);
		if(!s->array)
			printf("\nLINE: 33:: Unable to allocate memory for Stack Array");
}
void pushStack(struct DynArrayStack* s,int data){
		if(isFullStack(s))
			doubleStack(s);
		s->array[++s->top]=data;
}
int pop(struct DynArrayStack* s){
	if(isEmptyStack(s)){
		printf("\nLine:42:: Underflow: stack is empty");
		return INT_MIN;
	}else{
		return s->array[s->top--];
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
	int size;
	struct DynArrayStack* s=createStack();
	printf("\nEnter the size of array: ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter %d elements: ",size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d",&arr[i]);
	}
	pushStack(s,arr[0]);
	for (int i = 1; i < size; i++)
	{
		int temp;
		int next=arr[i];
		while(!isEmptyStack(s) && (temp=pop(s)) < next){
			printf("\n %d Next Greater: %d ",temp,next);
		}
		if(temp>next){
			pushStack(s,temp);
		}
		pushStack(s,next);
		//displayStack(s);
	}
	while(!isEmptyStack(s)){
		printf("\n%d NextGreater: -1",pop(s));
	}
	printf("\n%d Next Greater: -1",arr[size-1]);
	
	
}
