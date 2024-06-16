	#include <iostream>
	int main() {
	    char continuar = 'S';
	    int num = 0, cont = 0, par = 0, impar = 0;
	    while (continuar != 'N') { 
	        std::cout << "Digite um numero: ";
	        std::cin >> num;
	        if (num % 2 == 0) {
	            par = par + 1;
	        } else {
	            impar = impar + 1;
	        }
	        cont = cont + 1;
	        std::cout << "Deseja digitar mais um numero [S/N] ?";
	        std::cin >> continuar;
	    }
	    std::cout << " \n Quantidade de numeros digitados : "<< cont ;
	    std::cout << " \n Quantidade de numeros pares digitados  :"<<par;
	    std::cout << " \n Quantidade de numeros impares digitados  :"<<impar;
		return 0;
	}