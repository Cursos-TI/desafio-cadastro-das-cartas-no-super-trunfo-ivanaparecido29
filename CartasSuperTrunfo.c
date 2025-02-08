#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 32 // 8 estados * 4 cidades cada

typedef struct {
    char codigo[4]; // Exemplo: "A01"
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrar_cidades(Cidade cidades[], int *contador) {
    if (*contador >= MAX_CIDADES) {
        printf("Limite de cidades atingido!\n");
        return;
    }
    
    printf("Digite o código da cidade (Ex: A01, B02): ");
    scanf("%s", cidades[*contador].codigo);

    printf("Digite a população da cidade: ");
    scanf("%d", &cidades[*contador].populacao);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &cidades[*contador].area);

    printf("Digite o PIB da cidade em bilhões de dólares: ");
    scanf("%f", &cidades[*contador].pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidades[*contador].pontos_turisticos);

    printf("Cidade cadastrada com sucesso!\n\n");
    
    (*contador)++;
}

void exibir_cidades(Cidade cidades[], int contador) {
    printf("\n📌 Lista de Cidades Cadastradas:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("Código: %s\n", cidades[i].codigo);
        printf("População: %d\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos Turísticos: %d\n", cidades[i].pontos_turisticos);
        printf("---------------------------------\n");
    }
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int contador = 0;
    int opcao;

    do {
        printf("\n🃏 Super Trunfo - Cadastro de Cidades 🃏\n");
        printf("1 - Cadastrar Cidade\n");
        printf("2 - Exibir Cidades Cadastradas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_cidades(cidades, &contador);
                break;
            case 2:
                exibir_cidades(cidades, contador);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
