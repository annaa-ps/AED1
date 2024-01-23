#include<stdlib.h>
#include<stdio.h>

/*O que é e como criar um ponteiro?
-> Endereço de memória é representado pelo sistema hexadecimal;
-> Cada variável possui um ÚNICO endereço de memória;
-> Um ponteiro é uma variável que armazena um endereço de memória; */

int main(){

    int num = 10; 
    int *p; 

    p = &num; 

    printf("Valor de num: %d\n", num);
    printf("Endereco de num: %p\n", &num);
    printf("Valor de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);
    
    return 0; 
}
