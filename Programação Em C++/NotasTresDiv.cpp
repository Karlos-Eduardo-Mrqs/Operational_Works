#include <iostream>

int main(){
	float media;
	int n1,n2,n3;
	printf("Digite tres notas");
	scanf("%d %d %d",&n1,&n2,&n3);
	media=(n1+n2+n3)/3;
	if(media<=5){
		printf("Voce se fodeu! a sua media e %.2f ",media);
	}else{
		printf("Voce passou! a sua media e %.2f ",media);
	}
	return 0;
}