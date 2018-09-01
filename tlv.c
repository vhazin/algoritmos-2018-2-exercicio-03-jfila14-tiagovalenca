#include <stdio.h>
#include <stdlib.h>

struct Elemento{
  struct Elemento *proximo;
  int data;
};

struct Lista{
  struct Elemento *dados;
  struct Elemento *ultimo;
  int tamanho;
};

struct Lista* criarLista(){
  struct Lista *lista;
  lista = malloc(sizeof(struct Lista));
  if(lista != NULL){
    lista->tamanho = 0;
    lista->dados = NULL;
    lista->ultimo = NULL;
  }
  return(lista);
}

int adicionar(struct Lista *lista, int *info){
  struct Elemento *novo;
  novo = malloc(sizeof(struct Elemento));
  lista->tamanho = lista->tamanho + 1;
  novo->data = *info;

  if(lista->dados == NULL){
    lista->dados = novo;
    lista->ultimo = novo;
  }else{
    lista->ultimo->proximo = novo;
    lista->ultimo = novo;
  }
  return(lista->tamanho);
}

void remover(struct Lista *lista, int *value){
    struct Elemento *auxiliar = lista->dados;
    struct Elemento *anterior = NULL;

    for(auxiliar = lista->dados; auxiliar != NULL; auxiliar = auxiliar->proximo){
      if(auxiliar->data == *value){
        if (anterior == NULL){
          lista->dados = auxiliar->proximo;
          free(auxiliar);
          lista->tamanho = lista->tamanho - 1;
          break;
        } else{
          anterior->proximo = auxiliar->proximo;
          free(auxiliar);
          lista->tamanho = lista->tamanho -1;
          break;          
        }
      }
      anterior = auxiliar;
    }
}

void print_list(struct Lista *lista){
    struct Elemento *temp = lista->dados;

    for(temp = lista->dados; temp != NULL; temp = temp->proximo){
        printf("%i ", temp->data);
    }
}

int main(void) {
  int m, n, pessoa;
  struct Lista *lista;
  lista = criarLista();

  scanf("%i", &m);

  while(m!=0){
    scanf("%d", &pessoa);
    adicionar(lista, &pessoa);
    m--;
  }

  scanf("%i", &n);

  while(n != 0){
    scanf("%d", &pessoa);
    remover(lista, &pessoa);
    n--;
  }

  print_list(lista);
  
  return 0;
}
