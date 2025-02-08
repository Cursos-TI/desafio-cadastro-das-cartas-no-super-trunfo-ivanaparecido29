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
        printf("⚠️ Limite de cidades atingido!\n");
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

    printf("✅ Cidade cadastrada com sucesso!\n\n");
    
    (*contador)++;
}

void exibir_cidades(Cidade cidades[], int contador) {
    if (contador == 0) {
        printf("\n⚠️ Nenhuma cidade cadastrada ainda.\n");
        return;
    }

    printf("\n📌 Lista de Cidades Cadastradas:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("Código: %s\n", cidades[i].codigo);
        printf("População: %d\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões\n", cidades[i].pib);
        printf("Pontos Turísticos: %d\n", cidades[i].pontos_turisticos);
        
        // Cálculos (Nível Aventureiro)
        float densidade = cidades[i].populacao / cidades[i].area;
        float pib_per_capita = cidades[i].pib / cidades[i].populacao;
        
        printf("Densidade Populacional: %.2f hab/km²\n", densidade);
        printf("PIB per Capita: %.2f bilhões/hab\n", pib_per_capita);
        printf("---------------------------------\n");
    }
}

void comparar_cartas(Cidade c1, Cidade c2) {
    printf("\n🔹 Comparação entre %s e %s\n", c1.codigo, c2.codigo);
    printf("---------------------------------\n");

    // Critérios de vitória
    printf("População: %s\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("Área: %s\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("PIB: %s\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("Pontos Turísticos: %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    
    // Cálculo de propriedades derivadas
    float densidade1 = c1.populacao / c1.area;
    float densidade2 = c2.populacao / c2.area;
    float pib_per_capita1 = c1.pib / c1.populacao;
    float pib_per_capita2 = c2.pib / c2.populacao;

    // Critério especial: menor densidade vence
    printf("Densidade Populacional: %s (menor vence)\n", (densidade1 < densidade2) ? c1.codigo : c2.codigo);
    printf("PIB per Capita: %s\n", (pib_per_capita1 > pib_per_capita2) ? c1.codigo : c2.codigo);

    // Super Poder: soma de todas as propriedades
    float super_poder1 = c1.populacao + c1.area + c1.pib + c1.pontos_turisticos;
    float super_poder2 = c2.populacao + c2.area + c2.pib + c2.pontos_turisticos;

    printf("\n🏆 Super Poder: %s\n", (super_poder1 > super_poder2) ? c1.codigo : c2.codigo);
    printf("---------------------------------\n");
}

int buscar_cidade(Cidade cidades[], int contador, char codigo[]) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(cidades[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int contador = 0;
    int opcao;

    do {
        printf("\n🃏 Super Trunfo - Cadastro de Cidades 🃏\n");
        printf("1 - Cadastrar Cidade\n");
        printf("2 - Exibir Cidades Cadastradas\n");
        printf("3 - Comparar Cartas\n");
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
            case 3: {
                if (contador < 2) {
                    printf("\n⚠️ Cadastre pelo menos duas cidades para comparar!\n");
                    break;
                }

                char codigo1[4], codigo2[4];
                printf("Digite o código da primeira cidade: ");
                scanf("%s", codigo1);
                printf("Digite o código da segunda cidade: ");
                scanf("%s", codigo2);

                int idx1 = buscar_cidade(cidades, contador, codigo1);
                int idx2 = buscar_cidade(cidades, contador, codigo2);

                if (idx1 == -1 || idx2 == -1) {
                    printf("\n⚠️ Código(s) inválido(s)!\n");
                } else {
                    comparar_cartas(cidades[idx1], cidades[idx2]);
                }
                break;
            }
            case 0:
                printf("👋 Saindo do sistema...\n");
                break;
            default:
                printf("⚠️ Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}