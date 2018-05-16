#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
struct CharLLStack* createStack();
int isEmptyStack(struct CharLLStack*);
void pushStack(struct CharLLStack** ,char );
char popStack(struct CharLLStack** );

struct CharLLStack{
	char data;
	struct CharLLStack* next;
};
struct CharLLStack* createStack(){
	return NULL;
}
int isEmptyStack(struct CharLLStack* stack){
	return stack==NULL;
}
void pushStack(struct CharLLStack** stack,char data){
	struct CharLLStack* newNode=(struct CharLLStack*)malloc(sizeof(struct CharLLStack));
	if(!newNode){
		printf("\nLine:17 :: Unable to allocate memory for newNode\n");
		return;
	}else{
		newNode->data=data;
		newNode->next=(*stack);
		(*stack)=newNode;
	}
}
char popStack(struct CharLLStack** stack){
	if(isEmptyStack((*stack))){
		printf("\nLine:27 :: Underflow :: Unable to Pop");
		return (char)0;
	}else{
		struct CharLLStack* temp=(*stack);
		char data;
		(*stack)=(*stack)->next;
		data=temp->data;
		free(temp);
		return data;
	}
}
int topStack(struct CharLLStack* stack){
	if(isEmptyStack(stack)){
		printf("\nUnderflow: Stack is Empty\n");
		return INT_MIN;
	}
	else{
		
		return stack->data;
	}
}
void deleteStack(struct CharLLStack** stack){
	struct CharLLStack* temp=NULL;
	while((*stack)!=NULL){
		temp=(*stack);
		(*stack)=(*stack)->next;
		free(temp);
	}
}
void displayStack(struct CharLLStack* stack){
	if(stack==NULL)return;
	displayStack(stack->next);
	printf("%c",stack->data);
}

int main(){
	char s[100];
	struct CharLLStack* stack=createStack();
	scanf("%s",s);
	for (int i = 0; i < (int)strlen(s); i++)
	{
		pushStack(&stack,s[i]);
	}
	for (int i = 0; i < (int)strlen(s); i++)
	{
		s[i]=popStack(&stack);
	}
	printf("\n Reverse: %s",s);
	return 0;
}
