#include <stdio.h>
#include <stdlib.h>


int menu ();
void InserirInicio(int num);

struct ElementoDaLista_Simples
{
    int dado;
    struct ElementoDaLista_Simples *prox;
} *Head;


int main()
{

    int op, num, pos, c;
    Head = NULL;
    
    while (1)
    {
        op = menu();
        switch (op)
        {
        case 1: //inserir no inicio da lista
            printf("Digite o número desejado: ");
            scanf_s("%d", &num);
            while ((c = getchar()) != '\n' && c != EOF) {} //sempre limpe o buffer

            InserirInicio(num);
            break;

        case 2: //inserir no fim da lista
            printf("Digite o número desejado: ");
            scanf_s("%d", &num);
            while ((c = getchar()) != '\n' && c != EOF) {} //sempre limpe o buffer

            InserirFim(num);
            break;

        case 3: //inserir no meio da lista
            /* code */
            break;

        case 4: //remover da lista 
            /* code */
            break;

        case 5: //mostrar toda a lista
            /* code */
            break;

        case 6:
            /* code */
            return 0;
        
        default:
            printf("Invalido\n");
        }
    }
    
    
    return 0;
}

int menu()
{


    int op, c;

    system("clear"); // Comando usado para limpar a tela do terminal linux
    //system("cls"); // Comando usado para limpar a tela do terminal Windows
    
    printf("1. Inserir no inicio da lista encadeada simples\n");
    printf("2. Inserir no fim da lista encadeada simples\n");
    printf("3. Inserir no meio da lista encadeada simples\n");
    printf("4. Remover da lista encadeada simples\n");
    printf("5. Mostrar os elementos da lista encadeada simples\n");
    printf("6. Sair\n");
    printf("Digite sua escolha: ");

    scanf_s("%d", &op);
    while ((c = getchar()) != '\n' && c != EOF) {} //sempre limpe o buffer

    system("clear"); // Comando usado para limpar a tela do terminal linux
    return op;

}

void InserirInicio(int num)
{
    struct ElementoDaLista_Simples *NovoElemento;
    //Alocar o elemento na memória
    NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
    NovoElemento->dado = num;

    if (Head == NULL)
    {
        Head = NovoElemento;
        Head->prox = NULL;
    } 
    else
    {
        NovoElemento->prox = Head;
        Head = NovoElemento;
    }
    
}

void InserirFim(int num)
{
	struct ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}