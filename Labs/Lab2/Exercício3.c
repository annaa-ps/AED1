/*3) Crie um algoritmo de tabuadas. O programa deve solicitar um número ao usuário e
utilizar um loop para exibir a tabuada desse número de 1 a 10.*/

#include<stdlib.h>
#include<stdio.h>

int main(){

    int num, i; 

    printf("Digite um numero:\n");
    scanf("%d", &num);

    if(num < 0){
        printf("Para efetuar a tabuada o numero deve ser positivo");
        return 1; 
    }

    printf("\nTabuada do %d:\n", num);
    for(i= 1; i<=10; i++){
        printf("%d x %d = %d\n", num, i, num*i); 
    }

    return 0; 
}
