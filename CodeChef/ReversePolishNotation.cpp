#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct stackChar* createStack();
int isEmptyStackChar(struct stackChar *);
int isFullStackChar(struct stackChar *);
void pushStackChar(struct stackChar **,char);
char popStackChar(struct stackChar **);
struct stackChar* resizeStack(struct stackChar **);
char getOnTopStackChar(struct stackChar *);
void displayStack(struct stackChar*);
struct stackChar{
	char *array;
	int top;
	int capacity;
};
int main(){
	int  length,testCase;
	scanf("%d",&testCase);
	struct stackChar *stack=NULL,*stack1=NULL;
	char* c[testCase];
	char* ans[testCase];
	int counter=0;
	char operation;
	for (int i = 0; i < testCase; i++)
	{	fflush(stdin);
		c[i]=(char *)malloc(sizeof(char)*400);
		ans[i]=(char *)malloc(sizeof(char)*400);
		scanf("%s",c[i]);
		stack=createStack();
		stack1=createStack();
		length=strlen(c[i]);
		counter=0;
		for (int j = 0; j <length; j++)
		{
			if(c[i][j]=='('||c[i][j]=='*'||c[i][j]=='/'||c[i][j]=='+'||c[i][j]=='/'||c[i][j]=='^'||c[i][j]=='%'){
				pushStackChar(&stack,c[i][j]);
			}
			else if(c[i][j]>=97 && c[i][j]<=122){
				if(getOnTopStackChar(stack)=='*'||getOnTopStackChar(stack)=='+'||getOnTopStackChar(stack)=='/'||getOnTopStackChar(stack)=='^'||getOnTopStackChar(stack)=='%'){
					operation=popStackChar(&stack);	
					pushStackChar(&stack,c[i][j]);
					pushStackChar(&stack,operation);
				}
				else{
					pushStackChar(&stack,c[i][j]);
				}
			}
			else if(c[i][j]==')'){
				while(getOnTopStackChar(stack)!='('){
					pushStackChar(&stack1,popStackChar(&stack));
				}
				popStackChar(&stack);
				if(getOnTopStackChar(stack)=='*'||getOnTopStackChar(stack)=='+'||getOnTopStackChar(stack)=='/'||getOnTopStackChar(stack)=='^'||getOnTopStackChar(stack)=='%'){
					operation=popStackChar(&stack);
					while(!isEmptyStackChar(stack1)){
						pushStackChar(&stack,popStackChar(&stack1));
					}
					pushStackChar(&stack,operation);
				}
				else{
					while(!isEmptyStackChar(stack1)){
						pushStackChar(&stack,popStackChar(&stack1));
					}
				}
				
			}
			
			
		}
		while(!isEmptyStackChar(stack)){
			pushStackChar(&stack1,popStackChar(&stack));
		}
		while(!isEmptyStackChar(stack1)){
			ans[i][counter++]=popStackChar(&stack1);
		}
		
	}
	for (int i = 0; i < testCase; i++)
	{
		printf("%s\n",ans[i]);
	}
	
	
	
	return 0;
}
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
		//printf("UnderFlow Error:LINE::33");
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
char getOnTopStackChar(struct stackChar *stack){
	return stack->array[stack->top];
}
void displayStack(struct stackChar *stack){
	for (int i = 0; i <= stack->top; i++)
	{
		printf("%c",stack->array[i]);
	}
}
