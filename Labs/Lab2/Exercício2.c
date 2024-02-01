/*2) Crie uma calculadora simples que irá solicitar ao usuário 2 números e uma operação
(+,-,*,/). Use uma estrutura condicional para realizar a operação correta e exibir o
resultado*/

#include<stdlib.h>
#include<stdio.h>

void calculardora(float num1, float num2, int opcao){
    if(opcao == 1){
        printf("A soma dos dois numeros eh: %.2f\n", num1+num2);
    }
    else if(opcao == 2){
        printf("A subtracao dos dois numeros eh: %.2f\n", num1-num2);
    }
    else if(opcao == 3){
        printf("A multiplicacao dos dois numeros eh: %.2f\n",num1*num2);
    }
    else if(opcao == 4){
        printf("A divisao dos dois numeros eh: %.2f\n",num1/num2);
    }else {
        printf("Opcao Invalida!\n");
    }
}

int main(){
    int opcao;
    float num1, num2;

    printf("Informe o primeiro numero:\n");
    scanf("%f", &num1);
    printf("Informe o segundo numero:\n");
    scanf("%f", &num2);

    printf("\nInforme a opcao da operacao que deseja:\n");
    printf("1. Para somar dois numeros\n");
    printf("2. Para subtrair dois numeros\n");
    printf("3. Para multiplicar dois numeross\n");
    printf("4. Para dividir dois numeros\n");
    scanf("%d", &opcao);

    printf("\n"); 

    calculardora(num1, num2, opcao); 

    return 0; 
}
