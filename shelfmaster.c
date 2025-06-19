#include <stdio.h>
#include <string.h>

int menu();
void limpar_buffer();
struct data
{
    int dia;
    int mes;
    int ano;
};

enum category
{
    literatura,
    poesia,
    engenharia,
    computer,
    outros
};

struct livro
{
    char title[100];
    struct data datacompra;
    float price;
    enum category categoria;
};

int main()
{
    int option = menu();
    if(option == 0)
    {
        return 0;
    }
    if(option == 1)
    {
        limpar_buffer(); //limpar o buffer do teclado
        struct livro newlivro;
        printf("Digite o nome do livro: "); //nome do livro/
        scanf("%c", newlivro.title);

        limpar_buffer(); //limpar o buffer do teclado

        printf("Digite o dia da data de compra: "); //data de compra(mes dia ano)
        scanf("%d", &newlivro.datacompra.dia);
        printf("Digite o mes da data de compra: ");
        scanf("%d", &newlivro.datacompra.mes);
        printf("Digite o ano da data de compra: ");
        scanf("%d", &newlivro.datacompra.ano);

        printf("Digite o preco do livro: "); //preco do livro
        scanf("%f", &newlivro.price);

         limpar_buffer(); //limpar o buffer do teclado

        int categoria_temp; //variavel temp pq o enum comeca em 0, entao a opcao escolhida ta sempre +1
        printf("Escolha a categoria do livro:\n1 - Literatura\n2 - Poesia\n3 - Engenharia\n4 - Computacao\n5 - Folclore\n6 - Outros\nOpcao: ");
        scanf("%d", &categoria_temp);
        newlivro.categoria = categoria_temp - 1;
    }
}

int menu()
{
    int choice;
    printf("Bem-vindo a Biblioteca Romaniuk\n");
    printf("1 - Cadastrar um livro\n2 - Listar biblioteca\n3 - Consultar estatísticas\n0 - Sair\nSelecione uma das opcoes: ");
    scanf("%d", &choice);
    return choice;
}
void limpar_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}