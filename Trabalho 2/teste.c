#include"teste.h"

//Função para criar ums lista de departamentos
void criarListaDepartamentos(ListaDepartamentos *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

//Função para criar uma lista de funcionários
void criarListaFuncionarios(ListaDadosFuncionarios *lista){
    lista->cabeca = NULL;
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
        soma += (cpfAux[i] - '0')*(10 - i);
    }
    digito1 = 11 - (soma % 11);
    if(digito1 >= 10){
        digito1 = 0;
    }

    //Calculo do segundo digito
    soma = 0;
    for(i=0; i<10; i++){
       soma += (cpfAux[i] - '0') * (11 - i);
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
    Departamento *novoDepartamento = (Departamento *)malloc(sizeof(Departamento));
    novoDepartamento->codigo = codigo;
    strcpy(novoDepartamento->nomeDepartamento, nomeDepartamento);
    novoDepartamento->percentualBonificacao = percentualBonificacao;
    novoDepartamento->proximo = NULL;

    if(lista->inicio== NULL){
        lista->inicio = novoDepartamento;
        lista->fim = novoDepartamento;
    }else{
        lista->fim->proximo = novoDepartamento;
        lista->fim = novoDepartamento;
    }
}

//Função para buscar departamento
Departamento *buscarDepartamento(ListaDepartamentos *lista, int codigo) {
    Departamento *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

// Função para inserir um funcionário na lista
void inserirFuncionario(ListaDadosFuncionarios *lista, ListaDepartamentos *listaDepartamentos, char nome[50], char cpf[12], int idade, float salarioBruto, int codigoDepartamento){
    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->cpf,cpf);
    novoFuncionario->idade = idade;
    novoFuncionario->salarioBruto = salarioBruto;
    novoFuncionario->proximo = NULL;
    novoFuncionario->anterior = NULL;

    //Encontrar o departamento correspondente
    Departamento *departamento = buscarDepartamento(&listaDepartamentos, codigoDepartamento);
    if(departamento == NULL){
        printf("\nDepartamento nao encontrado, portanto o funcionario nao sera inserido!\n");
        free(novoFuncionario);
        return;
    }

    if(lista->cabeca == NULL){
        lista->cabeca = novoFuncionario;
    }else{
        Funcionario *atual = lista->cabeca;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novoFuncionario;
        novoFuncionario->anterior = atual;
    }
}

// Função para remover um funcionário da lista
void removerFuncionario(ListaDadosFuncionarios *lista, char cpf[12]) {
    Funcionario *atual = lista->cabeca;
    Funcionario *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            if (anterior == NULL) {
                lista->cabeca = atual->proximo;
                free(atual);
                return;
            } else {
                anterior->proximo = atual->proximo;
                if (atual->proximo != NULL) {
                    atual->proximo->anterior = anterior;
                }
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("\nFuncionario nao encontrado.\n");
}

// Função para remover um departamento da lista
void removerDepartamento(ListaDepartamentos *listaD, int codigo) {
    Departamento *atual = listaD->inicio;
    Departamento *anterior = NULL;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            if (anterior == NULL) {
                listaD->inicio = atual->proximo;
                free(atual);
                return;
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("\nDepartamento nao encontrado!\n");
}

// Função para buscar um funcionário pelo CPF e exibir suas informações
Funcionario *buscarFuncionario(ListaDadosFuncionarios *lista, char cpf[12]) {
    Funcionario *atual = lista->cabeca;

    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) {
            printf("Nome: %s\n", atual->nome);
            printf("CPF: %s\n", atual->cpf);
            printf("Idade: %d\n", atual->idade);
            printf("Salario Bruto: %.2f\n", atual->salarioBruto);
            printf("Departamento: %d\n", atual->codigoDepartamento);
            return atual;
        }
        atual = atual->proximo;
    }

    printf("\nFuncionario nao encontrado.\n");
    return NULL;
}

// Função para calcular o salário líquido de um funcionário
float calcularSalarioLiquido(float salarioBruto, float percentualBonificacao) {
    return salarioBruto * (1 + percentualBonificacao / 100);
}



/*float calcularSalario(ListaDadosFuncionarios *listaF, ListaDepartamentos *listaD, char cpf[12]){
    NoF *funcionarioAtual = listaF->cabeca;
    float salarioLiquido = 0;
    int funcionarioEncontrado = 0; // Variável para verificar se o funcionário foi encontrado

    // Procurar o funcionário na lista de funcionários
    while (funcionarioAtual != NULL){
        if (strcmp(funcionarioAtual->cpf, cpf) == 0) { // Comparação de strings corrigida
            funcionarioEncontrado = 1; // Marcar que o funcionário foi encontrado
            // Funcionário foi encontrado, agora temos que procurar o departamento
            NoD *departamentoAtual = listaD->inicio;
            while (departamentoAtual != NULL){
                if (strcmp(funcionarioAtual->departamento, departamentoAtual->nomeDepartamento) == 0) { // Comparação de strings corrigida
                    // Calcular o salário líquido com base no salário bruto e no percentual de bonificação do departamento
                    salarioLiquido = funcionarioAtual->salarioBruto * (1 + departamentoAtual->percentualBonificacao / 100);
                    return salarioLiquido;
                }
                departamentoAtual = departamentoAtual->proximo;
            }
            // Se chegou aqui, significa que o departamento não foi encontrado
            printf("Departamento do funcionario nao encontrado.\n");
            return salarioLiquido;
        }
        funcionarioAtual = funcionarioAtual->proximo;
    }
    // Se chegou aqui, significa que o funcionário não foi encontrado
    if (!funcionarioEncontrado) {
        printf("Funcionario com CPF %s nao encontrado.\n", cpf);
    }
    return salarioLiquido;
}*/

