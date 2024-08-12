#include <cstdio>
#include <stdlib.h>
int main(){
	int n1,n2,n3;
	int ma,mei,fi;
	printf("n1:");
	scanf("%d",&n1);
	printf("n2:");
	scanf("%d",&n2);
	printf("n3:");
	scanf("%d",&n3);
	if(n1==n2 && n2==n3){
		printf("Os numeros sao iguais");
		return 0;
	}
	if(n1 > n2 && n1 > n3){
		ma= n1;
		mei = n2 > n3 ? n2 : n3;
		fi =  n3 > n2 ? n2 : n3;		
	}		
	if(n2 > n1 && n2 > n3){
		ma= n2;
		mei = n3 > n1 ? n3 : n1;
		fi =  n1 > n3 ? n3 : n1;		
	}
	if(n3 > n1 && n3 > n2){
		ma = n3;
		mei = n2 > n1 ? n2 : n1;
		fi =  n1 > n2 ? n2 : n1;		
	}
	system("clear||cls");
	printf("\n Ordem Decrescente | maior:%d | meio:%d | menor:%d |",ma,mei,fi);
	printf("\n Ordem Crescente   | menor:%d | meio:%d | maior:%d | \n",fi,mei,ma);
	return 0;
}