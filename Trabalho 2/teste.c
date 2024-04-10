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
    // Validar o CPF
    if (!validarCPF(cpf)) {
        printf("\nCPF invalido.\n");
        return;
    }

    // Verificar se o CPF já existe na lista de funcionários
    if (buscarFuncionario(lista, cpf) != NULL) {
        printf("\nFuncionario com CPF %s ja existe na lista!\n", cpf);
        return;
    }

    Funcionario *novoFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (novoFuncionario == NULL) {
        printf("\nErro ao alocar memoria para novo funcionario!\n");
        return;
    }

    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->cpf, cpf);
    novoFuncionario->idade = idade;
    novoFuncionario->salarioBruto = salarioBruto;
    novoFuncionario->codigoDepartamento = codigoDepartamento;
    novoFuncionario->proximo = NULL;
    novoFuncionario->anterior = NULL;

    //Encontrar o departamento correspondente
    Departamento *departamento = buscarDepartamento(listaDepartamentos, codigoDepartamento);
    if(departamento == NULL){
        printf("\nDepartamento nao encontrado, portanto o funcionario nao sera inserido!\n");
        free(novoFuncionario);
        return;
    }

    // Inserir funcionário no final da lista
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

    printf("\nFuncionario inserido com sucesso!\n");
}

//Função para remover um departamento
int removerDepartamento(ListaDepartamentos *lista, ListaDadosFuncionarios *listaFuncionarios, int codigo) {
    Departamento *aux = lista->inicio;
    Departamento *remove = NULL;

    // Encontrar o departamento com o código especificado
    while (aux != NULL && aux->codigo != codigo) {
        remove = aux;
        aux = aux->proximo;
    }

    if (aux == NULL) return N_ENCOTRADO; // Departamento não encontrado, remoção não permitida

    // Verificar se há funcionários associados a este departamento
    Funcionario *funcionarioAtual = listaFuncionarios->cabeca;
    while (funcionarioAtual != NULL) {
        if (funcionarioAtual->codigoDepartamento == aux->codigo) {
            return N_P_REMOVER; // Remoção não permitida se houver funcionários associados
        }
        funcionarioAtual = funcionarioAtual->proximo;
    }

    // Remover o departamento
    if (remove == NULL) {
        lista->inicio = aux->proximo;
    } else {
        remove->proximo = aux->proximo;
    }

    free(aux);
    printf("Departamento removido com sucesso.\n");
    return SUCESSO; // Remoção bem-sucedida
}

//Função para remover um funcionário
int removerFuncionario(ListaDadosFuncionarios *lista,char *cpf) {
    if(lista == NULL || lista->cabeca == NULL) return VAZIO;
    Funcionario *remove = lista->cabeca;
    while(remove != NULL ){
        if(strcmp(remove->cpf,cpf) == 0){//Encontra o funcionario pelo cpf, uma vez encotrado,continua com a remoção
            if(remove->anterior != NULL){
                remove->anterior->proximo = remove->proximo; //Atualiza o próximo do nó anterior
            } else {
                lista->cabeca = remove->proximo; //é o primeiro da lista
            }
            if(remove->proximo != NULL){
                remove->proximo->anterior = remove->anterior;// Atualiza o anterior do próximo nó
            }
            free(remove);
            return SUCESSO;
        }
        //Caminha para o proximo funcionario dentro da lista.
        remove = remove->proximo;
    }
    /**
     * @brief Se o funcionario dono do CPF não foi encontrado,irá retornar um erro.
    */
    return ERRO;
}

//Função para buscar um funcionário
Funcionario* buscarFuncionario(ListaDadosFuncionarios *lista, char *cpf){
    if(lista == NULL || lista->cabeca == NULL){
        printf("Lista Vazia\n");
        return NULL;
    }
    Funcionario *busca = lista->cabeca;
    while (busca != NULL) {
        if (strcmp(busca->cpf, cpf) == 0) {
            printf("\nInformacoes sobre o funcionario:\n");
            printf("Nome: %s\n", busca->nome);
            printf("CPF: %s\n", busca->cpf);
            printf("Idade: %d\n", busca->idade);
            printf("Departamento: %d\n", busca->codigoDepartamento);
            printf("Salario Bruto: %.2f\n", busca->salarioBruto);
            return busca; // Retorna o nó do funcionário encontrado
        }
        busca = busca->proximo; // Avança para o próximo funcionário na lista
    }

    printf("\nFuncionario com CPF:%s, nao encontrado!\n",cpf);
    return NULL;
}

// Função para calcular o salário líquido de um funcionário
float calcularSalarioLiquido(float salarioBruto, float percentualBonificacao) {
    // Calcular o valor do bônus/desconto
    float bonificacao = salarioBruto * (percentualBonificacao / 100);

    // Calcular o salário líquido
    float salarioLiquido = salarioBruto + bonificacao;

    return salarioLiquido;
}
