#include<iostream>
#include<vector>

using namespace std;

struct resposta {
    int passos, posicao;
};

resposta resp;

void ordenar_elementos(vector<int> &elementos, int &tamanho, int valorTemp) {
    int indice = 0;

    if (tamanho == 128) {
        cout << "LISTA ESTÁ MUITO CHEIA !" << endl;
        return;
    }

    while (valorTemp > elementos[indice] && indice < tamanho) {
        indice++;
    }

    for (int posicao = tamanho; posicao > indice; posicao--) {
        elementos[posicao] = elementos[posicao - 1];
    }

    elementos[indice] = valorTemp;
    tamanho++;
}

void percorrer(vector<int> elementos, int tamanho) {
    for (int indice = 0; indice < tamanho; indice++) {
        cout << elementos[indice] << " ";
    }
    cout << endl;
}

resposta busca_sequencial(vector<int> &elementos, int tamanho, int valorTemp) {
    resp.passos = 0;
    for (int indice = 0; indice < tamanho; indice++) {
        resp.passos++;
        if (elementos[indice] == valorTemp) {
            resp.posicao = indice;
            return resp;
        }
    }
    resp.posicao = -1;
    return resp;
}

// Função de busca binária
resposta busca_binaria(vector<int> &elementos, int tamanho, int valorTemp) {
    int esquerda = 0, direita = tamanho - 1;
    int meio;
    resp.passos = 0;

    while (esquerda <= direita) {
        meio = esquerda + (direita - esquerda) / 2;
        resp.passos++;

        if (elementos[meio] == valorTemp) {
            resp.posicao = meio;
            return resp;
        }

        if (elementos[meio] < valorTemp) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    resp.posicao = -1; // Caso não encontre o valor
    return resp;
}

int main() {
    vector<int> elementos(128);
    int tamanho = 0, indice, valorTemp;
    resposta respSequencial, respBinaria;

    // Preenche o vetor com valores
    for (indice = 0; indice < 128; indice++) {
        valorTemp = (indice * 3) + 1;
        ordenar_elementos(elementos, tamanho, valorTemp);
    }

    percorrer(elementos, tamanho);

    cout << "Digite um numero pra ENCONTRAR: " << endl;
    cin >> valorTemp;

    // Chama busca sequencial
    respSequencial = busca_sequencial(elementos, tamanho, valorTemp);
    if (respSequencial.posicao != -1) {
        cout << "Busca Sequencial: Encontrado na posição " << respSequencial.posicao << " em " << respSequencial.passos << " passos.\n";
    } else {
        cout << "Busca Sequencial: Não encontrado! Passos: " << respSequencial.passos << endl;
    }

    // Chama busca binária
    respBinaria = busca_binaria(elementos, tamanho, valorTemp);
    if (respBinaria.posicao != -1) {
        cout << "Busca Binária: Encontrado na posição " << respBinaria.posicao << " em " << respBinaria.passos << " passos.\n";
    } else {
        cout << "Busca Binária: Não encontrado! Passos: " << respBinaria.passos << endl;
    }

    return 0;
}