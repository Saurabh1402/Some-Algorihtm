#include<stdio.h>
int main(){
	int testCase;
	char a;
	scanf("%d",&testCase);
	while(testCase--){
		scanf(" %c ",&a);
		if(a=='b'||a=='B')
			printf("BattleShip\n");
		else if(a=='c'||a=='c')
			printf("Cruiser\n");
		else if(a=='d'||a=='D')
			printf("Destroyer\n");
		else if(a=='f'||a=='F')
			printf("Frigate\n");
		
	}
	return 0;
}
