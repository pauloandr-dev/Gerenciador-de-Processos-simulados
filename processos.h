#ifndef PROCESSOS_H
#define PROCESSOS_H

typedef struct {
    int id;
    int tempoExecucao;
    int prioridade;
    int tempoRestante;
} Processo;

typedef struct Node {
    Processo processo;
    struct Node *proximo;
} Node;

void adicionarProcesso(int id, int tempoExecucao, int prioridade);
void exibirFila();
void executarRoundRobin(int quantum);
void executarFIFO();
void calcularMetricas();
void inicializarProcessos();
void liberarFila();

#endif
