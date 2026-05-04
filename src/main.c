#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool backspaceCompare(char* s, char* t) {

    int i = 0;

    typedef struct no {
        char letra;
        struct no *prox;
    } No;

    typedef struct {
        No *topo;
    } Pilha;

    Pilha pilhaS;
    pilhaS.topo = NULL;

    Pilha pilhaT;
    pilhaT.topo = NULL;


    while (s[i] != '\0') {

        if (s[i] == '#') {
            if (pilhaS.topo != NULL) {
                No *remover = pilhaS.topo;
                pilhaS.topo = remover->prox;
                free(remover);
            }
        } else {
            No *novoS = (No*)malloc(sizeof(No));
            novoS->letra = s[i];
            novoS->prox = pilhaS.topo;
            pilhaS.topo = novoS;
        }

        i++;
    }


    i = 0;
    while (t[i] != '\0') {

        if (t[i] == '#') {
            if (pilhaT.topo != NULL) {
                No *remover = pilhaT.topo;
                pilhaT.topo = remover->prox;
                free(remover);
            }
        } else {
            No *novoT = (No*)malloc(sizeof(No));
            novoT->letra = t[i];
            novoT->prox = pilhaT.topo;
            pilhaT.topo = novoT;
        }

        i++;
    }

    
    No *pS = pilhaS.topo;
    No *pT = pilhaT.topo;

    while (pS != NULL && pT != NULL) {

        if (pS->letra != pT->letra) {
            return false;
        }

        pS = pS->prox;
        pT = pT->prox;
    }

    if (pS != NULL || pT != NULL) {
        return false;
    }

    return true;
}

int main() {

    char s1[] = "ab#c";
    char t1[] = "ad#c";


    if(backspaceCompare(s1, t1)==true) {
        printf("Iguais!");
    } else {
        printf("Diferentes!");
    }
   

    return 0;
}
