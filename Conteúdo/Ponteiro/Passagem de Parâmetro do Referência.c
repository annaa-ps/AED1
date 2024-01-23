#include<stdlib.h>
#include<stdio.h>

/*Como passar um ponteiro como parâmetro?
- Situações que usa o (*):
-> Quando cria a variável (Ponteiro);
-> Quando quer imprimir o conteúdo apontado pelo ponteiro;*/

/*Passagem de Parâmtro por referência:
  -> Passa o endereço da variável e não o conteúdo;*/ 
void imprimir (int *num){
    printf("%d\n", *num);
    *num = 80; 
}

int main(){
    
    int idade = 35; 
    
    imprimir (&idade); 
    printf("No main: %d\n", idade); 

    return 0; 
}
