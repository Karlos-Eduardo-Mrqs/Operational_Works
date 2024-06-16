#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main(){
    int TamNumbersP = 0;
    int list = 0, num = 0;

    printf("Quantos numeros voce quer listar: ");
    scanf("%d", &list);
    if (list < 0) {
        printf("Numero Invalido ! \n");
        return 0;
    }
    std::vector<int> numbersP;
    
	for (int i = 0; i < list; i++) {
        printf("\nDigite o numero %d: ", i);
        scanf("%d", &num);
        if (num % 2 == 0) {
            numbersP.push_back(num);
        }
    }

    std::sort(numbersP.begin(), numbersP.end());
    TamNumbersP = numbersP.size();
    system("clear||cls");

    printf("A Ordem Crescente dos numeros pares e: \n");
    for (int i = 0; i < TamNumbersP; i++) {
        printf("%d ;", numbersP[i]);
    }
	return 0;
}