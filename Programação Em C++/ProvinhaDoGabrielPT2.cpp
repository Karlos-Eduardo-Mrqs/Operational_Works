#include <iostream>

int main(){
	int vet [8] = {5,1,4,2,7,8,3,6};
	int aux = 0;
	for (int ind=7;ind>=4;ind--){
	    aux=vet[7-ind];
	    vet[7-ind]=vet[ind];
	    vet[ind]=aux;
	}
	for(int ind = 7 ; ind >= 4 ;ind-- ){
	    std::cout<< vet[ind] <<std::endl;
	}
	return 0 ; 
}