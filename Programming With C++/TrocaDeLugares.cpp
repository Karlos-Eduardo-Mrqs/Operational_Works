#include <iostream>
using namespace std;

void troca_de_valores(int &a , int &b){
	// a = 2 , b = 4 
	int aux; // auxiliar
	aux = a ; // 0 = 2
	a = b ; // 2 = 4
	b = aux; // 4 = 2
	cout<<"Dentro da troca:"<< endl;
	cout<<"A:" << a << " B:" << b<< endl; // 4 , 2
} 

int main(){
	int a,b;
	cout<<"Digite o primeiro numero:";
	cin>>a;
	cout<<"Digite o segundo numero:";
	cin>>b;
	cout<<"Antes da troca:" << endl;
	cout<<" A: " << a << " B: " << b << endl;
	troca_de_valores(a, b);
	cout<<"Depois da troca:";
	cout<<" A: " << a << " B: " << b << endl;
	return 0;
}