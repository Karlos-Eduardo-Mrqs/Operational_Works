#include <cstdio>
int main(){
		int num = 0 , cont = 0 , media = 0 ;
	while(num >=0 ){
		printf("Digite um numero positivo :");
		scanf("%d",&num);
		if(num >= 0){
			media+=num;
			cont++;
		}else{
			cont--;
		}
	}	
	if(cont > 0){
		media/=cont;
		printf("A media dos numeros e %d",media);
	}else{
		printf("Nenhum numero foi digitado ou ele e negativo");
	}
	return 0;
}