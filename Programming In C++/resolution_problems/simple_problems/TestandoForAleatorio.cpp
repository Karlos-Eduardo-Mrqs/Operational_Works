#include <iostream>
#include <random>
#include <vector>

int main(){
	std::vector<char> letrasmin;
	std::vector<int> numeros;
	for(char letra='a';letra<='z';letra++){
		letrasmin.push_back(letra);
	}
	for(char letra : letrasmin){
		std::cout<<letra<<std::endl;
	}
	for(int num=0;num<=9;num++){
		numeros.push_back(num);
	}
	for(int num : numeros){
		std::cout<<num<<std::endl;
	}
	return 0;
}