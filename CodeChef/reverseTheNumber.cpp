#include<stdio.h>
#include<string.h>
char* reverseXOR(char str[]){
	int start=0,end=0;
	end=strlen(str)-1;
	while(str[end]=='0'){
		end--;
	}
	str[end+1]='\0';
	for(;start<end;start++,end--){
		str[start]^=str[end];
		str[end]^=str[start];
		str[start]^=str[end];
	}
	return str;
}


int main(){
	int testCase;
	char ch[1000000];
	scanf("%d",&testCase);
	while (testCase--)
	{	scanf("%s",ch);
		
		printf("%s\n",reverseXOR(ch));
	}
	
	return 0;
}
