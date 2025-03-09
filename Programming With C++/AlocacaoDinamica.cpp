#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Digite o tamanho do array: ";
    cin >> n;

    // Alocação dinâmica de memória
    int* array = new int[n];

    // Preenchendo o array
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Imprimindo o array
    cout << "Array alocado dinamicamente:\n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Liberando a memória
    delete[] array;

    return 0;
}