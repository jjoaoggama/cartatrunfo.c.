#include <stdio.h>

#define MAX_NOME 100
#define MAX_CODIGO 5

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado;
    char codigo[MAX_CODIGO];
    char nomeCidade[MAX_NOME];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Função para calcular o Super Poder
float calcularSuperPoder(struct Carta c) {
    return (float)c.populacao +
           c.area +
           (c.pib * 1e9f) + // PIB em reais
           (float)c.pontosTuristicos +
           c.pibPerCapita +
           (1.0f / c.densidadePopulacional); // inverso da densidade
}

int main() {
    struct Carta carta1, carta2;

    // Entrada dos dados da primeira carta
    printf("Digite os dados da Carta 1:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    getchar(); // limpar buffer
    fgets(carta1.nomeCidade, MAX_NOME, stdin);

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Entrada dos dados da segunda carta
    printf("\nDigite os dados da Carta 2:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    getchar(); // limpar buffer
    fgets(carta2.nomeCidade, MAX_NOME, stdin);

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9f) / carta1.populacao;
    carta1.superPoder = calcularSuperPoder(carta1);

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9f) / carta2.populacao;
    carta2.superPoder = calcularSuperPoder(carta2);

    // Comparações
    int popVence = carta1.populacao > carta2.populacao;
    int areaVence = carta1.area > carta2.area;
    int pibVence = carta1.pib > carta2.pib;
    int pontosVence = carta1.pontosTuristicos > carta2.pontosTuristicos;
    int densidadeVence = carta1.densidadePopulacional < carta2.densidadePopulacional; // menor vence
    int pibCapitaVence = carta1.pibPerCapita > carta2.pibPerCapita;
    int poderVence = carta1.superPoder > carta2.superPoder;

    // Impressão das comparações
    printf("\n--- Comparação de Cartas ---\n");

    printf("População: Carta 1 venceu (%d)\n", popVence);
    printf("Área: Carta 1 venceu (%d)\n", areaVence);
    printf("PIB: Carta 1 venceu (%d)\n", pibVence);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosVence);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidadeVence);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibCapitaVence);
    printf("Super Poder: Carta 1 venceu (%d)\n", poderVence);

    // Impressão das cartas com detalhes
    printf("\n--- Detalhes das Cartas ---\n");

    for (int i = 1; i <= 2; i++) {
        struct Carta c = (i == 1) ? carta1 : carta2;
        printf("\nCarta %d:\n", i);
        printf("Estado: %c\n", c.estado);
        printf("Código: %s\n", c.codigo);
        printf("Nome da Cidade: %s", c.nomeCidade);
        printf("População: %lu\n", c.populacao);
        printf("Área: %.2f km²\n", c.area);
        printf("PIB: %.2f bilhões de reais\n", c.pib);
        printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
        printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
        printf("Super Poder: %.2f\n", c.superPoder);
    }

    return 0;
}
