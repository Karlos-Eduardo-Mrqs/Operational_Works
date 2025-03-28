#include <iostream>
#define TAMANHO 10
using namespace std;

struct lista{
	int v[TAMANHO];
	int tam;
};

void iniciaLista (lista *l){
     l->tam = 0;
}

void inserir(lista *l, int e){
	if (l->tam == TAMANHO){
		cout << "\nERRO: Lista cheia. \nElemento " << e << " nao incluido!\n\n";
	}else{
		l->v[l->tam] = e;
		(l->tam)++;
	}
	return;
}

void percorrer(lista l){
	cout << "\n Conteudo da Lista: \n[ ";
	for (int i = 0; i < l.tam; i++){
		cout <<  l.v[i] << " | ";
    }
	cout << " ]\n\n";
}

int buscarSequencial(lista l, int valor){
	for (int i = 0; i < l.tam; i++){
		if (l.v[i] == valor) return i;
	}
	return -1;
}

void remover(lista *l, int e){
	int pos;
	if (l->tam == 0){
		cout << "\nERRO : Lista vazia. \n";
		return; // return; sai da função sem retornar valor algum
	}
	pos = buscarSequencial(*l,e);
	if (pos == -1){
		cout << "\nERRO : Valor não encontrado. \n";
		return;
	}
	l->v[pos] = l->v[(l->tam)-1];
	(l->tam)--;
}

// Prog. Principal
int main(){
	//int v[TAMANHO], tam, i, temp, x;
    int i, temp, x;
    lista l;
    
    //iniciaLista (&tam);
    iniciaLista (&l);
    
    cout << "Informe o tam da entrada inicial: ";
    cin >> x;
	for (i = 0; i < x; i++){
		cout << "Digite um numero: ";
		cin >> temp;
				
		//inserir(v, &tam, temp);
		inserir(&l, temp);
	}
	
	//percorrer(v,tam);
	percorrer(l);
	
	cout << "\nDigite um numero pra procurar: ";
	cin >> temp;
	
	//i = buscarSequencial(v,tam,temp);
	i = buscarSequencial(l,temp);
	
	if (i == (-1)){
		cout << "\nNao achei " << temp << "...\n";
	}else{
		cout << "\nAchei " << temp << " na posicao " << i << "...\n";
	}
	cout << "\nDigite um numero pra excluir: ";
	cin >> temp;
	
	//remover(v,tam,temp);
	remover(&l,temp);
	
	//percorrer(v,tam);
	percorrer(l);
	return 0;
}