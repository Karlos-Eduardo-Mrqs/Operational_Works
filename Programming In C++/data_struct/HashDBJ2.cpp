#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#define TABLESPACE 2000

using namespace std;

struct agenda {
    bool livre;
    char nome[50];
    char enredeco[50];
    char tel[10];
};

void iniciaAgenda(agenda a[]) {
    for (int i = 0; i < TABLESPACE; i++) {
        a[i].livre = true;
    }
}

// Função de hash baseada no algoritmo DJB2
int minhaHashModificada(string chave, int tamanhoTabela) {
    unsigned long hash = 5381;
	for (char c : chave) {
        hash += ( (hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % tamanhoTabela;
}

int main() {
    agenda a[TABLESPACE];
    char nome[50];
    vector<string> Nomes;
    iniciaAgenda(a);

    for (int i = 0; i <= 10; i++) {
        cout << "Digite o nome " << i << ": ";
        cin >> nome;
        Nomes.push_back(nome);
    }

    cout << "\n**Testando as Funções de Hash**\n\n";
    cout << "**Dados Utilizados:**\n";
    for (const string& nome : Nomes) {
        cout << nome << " "<<endl;
    }
    cout << "\n\n";

    cout << "**Análise de Colisões:**\n";
    vector<int> indicesModificada(TABLESPACE, 0);
    int colisoesModificada = 0;

    for (int j = 0; j < Nomes.size(); j++) {
        int posModificada = minhaHashModificada(Nomes[j], TABLESPACE);

        cout << "  Hash Modificada: " << minhaHashModificada(Nomes[j], TABLESPACE);
        cout << "Nome : " << Nomes[j] <<" -> Posição: " << posModificada << " (Ocupado: " << (indicesModificada[posModificada] > 0 ? "Sim" : "Não") << ")\n\n";

        if (indicesModificada[posModificada] > 0) {
            colisoesModificada++;
        }
        indicesModificada[posModificada]++;
    }

    cout << "\n**Resultados:**\n";
    cout << "Colisões na Função Hash Modificada: " << colisoesModificada << "\n";

    return 0;
}