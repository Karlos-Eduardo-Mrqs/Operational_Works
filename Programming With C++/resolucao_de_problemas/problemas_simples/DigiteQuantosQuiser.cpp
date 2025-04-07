#include <cstdio>
#include <stdlib.h>
#include <string>

int main (){
	std::string msg;
	int media=0,num=0,i=0,quantos;
	printf("Quantos numeros voce quer somar?:");
	scanf("%d",&quantos);
	for(i=1;i<=quantos;i++){
		printf("\n Digite o numero[%d]:",i);
		scanf("%d",&num);
		media+=num;
		msg+=std::to_string(num);
		if(i < quantos){
			msg+="+";
		}
	}
	system("clear||cls");
	media/=quantos;
	printf("%s",msg.c_str());
	printf("/%d = %d",quantos,media);
	return 0;
}