#include <iostream>
#include <vector>
#include <algorithm> // Para usar as funções find e remove

using namespace std;

// Definição da estrutura lista
struct lista {
    vector<int> elementos;
    int tamanho;
};

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para verificar se um elemento existe no vetor
bool procura(const vector<int> &elementos, int elemento) {
    return find(begin(elementos), end(elementos), elemento) != elementos.end();
}

// Função para inserir um elemento na lista
bool inserir_valor_lista(lista &List, int numero) {
    bool repetido = procura(List.elementos, numero);
    if (repetido) {
        cout << "Valor ja existe na lista! Digite outro valor." << endl;
        return false; // Retorna falso se o valor já existir
    } else {
        List.elementos.push_back(numero);
        cout << "Valor inserido com sucesso!" << endl;
        return true; // Retorna verdadeiro se o valor for inserido
    }
}

// Função para exibir o conteúdo da lista
void ilustrar_lista(lista &List) {
    cout << "Conteudo da lista:" << endl;
    for (size_t i = 0; i < List.elementos.size(); i++) {
        cout << "|" << List.elementos[i] << "|" << endl;
    }
}

// Função para remover um elemento da lista
void remover_item(lista &List, int numero) {
    if (List.elementos.empty()) {
        cout << "Erro! A lista esta vazia." << endl;
        return;
    }

    auto it = find(begin(List.elementos), end(List.elementos), numero);
    if (it != end(List.elementos)) {
        List.elementos.erase(it); // Remove o elemento encontrado
        cout << "O numero " << numero << " foi removido com sucesso." << endl;
    } else {
        cout << "Erro! O numero " << numero << " nao foi encontrado na lista." << endl;
    }
}

int main() {
    lista List; // Cria uma instância da estrutura lista
    int len_usuario, numero;

    cout << "Informe o tamanho da entrada inicial: "; // Solicita o tamanho inicial da lista
    cin >> len_usuario;

    List.tamanho = len_usuario; // Define o tamanho
    int contador = 0; // Contador para controlar o número de inserções

    while (contador < len_usuario) { // Insere valores na lista
        cout << "Digite um numero: ";
        cin >> numero;

        if (inserir_valor_lista(List, numero)) { // Tenta inserir o número na lista
            contador++; // Incrementa o contador apenas se o valor for inserido
        }
    }

    limpar_tela();
    ilustrar_lista(List); // Exibe o conteúdo da lista

    // Procura um número na lista
    cout << "Informe um numero para encontrar: ";
    cin >> numero;

    if (procura(List.elementos, numero)) {
        cout << "O numero " << numero << " foi encontrado." << endl;
    } else {
        cout << "O numero " << numero << " nao foi encontrado." << endl;
    }

    // Remove um número da lista
    cout << "\nDigite um numero para excluir: ";
    cin >> numero;

    remover_item(List, numero);

    // Exibe o conteúdo atualizado da lista
    cout << "\nConteudo atualizado da lista:" << endl;
    ilustrar_lista(List);

    return 0; // Indica que o programa foi concluído com sucesso
}