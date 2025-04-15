#include <stdio.h>

int main() {
    int i, w = 0, d = 0; 
    
    printf("Lacos de Repeticao (3)\n");
    
    printf("Laco de Repeticao FOR (1/3)\n");
    for (i = 0; i < 10; i++) {
        printf("%d..", i); 
    }
    printf("\n");
    
    printf("Laco de Repeticao WHILE (2/3)\n");
    while (w < 10) { 
        printf("%d..", w); 
        w = w + 1; 
    }
    
    printf("\n Laco de Repeticao DO WHILE (3/3)\n");
    do {
        printf("%d..", d);
        d = d + 1;	
    } while (d < 10);
    
    return 0;
}
