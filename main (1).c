#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int valor;
  struct no *proximo;
  struct no *anterior;
}No;

typedef struct{
  No *inicio;
  No *fim;
  int tam;
}Lista;

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

void inserir_inicio(Lista *lista,int num){
  No *novo = malloc(sizeof(No));

  if(novo){
    novo->valor=num;
    novo->proximo=lista->inicio;
    novo->anterior=lista->fim;
    lista->inicio=novo;
    
    if(lista->fim==NULL)
      lista->fim=novo;
    
    lista->inicio->anterior=lista->fim;
    lista->fim->proximo=lista->inicio;
    lista->tam++;
  }else
    printf("\nERRO ao alocar memoria\n");
}

void imprimir(Lista lista){
  No *no = lista.inicio;
  printf("\nTamanho da lista: %d \nLista: ",lista.tam);
  if(no){
    do{
      printf("%d ",no->valor);
      no = no->proximo;
    }while(no != lista.inicio);
    
  }
}

int main(void) {
  int opcao, valor;
  Lista lista;

  criar_lista(&lista);
  
  do{
    //system("clear");
    printf("\n[1] Inserir no inicio\n[2] Imprimir\n[0] Sair\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        printf("\nValor: ");
        scanf("%d",&valor);
        inserir_inicio(&lista,valor);
      break;
      case 2:
        imprimir(lista);
      break;
    }
  }while(opcao!=0);
}