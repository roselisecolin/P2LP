#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu = 0;
    while(menu != 3){
        system("cls");
        menu = 0;
        printf("\n\n");
        printf("    |           Menu Principal           |\n");
        printf("    |____________________________________|\n");
        printf("    |                                    |\n");
        printf("    |         1- Exercicio 1             |\n");
        printf("    |         2- Exercicio 2             |\n");
        printf("    |         3- Sair                    |\n");
        printf("    |____________________________________|\n");
        printf("\n    Digite uma das opcoes acima: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                exercicio1();
                break;
            case 2:
                exercicio2();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("    Opcao invalida!\n\n");
                printf("\n    Pressione ENTER para continuar");
                fflush(stdin);
                getchar();
                system("cls");
        }
    }
    return 0;
}

void exercicio1(){
    system("cls");
    struct Cliente{
        char nome[256];
        char cpf[20];
    };
    struct Conta {
        int numero_da_conta;
        struct Cliente cliente;
        float  saldo;
    };

    struct Cliente cli;
    struct Conta conta_cli;

    printf("\t-- CADASTRAR CLIENTE --\n");
    printf("Informe o nome do cliente: ");
    scanf("%s", &cli.nome);
    printf("Informe o CPF: ");
    scanf("%s", &cli.cpf);
    getchar();
    printf("\n\t-- ABRIR CONTA --\n");
    printf("Informe o numero da conta: ");
    scanf("%d", &conta_cli.numero_da_conta);
    conta_cli.cliente = cli;
    conta_cli.saldo = 0;

    printf("\n\t-- INSERIR SALDO --\n");
    printf("Informe o valor do deposito: ");
    scanf("%f", &conta_cli.saldo);

    printf("\n\t -- DADOS DA CONTA --\n");
    printf("NOME   : %s\n", conta_cli.cliente.nome);
    printf("CPF    : %s\n", conta_cli.cliente.cpf);
    printf("N.CONTA: %d\n", conta_cli.numero_da_conta);
    printf("SALDO  : %.2f\n\n\n", conta_cli.saldo);

    printf("Pressione ENTER para continuar");
    fflush(stdin);
    getchar();
    system("cls");

}

void exercicio2(){
    system("cls");
    fflush(stdin);
    int sm, i, r, num, mult;
    char dig13, dig14, cnpj[14];
    printf("Informe o CNPJ (apenas digitos) : ");
    gets(cnpj);

    sm = 0; mult = 2;
    for (i=11; i>=0; i--) {
        num = cnpj[i] - 48;
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10){
           mult = 2;
        }
    }
    r = sm % 11;
    if ((r == 0) || (r == 1)){
         dig13 = '0';
    }else{
         dig13 = (11 - r) + 48;
    }

    sm = 0; mult = 2;
    for (i=12; i>=0; i--) {
        num = cnpj[i] - 48;
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10){
           mult = 2;
        }
    }
    r = sm % 11;
    if ((r == 0) || (r == 1)){
         dig14 = '0';
    }else{
         dig14 = (11 - r) + 48;
    }

    if ((dig13 == cnpj[12]) && (dig14 == cnpj[13])){
        printf("\nO CNPJ informado eh valido.");
    }else{
        printf("\nO CNPJ informado eh invalido.");
    }

    printf("\n\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    system("cls");
}
