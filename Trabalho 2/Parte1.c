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
