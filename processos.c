#include <stdio.h>
#include <stdlib.h>
#include "processos.h"

Node *inicio = NULL;
Node *fim = NULL;
int totalProcessos = 0;

void adicionarProcesso(int id, int tempoExecucao, int prioridade) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->processo.id = id;
    novoNode->processo.tempoExecucao = tempoExecucao;
    novoNode->processo.prioridade = prioridade;
    novoNode->processo.tempoRestante = tempoExecucao;
    novoNode->proximo = NULL;

    if (inicio == NULL) {
        inicio = novoNode;
        fim = novoNode;
    } else {
        fim->proximo = novoNode;
        fim = novoNode;
    }
    totalProcessos++;
}

void exibirFila() {
    if (inicio == NULL) {
        printf("Fila de processos vazia.\n");
        return;
    }

    Node *atual = inicio;
    printf("Fila de Processos:\n");
    while (atual != NULL) {
        printf("ID: %d, Tempo de Execução: %d, Prioridade: %d\n", atual->processo.id, atual->processo.tempoExecucao, atual->processo.prioridade);
        atual = atual->proximo;
    }
}

void executarRoundRobin(int quantum) {
    Node *atual = inicio;
    while (totalProcessos > 0) {
        if (atual->processo.tempoRestante > 0) {
            printf("Executando processo ID: %d\n", atual->processo.id);
            if (atual->processo.tempoRestante > quantum) {
                atual->processo.tempoRestante -= quantum;
            } else {
                printf("Processo ID: %d finalizado.\n", atual->processo.id);
                atual->processo.tempoRestante = 0;
                totalProcessos--;
            }
        }
        atual = (atual->proximo != NULL) ? atual->proximo : inicio;
    }
}

void executarFIFO() {
    Node *atual = inicio;
    while (atual != NULL) {
        printf("Executando processo ID: %d\n", atual->processo.id);
        atual->processo.tempoRestante = 0;
        printf("Processo ID: %d finalizado.\n", atual->processo.id);
        atual = atual->proximo;
    }
    totalProcessos = 0;
}

void calcularMetricas() {
    printf("Cálculo de métricas ainda não implementado.\n");
}

void inicializarProcessos() {
    adicionarProcesso(1, 10, 1);
    adicionarProcesso(2, 5, 2);
    adicionarProcesso(3, 8, 1);
    adicionarProcesso(4, 12, 3);
}

void liberarFila() {
    Node *atual = inicio;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    inicio = NULL;
    fim = NULL;
}

