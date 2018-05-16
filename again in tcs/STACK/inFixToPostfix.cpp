#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
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
	char exp[]="(A+B)*(C-D)";
	char temp;
	struct CharLLStack* stack=createStack();
	//struct CharLLStack* output=createStack();
	//printf("%s -->%d",string,(int)strlen(exp));
	for (int i = 0; i < (int)strlen(exp); i++)
	{
		temp='\0';
		//printf("stacK:  ");
		//displayStack(stack);
		//printf("\n");
		switch(exp[i]){
			case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':case 'H':case 'I':case 'J':case 'K':case 'L':case 'M':case 'N':case 'O':case 'P':case 'Q':case 'R':case 'S':case 'T':case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':
				printf("%c",exp[i]);
				break;
			case ')'://case ']':case '}':
				while(stack&&(temp=popStack(&stack))!='('){
					printf("%c",temp);
				}
				//printf("stack:");
				//displayStack(stack);
				//printf("\n");
		
				break;
			case '(':
				pushStack(&stack,exp[i]);
				break;
			case '/':case '*':case '%':
				
				while(stack&&((temp=popStack(&stack))!='-'||(temp=popStack(&stack))!='+'||(temp=popStack(&stack))!='(')){
					printf("%c",temp);
				}
				pushStack(&stack,temp);
				pushStack(&stack,exp[i]);
				break;
			case '+':case '-':
			while(stack&&((temp=popStack(&stack))!='(')){
					printf("%c",temp);
				}
				pushStack(&stack,temp);
				pushStack(&stack,exp[i]);
				break;
				
		}
		
	}
	while(stack){
			printf("%c",popStack(&stack));
		}
	
	return 0;
}
