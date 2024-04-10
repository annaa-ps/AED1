#include "teste.h"

int main() {
    ListaDepartamentos listaDepartamentos;
    ListaDadosFuncionarios listaFuncionarios;
    int opcao, codigoDepartamento;
    char nome[50], cpf[12];
    int idade;
    float salarioBruto, percentualBonificacao;

    criarListaDepartamentos(&listaDepartamentos);
    criarListaFuncionarios(&listaFuncionarios);

    do {
        printf("\n-------------------------MENU DE OPCOES-------------------------------\n");
        printf("1 - Inserir departamento\n2 - Inserir funcionario\n3 - Remover funcionario\n4 - Remover departamento\n");
        printf("5 - Buscar funcionario\n6 - Listar departamentos\n7 - Listar funcionarios de um departamento\n");
        printf("8 - Listar todos os funcionarios\n9 - Calcular salario liquido\n10 - Sair\n");
        printf("----------------------------------------------------------------------\n");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite o codigo do departamento: ");
                scanf("%d", &codigoDepartamento);
                getchar(); // Limpar o buffer do teclado
                printf("Digite o nome do departamento: ");
                fgets(nome, 50, stdin);
                printf("Digite o percentual de bonificacao do departamento: ");
                scanf("%f", &percentualBonificacao);
                 inserirDepartamento(&listaDepartamentos, codigoDepartamento, nome, percentualBonificacao);
                break;
            case 2:
                printf("Digite o nome do funcionario: ");
                fgets(nome, 50, stdin);
                printf("Digite o CPF do funcionario: ");
                fgets(cpf, 12, stdin);
                printf("Digite a idade do funcionario: ");
                scanf("%d", &idade);
                printf("Digite o salario bruto do funcionario: ");
                scanf("%f", &salarioBruto);
                printf("Digite o codigo do departamento: ");
                scanf("%d", &codigoDepartamento);
                inserirFuncionario(&listaFuncionarios, &listaDepartamentos, nome, cpf, idade, salarioBruto, codigoDepartamento);
                break;
            case 3:
                printf("Digite o CPF do funcionario para remover: ");
                fgets(cpf, 12, stdin);
                removerFuncionario(&listaFuncionarios, cpf);
                break;
            case 4:
                printf("Digite o codigo do departamento para remover: ");
                scanf("%d", &codigoDepartamento);
                removerDepartamento(&listaDepartamentos, codigoDepartamento);
                break;
            case 5:
                printf("Digite o CPF do funcionario para buscar: ");
                fgets(cpf, 12, stdin);
                buscarFuncionario(&listaFuncionarios, cpf);
                break;
            case 6:
                //listarDepartamentos(&listaDepartamentos);
                break;
            case 7:
                printf("Digite o codigo do departamento para listar os funcionarios: ");
                scanf("%d", &codigoDepartamento);
                //listarFuncionariosDepartamento(&listaFuncionarios, &listaDepartamentos, codigoDepartamento);
                break;
            case 8:
                //listarTodosFuncionarios(&listaFuncionarios, &listaDepartamentos);
                break;
            case 9:
                printf("Digite o CPF do funcionario para calcular o salario liquido: ");
                fgets(cpf, 12, stdin);
                Funcionario *funcionario = buscarFuncionario(&listaFuncionarios, cpf);
                if (funcionario != NULL) {
                    Departamento *departamento = buscarDepartamento(&listaDepartamentos, funcionario->codigoDepartamento);
                    if (departamento != NULL) {
                        float salarioLiquido = calcularSalarioLiquido(funcionario->salarioBruto, departamento->percentualBonificacao);
                        printf("O salario liquido do funcionario e: %.2f\n", salarioLiquido);
                    } else {
                        printf("Departamento do funcionario nao encontrado.\n");
                    }
                } else {
                    printf("Funcionario nao encontrado.\n");
                }
                break;
            case 10:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 10);

    return 0;
}
