#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ERRO -1
#define SUCESSO 0
#define N_ENCOTRADO 1
#define N_P_REMOVER 2
#define VAZIO 3


// ESTRUTURA DA LISTA SIMPLESMENTE ENCADEADA PARA OS DEPARTAMENTOS
// Estrutura do nó para os departamentos
typedef struct Departamento{
    int codigo;
    char nomeDepartamento[50];
    float percentualBonificacao;
    struct Departamento *proximo;
}Departamento;

// Estrutura da lista encadeada simples para os departamentos
typedef struct {
    Departamento *inicio;
    Departamento *fim;
} ListaDepartamentos;

// ESTRUTURA DA LISTA DUPLAMENTE ENCADEADA PARA OS DADOS DOS FUNCIONÁRIOS
// Estrutura do nó para os funcionários
typedef struct Funcionario{
    char nome[50];
    char cpf[12];
    int idade;
    float salarioBruto;
    int codigoDepartamento;
    struct Funcionario *proximo;
    struct Funcionario *anterior;
} Funcionario;

// Estrutura da lista duplamente encadeada com nó cabeça para os funcionários
typedef struct {
    Departamento *cabeca; // Nó cabeça que marca o início da lista
} ListaDadosFuncionarios;

//DEPARTAMENTO
void criarListaDepartamentos(ListaDepartamentos *lista);
void inserirDepartamento(ListaDepartamentos *lista, int codigo, char nomeDepartamento[50], float percentualBonificacao);
int removerDepartamento(ListaDepartamentos *lista, ListaDadosFuncionarios *listaFuncionarios, int codigo);
Departamento *buscarDepartamento(ListaDepartamentos *lista, int codigo);

//FUNCIONARIO
void criarListaFuncionarios(ListaDadosFuncionarios *lista);
void inserirFuncionario(ListaDadosFuncionarios *lista, ListaDepartamentos *listaDepartamentos, char nome[50], char cpf[12], int idade, float salarioBruto, int codigoDepartamento);
int removerFuncionario(ListaDadosFuncionarios *lista,char *cpf);
Funcionario* buscarFuncionario(ListaDadosFuncionarios *lista, char *cpf);


//EXTRAS
int validarCPF(char *cpf);
float calcularSalarioLiquido(float salarioBruto, float percentualBonificacao);

#endif // TESTE_H_INCLUDED
