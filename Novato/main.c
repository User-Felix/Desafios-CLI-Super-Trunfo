#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

#define MAX_CARTAS 10
#define MAX_ESTADO 3
#define MAX_NOME 50

int main() {
    //Permite que a aplicação trabalhe com acentos
    setlocale(LC_ALL,"portuguese");
    // Variáveis para armazenar os dados das cartas
    char estado[MAX_CARTAS][MAX_ESTADO];
    char codigo_carta[MAX_CARTAS][5];
    char nome_cidade[MAX_CARTAS][MAX_NOME];
    long populacao[MAX_CARTAS];
    double area[MAX_CARTAS];
    double pib[MAX_CARTAS];
    int pontos_turisticos[MAX_CARTAS];
    double densidade_populacional[MAX_CARTAS];
    double pib_per_capita[MAX_CARTAS];
    
    int quantidade_cartas, i;
    
    printf("ATENÇÃO!!! \nNão use pontos ou virgulas em números!\n [EX: 1234152]\n");

    // Solicita a quantidade de cartas a serem cadastradas
    printf("Quantas cartas deseja cadastrar (máximo %d)? ", MAX_CARTAS);
    scanf("%d", &quantidade_cartas);
    fflush(stdin);

    // Valida a quantidade de cartas
    if (quantidade_cartas < 1 || quantidade_cartas > MAX_CARTAS) {
        printf("Quantidade inválida. O programa será encerrado.\n");
        return 1;
    }

    // Loop para entrada de dados das cartas
    for (i = 0; i < quantidade_cartas; i++) {
        printf("\nCadastrando a carta %d:\n", i + 1);

        // Entrada do estado
        printf("Digite o estado (Ex: SP, RJ): ");
        scanf(" %2s", estado[i]);
        fflush(stdin);

        // Entrada do código da carta
        printf("Digite o código da carta (Ex: A01, B02): ");
        scanf(" %4s", codigo_carta[i]);
        fflush(stdin);

        // Entrada do nome da cidade
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", nome_cidade[i]);
        fflush(stdin);

        // Entrada da população
        printf("Digite a população da cidade: ");
        scanf("%ld", &populacao[i]);
        fflush(stdin);

        // Entrada da área
        printf("Digite a área da cidade (em km²): ");
        scanf("%lf", &area[i]);
        fflush(stdin);

        // Entrada do PIB
        printf("Digite o PIB da cidade (em bilhões): ");
        scanf("%lf", &pib[i]);
        fflush(stdin);

        // Entrada do número de pontos turísticos
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &pontos_turisticos[i]);
        fflush(stdin);

        // Calcula a densidade populacional e o PIB per capita
        densidade_populacional[i] = populacao[i] / area[i];
        pib_per_capita[i] = (pib[i] * 1000000000) / populacao[i];
    }

    // Exibe os dados das cartas cadastradas
    printf("\n___ Dados das Cartas Cadastradas ___\n");
    for (i = 0; i < quantidade_cartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %s\n", estado[i]);
        printf("Código da Carta: %s\n", codigo_carta[i]);
        printf("Nome da Cidade: %s\n", nome_cidade[i]);
        printf("População: %ld\n", populacao[i]);
        printf("Área: %.2f km²\n", area[i]);
        printf("Densidade Populacional: %.2f pessoas/km²\n", densidade_populacional[i]);
        printf("PIB: %.2f bilhões de reais\n", pib[i]);
        printf("PIB per Capita: %.2f reais\n", pib_per_capita[i]);
        printf("Número de Pontos Turísticos: %d\n", pontos_turisticos[i]);
        printf("_____________________________________\n");
    }
    
    return 0;
}