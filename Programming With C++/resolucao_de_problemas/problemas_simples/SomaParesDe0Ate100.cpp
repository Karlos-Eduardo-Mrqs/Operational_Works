#include <cstdio>

int main(){
	int soma=0;
	for(int i=0;i<=100;i+=2){
		soma+=i;	
	}
	printf("A soma dos numeros pares e: %d",soma);
}