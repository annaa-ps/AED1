//ESTRUTURA DA LISTA SIMPLESMENTE ENCADEADA PARA OS DEPARTAMENTOS
typedef struct no{
  int codigo;
  char  nomeDepartamento[50];
  float percentualBonificacao; 
  struct no *proximo; 
}NoD;

typedef struct {
  NoD *inicio; 
  int tam; 
}ListaDepartamentos;


//ESTRUTURA DA LISTA DUPLAMENTE ENCADEADA PARA OS DADOS DOS FUNCIONÁRIOS
typedef struct no {
  char nome[50];
  char cpf[12];
  int idade;
  float salarioBruto;
  char departamento[15];
  struct no *proximo;
  struct no *anterior;
} NoF;

typedef struct {
  NoF *cabeca; //Nó cabeça que marca o início da lista
  int tam;
} ListaDadosFuncionarios;

