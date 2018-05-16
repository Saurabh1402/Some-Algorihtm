#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* reverseXOR(char [],int,int);
char* reverseWordInSentence(char *);
char* reverseWordInSentenceRecursive(char*);

char* reverseWordInSentence(char str[]){
	int start=0,end=0,length;
	length=strlen(str);
	str=reverseXOR(str,0,length-1);
	for(start=0,end=0;end<length;end++){
		if(str[end]!=' '){
				start=end;
				while(str[end]!=' '&& end<length)
					end++;
				end--;
				reverseXOR(str,start,end);
			
			}
	}
	return str;
}
char* reverseXOR(char str[],int start,int end){
	for(;start<end;start++,end--){
		str[start]^=str[end];
		str[end]^=str[start];
		str[start]^=str[end];
	}
	return str;
}
char* reverseWordInSentenceRecursive(char str[]){
	if(strlen(str)<1) return "";
	
	char *temp1,*temp2=(char*)malloc(sizeof(char)*strlen(str));
	int count=0,length;
	length=strlen(str);
	while(str[count]!=' '&&count<length)count++;
	while(str[count]==' ' && count<length)count++;
	temp1=(char*)malloc(sizeof(char)*(count));
	strcpy(temp1,str);
	temp1[count]='\0';
	strcpy(temp2,reverseWordInSentenceRecursive(str+count));
	strcat(temp2,temp1);
	return temp2;
}
int main(){
	char a[]="Algorithm is the most important subject for any computer science student ";
	//char *str=(char*)malloc(sizeof(char)*strlen(a));
	//printf("%s\n%d",reverseWordInSentence(a),printf("%s",strcpy(str,a)));
	printf("%s\n",reverseWordInSentenceRecursive(a));
	
	return 0;
}

