#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    int valor;
    char nome[30];
    struct arvore *esq;
    struct arvore *dir;
};

void insercao(struct arvore **raiz, int elemento){
    if(*raiz == NULL ){
        struct arvore *aux = (struct arvore *) malloc(sizeof(struct arvore));
        aux->valor = elemento;
        aux->dir = aux->esq = NULL;
        *raiz = aux;
        printf("Elemento %d foi inserido com sucesso.\n", elemento);
        return;
    }

    else if(elemento < (*raiz)->valor){
        insercao(&(*raiz)->esq, elemento);
        return;
    }

    else if(elemento > (*raiz)->valor){
        insercao(&(*raiz)->dir, elemento);
        return;
    }
    printf("Elemento %d ja existe na arvore.\n", elemento);

}

struct arvore *DoisFilhos(struct arvore *raiz){
    if(raiz==NULL)
        return NULL;
    else if(raiz->esq == NULL)
        return raiz;
    else
        return DoisFilhos(raiz->esq);
}

void remocao(struct arvore **raiz, int elemento){

    if(elemento < (*raiz)->valor)
        remocao(&(*raiz)->esq, elemento);

    else if(elemento > (*raiz)->valor)
        remocao(&(*raiz)->dir, elemento);

    else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){
        struct arvore *aux = NULL;
        aux = DoisFilhos((*raiz)->dir);
        (*raiz)->valor = aux->valor;
        remocao(&(*raiz)->dir, (*raiz)->valor);
    }
    else{
        struct arvore *aux = (*raiz);
        if((*raiz)->esq == NULL)
            (*raiz) = (*raiz)->dir;
        else{
            *raiz = (*raiz)->esq;
        }
        free(aux);
        printf("Elemento %d removido com sucesso.\n", elemento);
    }

}

int busca(struct arvore *raiz, int elemento ){
    int x;
    if(raiz==NULL)
        return -1;
    x = raiz->valor;

    if( x == elemento ) return x;
    else if(elemento < x) return busca(raiz->esq, elemento);
    else return busca(raiz->dir, elemento);

}

void imprime_preordem(struct arvore *raiz){
    if(raiz==NULL)
        return;
    printf("%d ",raiz->valor);
    imprime_preordem(raiz->esq);
    imprime_preordem(raiz->dir);
}

void imprime_posordem(struct arvore *raiz){
    if(raiz==NULL)
        return;
    imprime_posordem(raiz->esq);
    imprime_posordem(raiz->dir);
    printf("%d ", raiz->valor);
}

void imprime_emordem(struct arvore *raiz){
    if(raiz==NULL)
        return;

    imprime_emordem(raiz->esq);
    printf("%d ",raiz->valor);
    imprime_emordem(raiz->dir);
}

void imprime_labelledbracketing(struct arvore *raiz){

    if(raiz==NULL){
        printf("[] ");
        return;
    }
    printf("[%d ", raiz->valor);
    imprime_labelledbracketing(raiz->esq);
    imprime_labelledbracketing(raiz->dir);
    printf("]");
}

void inserir_membro(struct arvore **raiz, char string1[], char string2[], char string3[], int valor ){
    if(*raiz == NULL ){
        struct arvore *aux = (struct arvore *) malloc(sizeof(struct arvore));
        strcpy(aux->nome, string1);
        aux->dir = aux->esq = NULL;
        aux->valor = valor;
        *raiz = aux;
        printf("Elemento %s foi inserido com sucesso \n", string1);
        if((string2 == NULL) || (string3 == NULL) ){return;}
    }

    if(strcmp(string1, (*raiz)->nome) == 0){
        valor+=1;
        inserir_membro(&(*raiz)->esq, string2, NULL, NULL, valor);
        inserir_membro(&(*raiz)->dir, string3, NULL, NULL, valor);
    }
    else{
        valor+=1;
        if((*raiz)->esq != NULL){
            inserir_membro(&(*raiz)->esq, string1, string2, string3, valor);
            }
        if((*raiz)->dir != NULL){
            inserir_membro(&(*raiz)->dir, string1, string2, string3, valor);
        }
    }
}


void printGivenLevel(struct arvore* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%s ", root->nome);

  else if (level > 1)
  {
    printGivenLevel(root->esq, level-1);
    printGivenLevel(root->dir, level-1);
  }

}

void printLevelOrder(struct arvore* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}


