/*
#include <cstdio>
#include <stdlib.h>
int main(){
	int idade=0;
	int cont=0,jovem=0,adulto=0,velho=0;
	do{
		printf("Digite sua idade:");
		scanf("%d",&idade);
		cont=cont+1;
		if(idade<=18){
			jovem=jovem+1;
		}else if(idade>=18 && idade<=64){
			adulto=adulto+1;
		}else{
			velho=velho+1;
		}
	}while(cont<11);
	system("clear||cls");
	printf("\nTemos %d pessoas jovens",jovem);
	printf("\nTemos %d pessoas adultas",adulto);
	printf("\nTemos %d pessoas idosas",velho);
}

*/
/*
#include <iostream>
int main(){
	int n1,n2,n3;
	std::cout<<"Digite tres notas";
	std::cin>>n1;
	std::cin>>n2;
	std::cin>>n3;
	std::cout<<"A media das notas e:";
	std::cout<<(n1+n2+n3)/3;
}
*/
#include <cstdio>
int main(){
	int num1,num2,num3;
	printf("Digite tres numeros");
	scanf("%d %d %d",&num1, &num2, &num3);
	printf("A media das notas e %d",(num1+num2+num3)/3);
	return 0;
}