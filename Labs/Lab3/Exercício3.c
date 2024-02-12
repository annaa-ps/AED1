/*3) Cadastro de Livros:
a) Crie uma estrutura Livro com os campos título (tamanho máximo de 100
caracteres), autor (tamanho máximo de 50 caracteres) e ano de publicação.
b) Crie um vetor de objetos Livro.
c) Permita ao usuário cadastrar até 5 novos livros, inserindo título, autor e ano
de publicação.
d) Implemente uma função para buscar um livro pelo título e exibi-lo na tela.*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Estrtura Livro
typedef struct{
    char titulo[100];
    char autor[50];
    int ano; 
}Livro;

//Função para buscar livro
void buscarLivro(Livro livros[], char tituloBusca[]){
    int i;
    for(i=0; i<5; i++){
        if(strcmp(livros[i].titulo, tituloBusca) == 0){
            printf("\nLivro encontrado!\n");
            printf("--------------------------------------------\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano de publicacao: %d\n", livros[i].ano);
            printf("--------------------------------------------");
            return;
        }
    }
    printf("\nLivro com o titulo [%s] nao encontrado\n", tituloBusca); 
}


int main(){
    Livro livros[5];
    int i;
    char tituloBusca[100];

    //Recebendo dados do usuário
    for(i=0;i<5;i++){
        printf("Informe os dados do %d livro:", i+1);
        printf("\nTitulo: ");
        scanf(" %[^\n]", livros[i].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", livros[i].autor);

        printf("Ano de publicacao: ");
        scanf("%d", &livros[i].ano);
        printf("\n");
    }

    printf("\n");

    //Busca de livro
    printf("Digite o titulo que deseja buscar:\n");
    scanf(" %[^\n]", tituloBusca);
    buscarLivro(livros, tituloBusca); 

    return 0;
}