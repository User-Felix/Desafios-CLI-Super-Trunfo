#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    char nome1[MAX_NOME], nome2[MAX_NOME];
    long populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    int opcao;
    int vitorias1 = 0, vitorias2 = 0;
    
    printf("ATENÇÃO!!! \nNão use pontos ou virgulas em números!\n [EX: 1234152]\n");


    // Cadastro das Cartas
    printf("Cadastro da carta 1:\n");
    printf("Digite o nome do país: ");
    scanf(" %s", nome1);
    printf("Digite a população: ");
    scanf("%ld", &populacao1);
    printf("Digite a área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\nCadastro da carta 2:\n");
    printf("Digite o nome do país: ");
    scanf(" %s", nome2);
    printf("Digite a população: ");
    scanf("%ld", &populacao2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    do {
        // Menu interativo
        printf("\nEscolha o atributo para comparação:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos turísticos\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Comparar População
                if (populacao1 > populacao2) {
                    printf("%s vence com maior população (%ld).\n", nome1, populacao1);
                    vitorias1++;
                } else if (populacao1 < populacao2) {
                    printf("%s vence com maior população (%ld).\n", nome2, populacao2);
                    vitorias2++;
                } else {
                    printf("Empate! Ambas as cidades têm a mesma população (%ld).\n", populacao1);
                }
                break;
            case 2: // Comparar Área
                if (area1 > area2) {
                    printf("%s vence com maior área (%.2f km²).\n", nome1, area1);
                    vitorias1++;
                } else if (area1 < area2) {
                    printf("%s vence com maior área (%.2f km²).\n", nome2, area2);
                    vitorias2++;
                } else {
                    printf("Empate! Ambas as cidades têm a mesma área (%.2f km²).\n", area1);
                }
                break;
            case 3: // Comparar PIB
                if (pib1 > pib2) {
                    printf("%s vence com maior PIB (%.2f bilhões).\n", nome1, pib1);
                    vitorias1++;
                } else if (pib1 < pib2) {
                    printf("%s vence com maior PIB (%.2f bilhões).\n", nome2, pib2);
                    vitorias2++;
                } else {
                    printf("Empate! Ambas as cidades têm o mesmo PIB (%.2f bilhões).\n", pib1);
                }
                break;
            case 4: // Comparar Pontos Turísticos
                if (pontos_turisticos1 > pontos_turisticos2) {
                    printf("%s vence com mais pontos turísticos (%d).\n", nome1, pontos_turisticos1);
                    vitorias1++;
                } else if (pontos_turisticos1 < pontos_turisticos2) {
                    printf("%s vence com mais pontos turísticos (%d).\n", nome2, pontos_turisticos2);
                    vitorias2++;
                } else {
                    printf("Empate! Ambas as cidades têm o mesmo número de pontos turísticos (%d).\n", pontos_turisticos1);
                }
                break;
            case 5: // Sair
                printf("Saindo do sistema. Até mais!\n");
                if (vitorias1 > vitorias2) {
                    printf("O país vencedor é: %s com %d vitórias!\n", nome1, vitorias1);
                } else if (vitorias2 > vitorias1) {
                    printf("O país vencedor é: %s com %d vitórias!\n", nome2, vitorias2);
                } else {
                    printf("Não houve um vencedor. Ambos os países empataram com %d vitórias cada.\n", vitorias1);
                }
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
