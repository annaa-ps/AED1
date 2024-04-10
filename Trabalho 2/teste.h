#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

void criarListaDepartamentos(ListaDepartamentos *lista);
void criarListaFuncionarios(ListaDadosFuncionarios *lista);
int validarCPF(char *cpf);
void inserirDepartamento(ListaDepartamentos *lista, int codigo, char nomeDepartamento[50], float percentualBonificacao);
Departamento *buscarDepartamento(ListaDepartamentos *lista, int codigo);
void inserirFuncionario(ListaDadosFuncionarios *lista, ListaDepartamentos *listaDepartamentos, char nome[50], char cpf[12], int idade, float salarioBruto, int codigoDepartamento);
void removerFuncionario(ListaDadosFuncionarios *lista, char cpf[12]);
void removerDepartamento(ListaDepartamentos *listaD, int codigo);
Funcionario *buscarFuncionario(ListaDadosFuncionarios *lista, char cpf[12]);
float calcularSalarioLiquido(float salarioBruto, float percentualBonificacao);

#endif // TESTE_H_INCLUDED
