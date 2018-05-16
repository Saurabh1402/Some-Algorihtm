#include<stdio.h>
#include<string.h>
void RemoveAdjacentPair(char *str){
	int i,j=0,length=strlen(str);
	for(i=1;i<=length;i++){
		
		while(str[i]==str[j] && j>=0){
			i++;
			j--;
		}
		str[++j]=str[i];
	}
}
int main(){
	char str[]="SaurabhasdfghjhgfdsaYogesh";
	RemoveAdjacentPair(str);
	printf("%s\n",str);
	return 0;}
