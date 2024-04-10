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
        printf("[1] - Inserir departamento\n[2] - Inserir funcionario\n[3] - Remover funcionario\n[4] - Remover departamento\n");
        printf("[5] - Buscar funcionario\n[6] - Listar departamentos\n[7] - Listar funcionarios de um departamento\n");
        printf("[8] - Listar todos os funcionarios\n[9] - Calcular salario liquido\n[10]- Sair\n");
        printf("----------------------------------------------------------------------\n");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("\nDigite o codigo do departamento: ");
                scanf("%d", &codigoDepartamento);
                getchar(); // Limpar o buffer do teclado
                printf("Digite o nome do departamento: ");
                fgets(nome, 50, stdin);
                printf("Digite o percentual de bonificacao do departamento: ");
                scanf("%f", &percentualBonificacao);
                inserirDepartamentoOrdenado(&listaDepartamentos, codigoDepartamento, nome, percentualBonificacao);

                break;
            case 2:
                printf("\nDigite o nome do funcionario: ");
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
                printf("\nDigite o CPF do funcionario para remover: "  );
                fgets(cpf, 12, stdin);
                Funcionario *funcionarioRemovido = removerFuncionario(&listaFuncionarios, cpf);
                if (funcionarioRemovido != NULL) {
                    printf("\nFuncionario removido com sucesso.\n");
                } else {
                    printf("\nFuncionario nao encontrado ou lista vazia.\n");
                }
                break;


            case 4:
                printf("\nDigite o codigo do departamento para remover: ");
                scanf("%d", &codigoDepartamento);
                int resultadoRemocaoDep = removerDepartamento(&listaDepartamentos, &listaFuncionarios, codigoDepartamento);
                if (resultadoRemocaoDep == SUCESSO) {
                    printf("Departamento removido com sucesso.\n");
                } else if (resultadoRemocaoDep == N_ENCOTRADO) {
                    printf("Departamento nao encontrado.\n");
                } else if (resultadoRemocaoDep == N_P_REMOVER) {
                    printf("Remocao nao permitida, existem funcionarios associados a este departamento.\n");
                }
                break;

            case 5:
                printf("\nDigite o CPF do funcionario para buscar: ");
                fgets(cpf, 12, stdin);
                buscarFuncionario(&listaFuncionarios, cpf);
                break;
            case 6:
                //listarDepartamentos(&listaDepartamentos);
                break;
            case 7:
                printf("Digite o codigo do departamento para listar os funcionarios: ");
                scanf("%d", &codigoDepartamento);
                //ListarFuncionariosDepartamento(&listaFuncionarios, &listaDepartamentos, codigoDepartamento);
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
                        printf("-------------------------------------------------------------");
                        printf("\nO salario liquido do funcionario e: %.2f\n", salarioLiquido);
                        printf("-------------------------------------------------------------");
                    } else {
                        printf("\nDepartamento do funcionario nao encontrado!\n");
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
