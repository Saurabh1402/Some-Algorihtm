#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main(){
	int no,flag;
	char *c=(char*)malloc(sizeof(char));
	while(1){
		scanf("%d",&no);
		if(no==0){
			printf("%s",c);
			return 0;
		}
		else{
			int ar[no];
			for (int i = 0; i <no; i++)
			{
				scanf("%d",&ar[i]);
			}
			flag=1;
			for (int i = 0; i <no ; i++)
			{
				if(i+1!=ar[ar[i]-1]){
					flag=0;
					break;
				}
			}
			if(flag==0){
				strcat(c,"not ambiguous\n");
			}
			else{
				strcat(c,"ambiguous\n");
			
			}
			
		}
	}
	return 0;
}
