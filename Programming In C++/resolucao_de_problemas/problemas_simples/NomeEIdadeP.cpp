#include <stdio.h>

int main(){
	int idade;
	char nome[100];
	printf("Qual e o seu nome ?:");
	scanf("%s",&nome);
	printf("Quantos anos voce tem %s ?:",nome);
	scanf("%d",&idade);
	if(idade <=18){
		printf("Ai %s seu vagabundo! e o exercito em ???",nome);
	}else{
		printf("Ai %s seu danado! te pegaram com sabao ???",nome);
	}
}

/*
GPT HELP
#include <stdio.h>

int main() {
    int idade;
    char nome[100];
    
    printf("Qual é o seu nome? ");
    scanf("%99s", nome);
    
    printf("Quantos anos você tem, %s? ", nome);
    scanf("%d", &idade);
    
    if (idade <= 18) {
        printf("Ai %s seu vagabundo! e o exército em ???\n", nome);
    } else {
        printf("Ai %s seu danado! te pegaram com sabão ???\n", nome);
    }
    
    return 0;
}




*/