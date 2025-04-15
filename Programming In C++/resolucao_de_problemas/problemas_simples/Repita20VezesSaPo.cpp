#include <cstdio>

int main(){
	int num,i;
	printf("Digite um número:");
	scanf("%d",&num);
	for(i=1;i<=5;i++){
		printf("[ %d ] = %d \n", i, num);
	}
}