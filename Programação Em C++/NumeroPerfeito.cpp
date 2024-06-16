#include <cstdio>
#include <string>
int main(){
	int num=0;
	int SomaAntes = 0;
	printf("Escreva um numero:");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		if(num % i == 0 ){
			SomaAntes+=i;			
		}	
	}
	if(SomaAntes == num){
		printf("O numero %d e perfeito:",num);
	}else{
		printf("O numero %d e imperfeito:",num);
	}
	return 0;	
}	