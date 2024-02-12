/*2) Calculadora de Área:
a) Defina uma estrutura Retangulo com os campos comprimento e largura.
b) Crie um vetor de objetos Retangulo.
c) Solicite ao usuário que insira o comprimento e a largura de até 5 retângulos e
armazene esses valores nos objetos Retangulo.
d) Calcule a área de cada retângulo e exiba os resultados na tela.
Observação: A área é calculada por comprimento * largura*/

#include<stdlib.h>
#include<stdio.h>

//Estrutura Retângulo
typedef struct{
    float comprimento;
    float largura;
}Retangulo;



int main(){
    Retangulo dados[5];
    float area[5];
    int i;

    //Solicitando dados do usuário
    for(i=0; i<5;i++){
        printf("Insira as medidas do [%d] retangulo:\n", i+1);
        printf("Comprimento:\n");
        scanf("%f", &dados[i].comprimento);
        printf("Largura:\n");
        scanf("%f", &dados[i].largura);
        printf("\n");
    }

    //Calculando a área (comprimento * largura)
    for(i=0;i<5;i++){
        area[i] = dados[i].comprimento * dados[i].largura;
    }

    printf("\n");
    
    //Exibindo dados 
    for(i=0; i<5; i++){
        printf("\nDados do retangulo [%d]\n", i+1);
        printf("--------------------------------\n");
        printf("Comprimento: %.2f\n", dados[i].comprimento);
        printf("Largura: %.2f\n", dados[i].largura);
        printf("Area: %.2f\n", area[i]);
        printf("--------------------------------");
        printf("\n"); 
    }

    return 0;
}