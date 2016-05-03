#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define wait(msg) printf("%s\nPressione algo para continuar...\n", msg);getch();

typedef struct TNo{
    int info;
    struct TNo *prox;
}No;

typedef struct TFila{
    No *inicio, *fim;
    int quantidade;
}Fila;

Fila *inicia_fila(){
    Fila *tmp=(Fila *)malloc(sizeof(Fila));
    if (tmp != NULL){
        tmp->quantidade = 0;
        tmp->inicio = NULL;
        tmp->fim = NULL;
    }
}

No *inicia_no(int info){
    No *tmp = (No *)malloc(sizeof(No));
    if (tmp != NULL){
        tmp->info = info;
        tmp->prox = NULL;
    }
    return tmp;
}

void push(Fila *fila, No *no){
    if (fila->inicio == NULL)
        fila->inicio = no;
    if (fila->fim != NULL)
        fila->fim->prox = no;
    fila->fim = no;
    fila->quantidade += 1;
}

No *pop(Fila *fila){
    No *no = NULL;
    if (fila->fim != NULL){
        no = fila->inicio;
        fila->inicio = no->prox;
        no->prox = NULL;
        if (fila->inicio == NULL)
            fila->fim = NULL;
        fila->quantidade -= 1;
    }
    return no;
}

void retira_imprime(Fila *f){
    No *tmp;
    printf("Total de itens na fila: %d\n", f->quantidade);
    while((tmp = pop(f))!=NULL){
        printf(" - %d\n", tmp->info);
        free(tmp);
    }
}

void clear(){
    int i=0;
    while(i++<50) printf("\n");
}

char menu(){
    char op=' ';
    clear();
    printf("\n\nMENU\n");
    printf("   [0] - Sair\n");
    printf("   [1] - Inserir na Fila(push)\n");
    printf("   [2] - Retirar da Fila (pop)\n");
    printf("   [3] - Tamanho da Fila\n");
    printf("   [4] - Retirar Tudo e Imprimir\n");
    printf("Sua escolha: ");
    while(strchr("01234", op)==NULL)
        op = getch();
    printf("%c\n", op);
    return op;
}

int main(){
    Fila *fila;
    No *n;
    int valor;
    char op = ' ';
    fila = inicia_fila();
    while(op!='0'){
        op = menu();
        if (op == '1'){
            printf("\n\nValor a inserir:");
            scanf("%d", &valor);
            push(fila, inicia_no(valor));
            wait("Valor inserido!");
        }else if (op == '2'){
            n = pop(fila);
            if (n == NULL)
                printf("\n\nNada para retirar da fila!\n");
            else
                printf("\n\nValor retirado da fila: %d\n", n->info);
            wait("");
        }else if (op == '3'){
            printf("\n\nTamanho da fila: %d\n", fila->quantidade);
            wait("");
        }else if (op == '4'){
            retira_imprime(fila);
            wait("");
        }
    }

    return 0;
}
