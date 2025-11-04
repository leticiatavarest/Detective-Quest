#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa cada cômodo (nó da árvore binária)
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Função que cria dinamicamente uma nova sala com nome
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*) malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Função que permite o jogador explorar a mansão
void explorarSalas(Sala* salaAtual) {
    char escolha;

    while (salaAtual != NULL) {
        printf("\nVocê está na sala: %s\n", salaAtual->nome);

        // Verifica se chegou ao fim (nó-folha)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("Você chegou ao fim da exploração. Não há mais caminhos.\n");
            return;
        }

        printf("\nEscolha um caminho:\n");
        if (salaAtual->esquerda != NULL) printf(" (e) Ir para a esquerda → %s\n", salaAtual->esquerda->nome);
        if (salaAtual->direita != NULL) printf(" (d) Ir para a direita → %s\n", salaAtual->direita->nome);
        printf(" (s) Sair do jogo\n");
        printf(">> ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && salaAtual->esquerda != NULL) {
            salaAtual = salaAtual->esquerda;
        } 
        else if (escolha == 'd' && salaAtual->direita != NULL) {
            salaAtual = salaAtual->direita;
        } 
        else if (escolha == 's') {
            printf("\nVocê decidiu encerrar a exploração. Até a próxima, detetive!\n");
            return;
        } 
        else {
            printf("\nCaminho inválido. Tente novamente.\n");
        }
    }
}

// Função principal - monta o mapa da mansão e inicia o jogo
int main() {
    // Criação manual das salas (nós da árvore)
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("Jardim");
    Sala* despensa = criarSala("Despensa");

    // Conectando as salas (estrutura da árvore binária)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->direita = despensa;

    // Inicia a exploração
    printf("======================================\n");
    printf("      Bem-vindo ao Detective Quest!\n");
    printf("  Explore a mansão e descubra segredos.\n");
    printf("======================================\n");

    explorarSalas(hall);

    // Libera a memória alocada
    free(hall);
    free(salaEstar);
    free(cozinha);
    free(biblioteca);
    free(jardim);
    free(despensa);

    return 0;
}
