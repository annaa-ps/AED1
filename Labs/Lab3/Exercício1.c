/*1) Registro de Alunos:
a) Crie uma estrutura Aluno com os seguintes campos: nome (tamanho
máximo de 50 caracteres), idade e média.
b) Crie um vetor de objetos Aluno.
c) Solicite ao usuário que insira os dados de até 10 alunos (nome, idade e
média) e armazene-os no vetor.
d) Exiba os dados dos alunos na tela*/

#include<stdlib.h>
#include<stdio.h>

//Estrutura Aluno
typedef struct {
    char nome[50];
    int idade;
    float media;
}Aluno; 

int main(){
    Aluno dados[10];
    int i;

    //Coletando os dados do usuário
    for(i=0; i<10; i++){
        printf("Informe o nome do [%d] aluno:\n", i+1);
        scanf("%s", &dados[i].nome);
        printf("Informe a idade do [%d] aluno:\n", i+1);
        scanf("%d", &dados[i].idade); 
        printf("Informe a media do [%d] aluno\n", i+1);
        scanf("%f", &dados[i].media);
        printf("\n");
    }
    printf("\n"); 
    //Exibindo na tela os dados dos alunos
    for(i=0; i<10; i++){
        printf("\nDados do aluno [%d]\n", i+1);
        printf("--------------------------------\n");
        printf("Nome: %s\n", dados[i].nome);
        printf("Idade: %d\n", dados[i].idade);
        printf("Media: %.2f\n", dados[i].media);
        printf("--------------------------------");
        printf("\n"); 
    }
    return 0; 
}