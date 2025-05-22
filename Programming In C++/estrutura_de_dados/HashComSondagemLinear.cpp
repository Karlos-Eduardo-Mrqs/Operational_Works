#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#define TABLESPACE 2000

using namespace std;

struct agenda {
    bool livre;
    char nome[50], enredeco[50], tel[10];
};

void iniciaAgenda(agenda a[]) {
    for (int i = 0; i < TABLESPACE; i++) {
        a[i].livre = true;
    }
}

int minhaHashMelhorada(char *chave) { // Função melhorada
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (chave[i] * (i + 1));
    }
    return soma % TABLESPACE;
}

int main() {
    agenda melhorada[TABLESPACE];
    char nome[50];
    iniciaAgenda(melhorada);
    vector<string> nomes(10);

    cout << "Digite 10 nomes:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Nome " << i + 1 << ": ";
        cin >> nomes[i];
    }

    cout << "\nTestando função de hash MELHORADA com sondagem linear:\n";
    for (int i = 0; i < 10; i++) {
        strcpy(nome, nomes[i].c_str());
        int pos = minhaHashMelhorada(nome);
        int originalPos = pos;
        bool inserido = false;

        // Sondagem linear: busca a próxima posição livre
        while (!melhorada[pos].livre) {
            cout << "Colisão com " << nome << " na posição " << pos
                 << ". Já existe: " << melhorada[pos].nome << endl;
            pos = (pos + 1) % TABLESPACE;
            if (pos == originalPos) {
                cout << "Tabela cheia! Não foi possível armazenar " << nome << endl;
                break;
            }
        }

        if (melhorada[pos].livre) {
            strcpy(melhorada[pos].nome, nome);
            melhorada[pos].livre = false;
            cout << nome << " armazenado na posição " << pos << endl;
        }
    }

    return 0;
}