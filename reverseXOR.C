#include<stdio.h>
#include<string.h>
char* reverseXOR(char str[]){
	int start=0,end=0;
	end=strlen(str)-1;
	for(;start<end;start++,end--){
		str[start]^=str[end];
		str[end]^=str[start];
		str[start]^=str[end];
	}
	return str;
}


int main(){
	char a[]="saurabh Vishwakarma";
	printf("%s\n",reverseXOR(a));
	return 0;
}
