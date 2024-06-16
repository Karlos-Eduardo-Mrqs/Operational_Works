#include <stdio.h>

int main(){
float dividendo, divisor;
printf("Entre com dois numeros reais:\n");
scanf("%f %f", &dividendo, &divisor);
printf("A divisao de %.4f por %.4f vale %.2f", dividendo, divisor, dividendo/divisor);
return 0;
}
