#include<stdlib.h>
#include<stdio.h>

/*Lista 1 -> Exercício 1*/

//Estrutura para representar o produto com seus dados
typedef struct{
    char nome_produto[50];
    int codigo;
    float preco; 
    int qtd_estoque; 
}Produto; 

//Função para cadastrar um novo produto 
void novoProduto(Produto *produtos, int *numProdutos){
    printf("\nInforme o  nome do produto:\n");
    scanf("%s", produtos[*numProdutos].nome_produto);
    printf("Informe o cogido do produto:\n");
    scanf("%d", &produtos[*numProdutos].codigo);
    printf("Informe o preco do produto:\n");
    scanf("%f", &produtos[*numProdutos].preco);
    printf("Informe a quantidade de estoque:\n");
    scanf("%d", &produtos[*numProdutos].qtd_estoque);

    (*numProdutos)++;
    printf("\nProduto adicionado!\n");
}

//Função para exibir detalhe de um produto dado o seu código 
void FiltrarProduto(Produto produtos[], int numProdutos,  int codigo){
    int i; 
    for (i=0; i<numProdutos; i++){
        if(produtos[i].codigo == codigo){
            printf("\nDetalhes do produto:\n");
            printf("Produto: %c\n", produtos[i].nome_produto);
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Preco: %f\n", produtos[i].preco);
            printf("Quantidade do produto em estoque: %d\n", produtos[i].qtd_estoque); 
            return; 
        }
    }
    printf("Produto nao encontrado!\n"); 
}

//Função para atualizar o preço de um produto 
void atualizarPreco(Produto *estoque, int numProdutos, int codigo, float novoPreco){
    int i;
    for(i=0; i<numProdutos; i++){
        if(estoque[i].codigo == codigo){
            estoque[i].preco = novoPreco;
            printf("Preco do produto atualizado!\n"); 
            return; 
        }
    }
}

//Função para realizar uma venda
void realizarVenda(Produto *estoque, int numProdutos, int codigo, int qtdVendida){
    int i;
    for(i=0; i<numProdutos; i++){
        if(estoque[i].codigo == codigo){
            if(estoque[i].qtd_estoque >= qtdVendida){
                estoque[i].qtd_estoque -= qtdVendida; 
                printf("Venda realizada!\n");
                return; 
            }else{
                printf("Quantidade insuficiente em estoque!\n");
                return; 
            }
        }
    }
    printf("Produto nao esta em estoque!\n"); 
}

// Função para listar todos os produtos em estoque
void listarProdutos(Produto *estoque, int numProdutos) {
    printf("Produtos em estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        if (estoque[i].qtd_estoque > 0) {
            printf("Codigo: %d, Preco: %.2f, Quantidade em estoque: %d\n", 
                   estoque[i].codigo, estoque[i].preco, estoque[i].qtd_estoque);
        }
    }
}

int main (){
    int escolha; 
    Produto produto[100];
    int numProdutos = 0;  
    int codigo,quantidade; 
    float novoPreco, preco; 

    printf("Escolha a operacao:\n");
    printf("1. Cadastrar um novo produto\n");
    printf("2. Exibir detalhes de um produto\n");
    printf("3. Atualizar o preco de um produto\n");
    printf("4. Realizar uma venda\n");
    printf("5. Listar todos os produtos em estoque\n"); 
    printf("\nDigite o numero da operacao desejada: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            novoProduto(produto, &numProdutos); 
            break;
        case 2:
            printf("Informe o codigo do produto: \n"); 
            scanf("%d", &codigo); 
            FiltrarProduto(produto, numProdutos, codigo); 
            break;
        case 3:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite o novo preco: ");
            scanf("%f", &novoPreco);
            atualizarPreco(produto, numProdutos, codigo, novoPreco);
            break;
        case 4:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidade);
            realizarVenda(produto, numProdutos, codigo, quantidade);
            break;
        case 5:
            listarProdutos(produto, numProdutos);
            break; 
        default:
            printf("Opcao invalida!\n");
    }
    return 0; 
}
