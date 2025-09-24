#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int num=0,TamPar,TamImpar;
	vector <int> Numpares;
	vector <int> NumImpares;
	for(int i = 1 ; i<=10 ; i++){
		printf("\n Digite o numero [%d]:",i);
		scanf("%d",&num);				
		if(num % 2 == 0){
			Numpares.push_back(num);
		}else{
			NumImpares.push_back(num);
		}
	}
	
	TamPar=Numpares.size();
	TamImpar=NumImpares.size();
	
	printf("\n Os numeros pares são:");
	for(int i = 0 ; i < TamPar ; i++){
		printf("|( %d [%d] )|",Numpares[i],i);
	}
	printf("\n");
	printf("\n Os numeros impares são:");
	for(int i = 0 ; i < TamImpar ; i++){
		printf("|( %d [%d] )|",NumImpares[i],i);
	}
	
}