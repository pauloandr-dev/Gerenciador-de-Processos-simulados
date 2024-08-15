#include <stdio.h>
#include <stdlib.h>
#include "processos.h"

void menuPrincipal() {
    int escolha;
    int quantum;

    do {
        printf("\n----- Gerenciador de Processos -----\n");
        printf("1. Exibir fila de processos\n");
        printf("2. Executar com Round-Robin\n");
        printf("3. Executar com FIFO\n");
        printf("4. Calcular métricas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                exibirFila();
                break;
            case 2:
                printf("Digite o quantum para o Round-Robin: ");
                scanf("%d", &quantum);
                executarRoundRobin(quantum);
                break;
            case 3:
                executarFIFO();
                break;
            case 4:
                calcularMetricas();
                break;
            case 5:
                liberarFila();
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 5);
}

int main() {
    inicializarProcessos();
    menuPrincipal();
    return 0;
}
