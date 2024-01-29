#include<stdlib.h>
#include<stdio.h>

/*Ponteiro para ponteiro*/

int main(){
    int A = 100, *B, **C;

    //Atribuindo a variável B o endereço da variável A
    B = &A;  
    //Atribuindo para a varável C o endereço da variável B
    C = &B; 

    printf("Endereco de A:%p\t Conteudo de A:%d\n", &A, A);
    printf("\nEndereco de B:%p\t Conteudo de B:%p\n", &B, B);
    printf("Conteudo apontado por B:%d\n", *B); 
    printf("\nEndereco de C:%p\t Conteudo de C:%p\n", &C, C);
    printf("Conteudo apontado por C:%d\n", **C); 

    return 0; 
}
