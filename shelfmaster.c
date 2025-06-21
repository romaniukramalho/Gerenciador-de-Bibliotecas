#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct das datas
struct data
{
    int dia;
    int mes;
    int ano;
};

//enum que categoriza o tipo do livro
enum category
{
    literatura,
    poesia,
    engenharia,
    computer,
    folclore,
    outros
};

//funcao pra dar print na categoria
const char* nome_categoria(enum category cat) 
{
    switch (cat) 
    {
        case literatura: return "Literatura";
        case poesia: return "Poesia";
        case engenharia: return "Engenharia";
        case computer: return "Computacao";
        case folclore: return "Folclore";
        case outros: return "Outros";
        default: return "Desconhecido";
    }
}

//struct do livro
struct livro
{
    char title[100];
    struct data datacompra;
    float price;
    enum category categoria;
};

//struct que contém todos os livros armazenados
struct livro acervo[15] = 
{
    { "An Ukranian Journey", {17, 2, 2020}, 35.00, folclore },
    { "Logica de Programacao", {5, 3, 2025}, 67.20, computer }
};
int total_livros = 2;


//prototipagem das funções
int menu();
void limpar_buffer();
void listar_livros(struct livro acervo[]);
void detalhamento(struct livro acervo[], int witchdetails);
void estatisticas(struct livro acervo[], int total_livros);

int main()
{
    int whichdetails;
    int option = 1;
    while(option != 0)
    {
        system("clear"); //limpa tela
        option = menu();
        if(option == 0)
        {
            return 0; // encerra o programa
        }

        if(option == 1)
        {
            struct livro newlivro; //variável pra guardar o livros cadastrados

            limpar_buffer(); //limpa buffer do teclado
            system("clear"); //limpa tela

            printf("Digite o nome do livro: ");
            fgets(newlivro.title, 100, stdin);
            newlivro.title[strcspn(newlivro.title, "\n")] = '\0';

            system("clear"); //limpa tela

            printf("Digite o dia da data de compra: ");
            scanf("%d", &newlivro.datacompra.dia);
            printf("Digite o mes da data de compra: ");
            scanf("%d", &newlivro.datacompra.mes);
            printf("Digite o ano da data de compra: ");
            scanf("%d", &newlivro.datacompra.ano);

            system("clear"); //limpa tela

            printf("Digite o preco do livro: ");
            scanf("%f", &newlivro.price);

            system("clear"); //limpa tela

            int categoria_temp;
            printf("Escolha a categoria do livro:\n1 - Literatura\n2 - Poesia\n3 - Engenharia\n4 - Computacao\n5 - Folclore\n6 - Outros\nOpcao: ");
            scanf("%d", &categoria_temp);
            newlivro.categoria = categoria_temp - 1; //converte a opção do usuário para o índice do enum 

            system("clear"); //limpa tela

            printf("--- Livro Cadastrado ---\n");
            printf("Titulo: %s\nData de compra: %d/%d/%d\nPreco: R$ %.2f\nCategoria: %s\n", 
                newlivro.title, 
                newlivro.datacompra.dia, 
                newlivro.datacompra.mes, 
                newlivro.datacompra.ano, 
                newlivro.price, 
                nome_categoria(newlivro.categoria));

            acervo[total_livros] = newlivro;
            total_livros++;

        }

        if(option == 2)
        {
            system("clear"); //limpa tela
            listar_livros(acervo);
            printf("\nCaso queira detalhar algum desses livros, digite o numero correspondente ou 0 para sair: ");
            scanf("%d", &whichdetails);
            if(whichdetails != 0)
            {
                whichdetails = whichdetails - 1;
                detalhamento(acervo, whichdetails);
            }
            limpar_buffer();
            getchar();
        }
        if(option == 3)
        {
            limpar_buffer();
            system("clear");
            estatisticas(acervo, total_livros);
        }
    }
}

int menu()
{
    int choice;
    printf("Bem-vindo a Biblioteca Romaniuk\n");
    printf("1 - Cadastrar um livro\n2 - Listar biblioteca\n3 - Consultar estatisticas\n0 - Sair\nSelecione uma das opcoes: ");
    scanf("%d", &choice);
    return choice;
}

void limpar_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void listar_livros(struct livro acervo[])
{
    int i;
    for (int i = 0; i < total_livros; i++) 
    {
        printf("%d - %s\n", i + 1, acervo[i].title);
    }
}

void detalhamento(struct livro acervo[], int whichdetails)
{
    printf("Titulo: %s\nData de compra: %d/%d/%d\nPreco: R$ %.2f\nCategoria: %s\n", 
        acervo[whichdetails].title, 
        acervo[whichdetails].datacompra.dia, 
        acervo[whichdetails].datacompra.mes, 
        acervo[whichdetails].datacompra.ano, 
        acervo[whichdetails].price, 
        nome_categoria(acervo[whichdetails].categoria));
}

void estatisticas(struct livro acervo[], int total_livros)
{
    int i, catlit = 0, catpoe = 0, cateng = 0, catcomp = 0, catfolk = 0, catout = 0;
    float sumprices = 0, sumlit = 0, sumpoe = 0, sumeng = 0, sumcomp = 0, sumfolk = 0, sumout = 0;
    for(i = 0; i < total_livros; i++)
    {
        if(acervo[i].categoria == 0)
        {
            catlit++;
            sumlit = sumlit + acervo[i].price;
        }
        if(acervo[i].categoria == 1)
        {
            catpoe++;
            sumpoe = sumpoe + acervo[i].price;
        }
        if(acervo[i].categoria == 2)
        {
            cateng++;
            sumeng = sumeng + acervo[i].price;
        }
        if(acervo[i].categoria == 3)
        {
            catcomp++;
            sumcomp = sumcomp + acervo[i].price;
        }
        if(acervo[i].categoria == 4)
        {
            catfolk++;
            sumfolk = sumfolk + acervo[i].price;
        }
        if(acervo[i].categoria == 5)
        {
            catout++;
            sumout = sumout + acervo[i].price;
        }
        sumprices = sumprices + acervo[i].price;   
    }
    printf("Literatura - %d livros, R$%.2f investidos\n", catlit, sumlit);
    printf("Poesia - %d livros, R$%.2f investidos\n", catpoe, sumpoe);
    printf("Engenharia - %d livros, R$%.2f investidos\n", cateng, sumeng);
    printf("Computacao - %d livros, R$%.2f investidos\n", catcomp, sumcomp);
    printf("Folclore - %d livros, R$%.2f investidos\n", catfolk, sumfolk);
    printf("Outros - %d livros, R$%.2f investidos\n", catout, sumout);
    printf("Total de livros: %d, Valor total investido: R$%.2f\n", total_livros, sumprices);
    getchar();
}