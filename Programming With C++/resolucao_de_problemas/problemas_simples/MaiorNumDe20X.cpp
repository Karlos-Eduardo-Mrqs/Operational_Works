#include <cstdio>
#include <stdlib.h>
int main(){
	int num=0,i,maior=0,posi;
	for(i=1;i<=15;i++){
		printf("Digite o [%d numero]",i);
		scanf("%d",&num);
		if(num>maior){
			maior=num;
			posi=i;
		}	
	}
	system("clear||cls");
	printf("O maior numero de todos os 15 lidos e: %d[%d]",maior,posi);
	return 0;
}