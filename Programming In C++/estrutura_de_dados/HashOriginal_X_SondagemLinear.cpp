#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#define TABLESPACE 2000

using namespace std;

struct agenda {
    bool livre;
    char nome[50], endereco[50], tel[10];
};

void iniciaAgenda(agenda a[]) {
    for (int i = 0; i < TABLESPACE; i++) {
        a[i].livre = true;
    }
}

// Função original baseada no primeiro caractere
int minhaHash(char *chave) {
    return (chave[0] - 65) % TABLESPACE;
}

// Função melhorada com soma ponderada dos caracteres
int minhaHashMelhorada(char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (chave[i] * (i + 1));
    }
    return soma % TABLESPACE;
}

int main() {
    agenda original[TABLESPACE], melhorada[TABLESPACE];
    char nome[50];
    int colisoesOriginal = 0;
    int colisoesMelhorada = 0;

    iniciaAgenda(original);
    iniciaAgenda(melhorada);

    vector<string> nomes(10);

    cout << "Digite 10 nomes:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Nome " << i + 1 << ": ";
        cin >> nomes[i];
    }

    // Teste com função original + sondagem linear
    cout << "\nTestando função de hash ORIGINAL com sondagem linear:\n";
    for (int i = 0; i < 10; i++) {
        strcpy(nome, nomes[i].c_str());
        int pos = minhaHash(nome);
        int originalPos = pos;

        while (!original[pos].livre) {
            colisoesOriginal++;
            cout << "Colisão com " << nome << " na posição " << pos
                 << ". Já existe: " << original[pos].nome << endl;
            pos = (pos + 1) % TABLESPACE;
            if (pos == originalPos) {
                cout << "Tabela cheia! Não foi possível armazenar " << nome << endl;
                break;
            }
        }

        if (original[pos].livre) {
            strcpy(original[pos].nome, nome);
            original[pos].livre = false;
            cout << nome << " armazenado na posição " << pos << endl;
        }
    }

    // Teste com função melhorada + sondagem linear
    cout << "\nTestando função de hash MELHORADA com sondagem linear:\n";
    for (int i = 0; i < 10; i++) {
        strcpy(nome, nomes[i].c_str());
        int pos = minhaHashMelhorada(nome);
        int originalPos = pos;

        while (!melhorada[pos].livre) {
            colisoesMelhorada++;
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

    // Exibir total de colisões
    cout << "\nResumo de colisões:\n";
    cout << "Função ORIGINAL: " << colisoesOriginal << " colisões\n";
    cout << "Função MELHORADA: " << colisoesMelhorada << " colisões\n";

    return 0;
}