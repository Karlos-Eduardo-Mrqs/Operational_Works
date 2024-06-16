//Exercício 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    string nome;
    int quantidade;
};

int main() {
    // Criar o vetor para armazenar os produtos
    vector<Produto> produtos = {
        {"Arroz", 10},
        {"Feijão", 15},
        {"Açúcar", 20}
    };

    // Mostrar os produtos disponíveis
    cout << "Produtos disponíveis:\n";
    for (int i = 0; i < produtos.size(); ++i) {
        cout << i+1 << ". " << produtos[i].nome << " - Quantidade: " << produtos[i].quantidade << endl;
    }

    // Atualizar o estoque
    int escolha;
    cout << "\nDigite o número do produto que deseja atualizar: ";
    cin >> escolha;

    // Verificar se a escolha do usuário é válida
    if (escolha < 1 || escolha > produtos.size()) {
        cout << "Escolha inválida!" << endl;
        return 1;
    }

    // Ajustar o índice para corresponder ao vetor (subtrair 1)
    escolha--;

    // Pedir ao usuário para digitar a nova quantidade
    int novaQuantidade;
    cout << "Digite a nova quantidade para " << produtos[escolha].nome << ": ";
    cin >> novaQuantidade;

    // Atualizar a quantidade no vetor
    produtos[escolha].quantidade = novaQuantidade;

    // Mostrar o estoque atualizado
    cout << "Estoque atualizado:\n";
    for (int i = 0; i < produtos.size(); ++i) {
        cout << i+1 << ". " << produtos[i].nome << " - Quantidade: " << produtos[i].quantidade << endl;
    }

    return 0;
}