int height(struct arvore* node)
{
   if (node==NULL)
       return 0;
   else
   {
     int lheight = height(node->esq);
     int rheight = height(node->dir);

     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}

void antepassados(struct arvore*pessoa, char *son){		//impressao dos antepassados de certo alguem. Basta passar a localizacao dessa pessoa, e entao pedir para dar imprimir todos os nós abaixo deste
	if(pessoa!=NULL){
		if(strcmp(pessoa->nome, son)!=0){
			printf("%s\n", pessoa->nome);
		}
		antepassados(pessoa->esq, son);
		antepassados(pessoa->dir, son);
	}
}

void imprime_grau(struct arvore *raiz, int flag){
    if(raiz==NULL) return;
    else{
        if(flag==0) printf("%s ");
        printf("\n");

        if(raiz->esq!=NULL){
            printf("%s ", raiz->esq->nome);
        }
        if(raiz->dir!=NULL){
            printf("%s ", raiz->dir->nome);
        }
        else return;
    }
         imprime_grau(raiz->esq, 1);
         imprime_grau(raiz->dir, 1);


}

void familia_labelledbracketing(struct arvore *raiz){

    if(raiz==NULL){
        //printf("[] ");
        return;
    }
    printf("[%s ", raiz->nome);
    familia_labelledbracketing(raiz->esq);
    familia_labelledbracketing(raiz->dir);
    printf("]");
}

int main(){
    int n, opc, opc2, i, j;
    char string1[30], string2[30], string3[30];
    struct arvore *raiz = NULL;
    struct arvore *familia = NULL;

    do{
        printf("1- Operacoes Basicas em Arvores\n");
        printf("2- Arvore Genealogica\n");
        printf("0- Sair\n");
        scanf("%d", &opc); getchar();
            switch(opc){
                case 1:
                    system("cls");
                    do{
                        printf("> OPERACOES BASICAS EM ARVORES \n\n");
                        printf("1- Insercao\n");
                        printf("2- Remocao\n");
                        printf("3- Busca\n");
                        printf("4- Impressao\n");
                        printf("0- Sair\n");
                        scanf("%d", &opc2); getchar();
                            switch(opc2){
                                case 1:
                                    system("cls");
                                    printf(">> INSERCAO \n");
                                    printf("Quantidade de Elementos: ");
                                    scanf("%d", &n); getchar();
                                    for(i=0; i<n; i++){
                                        printf("Elemento %d: ", i+1);
                                        scanf("%d", &j); getchar();
                                        insercao(&raiz, j);
                                    }
                                    printf("\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;

                                case 2:
                                    system("cls");
                                    printf(">> REMOCAO \n");
                                    printf("Valor a ser Removido: ");
                                    scanf("%d", &n); getchar();
                                    if(busca(raiz, n) == -1) printf("Elemento nao existe!\n");
                                    else remocao(&raiz, n);
                                    printf("\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;

                                case 3:
                                    system("cls");
                                    printf(">> BUSCA \n");
                                    printf("Valor procurado: ");
                                    scanf("%d", &n); getchar();
                                    if(busca(raiz, n) == -1) printf("Elemento nao existe!\n");
                                    else printf("Elemento encontrado\n");
                                    printf("\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;

                                case 4:
                                    system("cls");
                                    printf(">> IMPRESSAO\n");
                                    printf("\nImpressao em Ordem: \n");
                                    imprime_emordem(raiz);
                                    printf("\n\nImpressao Pre Ordem: \n");
                                    imprime_preordem(raiz);
                                    printf("\n\nImpressao Pos Ordem: \n");
                                    imprime_posordem(raiz);
                                    printf("\n\nImpressao em Labelled Bracketing: \n");
                                    imprime_labelledbracketing(raiz);
                                    printf("\n\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;

                                case 0:
                                    system("cls");
                                break;

                                default:
                                    printf("Opcao invalida!!!\n");
                                    printf("\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;
                            }
                    }while(opc2!=0);
                    break;

                case 2:
                    system("cls");
                    do{
                        printf("> ARVORE GENEALOGICA \n\n");
                        printf("1- Insercao\n");
                        printf("2- Imprimir\n");
                        printf("0- Sair\n");
                        scanf("%d", &opc2); getchar();
                            switch(opc2){
                                case 1:
                                    system("cls");
                                    printf(">> INSERCAO \n");
                                    printf("Quantidade de Elementos: ");
                                    scanf("%d", &n); getchar();
                                    for(i=0; i<n; i++){
                                        printf("(filho, pai, mae): ");
                                        scanf("%s %s %s", string1, string2, string3); getchar();
                                        inserir_membro(&familia, string1, string2, string3,0);
                                    }
                                    printf("\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;

                                case 2:
                                    system("cls");
                                    printf(">> IMPRIMIR \n");
                                    printf("\n>>> Impressao em Labelled Bracketing\n");
                                    familia_labelledbracketing(familia);
                                    printf("\n\n>>> Impressao da familia por geracao\n");
                                    printLevelOrder(familia);
                                    printf("\n\nENTER para continuar..."); getchar();
                                    system("cls");
                                break;


                            }
                    }while(opc2!=0);

                break;

                case 0:
                    printf("Programa Finalizado");
                break;

                default:
                    printf("Opcao invalida!!!\n");
                    printf("\nENTER para continuar..."); getchar();
                    system("cls");
                break;
            }
    }while(opc!=0);

return 0;
}
