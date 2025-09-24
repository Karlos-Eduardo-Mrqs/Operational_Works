o#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    string Title = "| Jogo da Forca |";
    string Word;
    char Letter;
    int error = 0, TamWord = 0;

    cout << "Digite uma palavra antes de começar: ";
    cin >> Word;
    TamWord = Word.size();

    vector<string> Secret(TamWord, "*");

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    bool AceptyPlay = true;
    while (AceptyPlay) {
        bool CorrectLetter = false;
        cout << Title << endl;
        for (string s : Secret) {
            for (char c : s) {
                cout << c << " ";
            }
        }
        cout << endl;
        cout << "Digite uma letra que pode ser da palavra secreta: ";
        cin >> Letter;

        #ifdef _WIN32
        	system("cls");
        #else
        	system("clear");
        #endif

        for (int i = 0; i < TamWord; i++) {
            if (Letter == Word[i]) {
                Secret[i] = Letter;
                CorrectLetter = true;
            }
        }

        if (!CorrectLetter) {
            cout << "Não tem essa letra na palavra" << endl;
            error++;
        }

        auto it = find(Secret.begin(), Secret.end(), "*");
        bool WordRevealed = (it == Secret.end());
        if (error > 5) {
            AceptyPlay = false;
        } else if (WordRevealed) {
            cout << "Parabens, você revelou a palavra!" << endl;
            AceptyPlay = false;
            return 0;
        }
    }

    return 0;
}