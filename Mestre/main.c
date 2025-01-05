#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CIDADES 10

int main() {
    // Variáveis para cadastro das cidades
    int quantidade;
    char nomes[MAX_CIDADES][MAX_NOME];
    long populacoes[MAX_CIDADES];
    float areas[MAX_CIDADES];
    float pib[MAX_CIDADES];
    int pontos_turisticos[MAX_CIDADES];
    
    printf("ATENÇÃO!!! \nNão use pontos ou vírgulas em números!\n [EX: 1234152]\n");

    // Cadastro das cidades
    printf("Digite a quantidade de cidades a serem cadastradas (max %d): ", MAX_CIDADES);
    scanf("%d", &quantidade);
    if (quantidade > MAX_CIDADES) {
        printf("Quantidade excede o máximo permitido (%d).\n", MAX_CIDADES);
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro da cidade %d:\n", i + 1);
        printf("Nome da cidade: ");
        scanf("%s", nomes[i]);
        printf("População: ");
        scanf("%ld", &populacoes[i]);
        printf("Área (km²): ");
        scanf("%f", &areas[i]);
        printf("PIB: ");
        scanf("%f", &pib[i]);
        printf("Pontos Turísticos: ");
        scanf("%d", &pontos_turisticos[i]);
    }

    int opcao, indice1, indice2;
    do {
        // Menu interativo
        printf("\nEscolha uma opção:\n");
        printf("1. Comparar cidades\n");
        printf("2. Listar cidades\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Exibir lista de cidades
                printf("\nCidades cadastradas:\n");
                for (int i = 0; i < quantidade; i++) {
                    printf("%d. %s\n", i + 1, nomes[i]);
                }

                // Selecionar cidades pelo índice
                printf("Digite o número da primeira cidade: ");
                scanf("%d", &indice1);
                printf("Digite o número da segunda cidade: ");
                scanf("%d", &indice2);

                // Ajustar índices para arrays (de 1-based para 0-based)
                indice1--;
                indice2--;

                // Verificar se os índices são válidos
                if (indice1 < 0 || indice1 >= quantidade || indice2 < 0 || indice2 >= quantidade) {
                    printf("Índice inválido! Tente novamente.\n");
                    break;
                }

                // Comparar as cidades selecionadas
                printf("\nComparação entre %s e %s:\n", nomes[indice1], nomes[indice2]);
                printf("População: %s tem %ld habitantes e %s tem %ld habitantes.\n",
                       nomes[indice1], populacoes[indice1], nomes[indice2], populacoes[indice2]);
                printf("Área: %s tem %.2f km² e %s tem %.2f km².\n",
                       nomes[indice1], areas[indice1], nomes[indice2], areas[indice2]);
                printf("PIB: %s tem um PIB de %.2f e %s tem um PIB de %.2f.\n",
                       nomes[indice1], pib[indice1], nomes[indice2], pib[indice2]);
                printf("Pontos Turísticos: %s tem %d pontos turísticos e %s tem %d pontos turísticos.\n",
                       nomes[indice1], pontos_turisticos[indice1], nomes[indice2], pontos_turisticos[indice2]);
                break;

            case 2:
                // Listar as cidades cadastradas
                printf("\nCidades cadastradas:\n");
                for (int i = 0; i < quantidade; i++) {
                    printf("%d. %s\n", i + 1, nomes[i]);
                }
                break;

            case 3:
                printf("Saindo do sistema. Até mais!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
