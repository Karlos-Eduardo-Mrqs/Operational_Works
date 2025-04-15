#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
    std::string WordForca;
    std::vector<char> Secret;
    int TamWord = 0;
    char UserLetra;
    bool Acepty = true;

    std::cout << "Digite uma palavra para começar o jogo da forca: ";
    std::cin >> WordForca;
    system("clear||cls");
    TamWord = WordForca.size();

    for (int i = 0; i < TamWord; i++) {
        Secret.push_back('*');
        std::cout << Secret[i];
    }

    while (Acepty) {
        std::cout << "\nDigite uma Letra para acertar a palavra: ";
        std::cin >> UserLetra;
        bool Acertou = false;

        for (int i = 0; i < TamWord; i++) {
            if (UserLetra == WordForca[i]) {
                Secret[i] = UserLetra;
                Acertou = true; // Indica que pelo menos uma letra foi acertada
            }
        }

        for (char letra : Secret) {
            std::cout << letra;
        }

        if (std::find(Secret.begin(), Secret.end(), '*') == Secret.end()) {
            std::cout << "\nVocê Acertou! Parabéns!\n";
            break;
        } else if (!Acertou) {
            std::cout << "\nA letra digitada não está na palavra.\n";
        }
    }

    return 0;
}