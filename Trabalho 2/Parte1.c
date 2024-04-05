#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//ESTRUTURA DA LISTA SIMPLESMENTE ENCADEADA PARA OS DEPARTAMENTOS
//Estrutura do nó para os departamentos
typedef struct no{
  int codigo;
  char  nomeDepartamento[50];
  float percentualBonificacao; 
  struct no *proximo; 
}NoD;

//Estrutura da lista encadeada simples para os departamentos
typedef struct {
  NoD *inicio; 
  int tam; 
}ListaDepartamentos;


//ESTRUTURA DA LISTA DUPLAMENTE ENCADEADA PARA OS DADOS DOS FUNCIONÁRIOS
//Estrutura do nó para os funcionários
typedef struct no {
  char nome[50];
  char cpf[12];
  int idade;
  float salarioBruto;
  char departamento[15];
  struct no *proximo;
  struct no *anterior;
} NoF;

//Estrutura da lista duplamente encadeada com nó cabeça para os funcionários
typedef struct {
  NoF *cabeca; //Nó cabeça que marca o início da lista
  int tam;
} ListaDadosFuncionarios;

//Função para criar ums lista de departamentos 
void criarListaDepartamentos(ListaDepartamentos *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

//Função para criar uma lista de funcionários
void criarListaFuncionarios(ListaDadosFuncionarios *lista){
    lista->cabeca = NULL;
    lista->tam = 0; 
}

//Função para validar CPF
int validarCPF(char *cpf){
    int i, j, soma=0, digito1, digito2;
    char cpfAux[11];
    
    //Remover os pontos e o hífen e copiar para cpfAux
    for(i=0, j=0; i<11; i++){
        if(cpf[i] != '.' && cpf[i]!= '-'){
            cpfAux[j] = cpf[i];
            j++;
        }
    }
    
    //Calculo do primeiro digito
    for(i=0; i<9; i++){
        soma+= (cpfAux - '0')*(10 - i);
    }
    digito1 = 11 - (soma % 11);
    if(digito1 >= 10){
        digito1 = 0; 
    }
    
    //Calculo do segundo digito 
    soma = 0;
    for(i=0; i<10; i++){
        soma+=(cpfAux[i] - '0')*(11 - i);
    }
    digito2 = 11 - (soma % 11);
    if(digito2 >= 10){
        digito2 = 0;
    }
    
    //Veririficar se os digitos calculados sao iguais aos digitos fornecidos
    if((digito1 == cpfAux[9] - '0')&&(digito2 == cpfAux[10] - '0')){
        return 1; //CPF Válido
    }else{
        return 0; //CPF Inválido
    }
    
}


//Função para inserir um departamento
void inserirDepartamento(ListaDepartamentos *lista, int codigo, char nomeDepartamento[50], float percentualBonificacao){
    NoD *novoDepartamento = malloc(sizeof(NoD));
    if(novoDepartamento){
        novoDepartamento->codigo = codigo;
        strcpy(novoDepartamento->nomeDepartamento, nomeDepartamento);
        novoDepartamento->percentualBonificacao = percentualBonificacao;
        novoDepartamento->proximo = lista->inicio;
        lista->tam++;
    }else{
        printf("\nErro ao alocar memoria para o departamento!\n");
    }
}

//Função para inserir um funcionário na lista
void inserirdFuncionario(ListaDadosFuncionarios *lista, char nome[50], char cpf[12], int idade, float salarioBruto, char departamento[15]){
    NoF *novoFuncionario = malloc(sizeof(NoF));
    if(novoFuncionario){
        //Realiza a validação do CPF antes de inserir o funcionário
        if(validarCPF(cpf)){
        strcpy(novoFuncionario->nome,nome);
        strcpy(novoFuncionario->cpf, cpf);
        novoFuncionario->idade = idade;
        novoFuncionario->salarioBruto = salarioBruto;
        strcpy(novoFuncionario->departamento, departamento);
        novoFuncionario->proximo = lista->cabeca;
        novoFuncionario->anterior = NULL;
        if(lista->cabeca){
            lista->cabeca->anterior = novoFuncionario;
        }
        lista->cabeca = novoFuncionario;
        lista->tam++;   
        }else{
            printf("\nCPF Invalido!\n");
            free(novoFuncionario);
        }
    }else{
        printf("\nErro ao alocar memoria para o funcionario!\n");
    }
}

