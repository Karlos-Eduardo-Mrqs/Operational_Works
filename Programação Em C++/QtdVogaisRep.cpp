#include <iostream>
#include <vector>
#include <stdlib.h>

int main(){
	std::vector<int> num{0,0,0,0,0};
	char letra;
	while(letra!='z'||letra!='Z'){
		std::cout<<"Digite uma letra:";
		std::cin>>letra;
		switch(letra){
			case 'a': 
				num[0]++;
			break;
			
			case 'e': 
				num[1]++;
			break;
			
			case 'i': 
				num[2]++;
			break;
			
			case 'o': 
				num[3]++;
			break;
			
			case 'u': 
				num[4]++;
			break;
					
		}
	}	
	system("cls");
	std::cout<<"Quantidade de vezes que apareceu as vogais:";
	for(int i = 0; i < 5 ;i++){
		std::cout<<num[i];
	}
	return 0;	
}