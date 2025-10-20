#include <stdio.h>
#include <string.h>

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para exibir o menu de atributos
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir != 1) printf("1. População\n");
    if (excluir != 2) printf("2. Área\n");
    if (excluir != 3) printf("3. PIB\n");
    if (excluir != 4) printf("4. Número de pontos turísticos\n");
    if (excluir != 5) printf("5. Densidade demográfica (vence o menor valor)\n");
    printf("0. Sair\n");
    printf("-------------------------------------------\n");
    printf("Digite sua opção: ");
}

int main() {
    // Dados das cartas
    char nome1[30] = "Brasil";
    char nome2[30] = "Portugual";

    int populacao1 = 374000000, populacao2 = 289000000;
    float area1 = 9815767.0, area2 = 657975.0;
    float pib1 = 3.1, pib2 = 5.7; // em trilhões de dólares
    int pontosTuristicos1 = 35, pontosTuristicos2 = 56;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int escolha1 = -1, escolha2 = -1;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;
    float soma1 = 0, soma2 = 0;
    char jogarNovamente;

    printf("==========================================\n");
    printf("     🌍 SUPER TRUNFO DE PAISES - FINAL\n");
    printf("==========================================\n\n");

    do {
        printf("Cartas em jogo:\n");
        printf("Carta 1: %s\n", nome1);
        printf("Carta 2: %s\n\n", nome2);

        // Escolha do primeiro atributo
        exibirMenu(-1);
        scanf("%d", &escolha1);
        limparBuffer();

        if (escolha1 == 0) {
            printf("Saindo do jogo... Até logo!\n");
            return 0;
        }

        // Escolha do segundo atributo, com exclusão do primeiro
        printf("\n Agora escolha o segundo atributo (diferente do primeiro):\n");
        exibirMenu(escolha1);
        scanf("%d", &escolha2);
        limparBuffer();

        if (escolha2 == 0) {
            printf("Saindo do jogo... Até logo!\n");
            return 0;
        }

        if (escolha1 == escolha2) {
            printf("⚠️ Você escolheu o mesmo atributo duas vezes! Jogue novamente.\n");
            continue;
        }

        printf("\n-------------------------------------------\n");
        printf("Comparando %s e %s\n", nome1, nome2);
        printf("-------------------------------------------\n");

        // Primeiro atributo
        switch (escolha1) {
            case 1:
                printf("Atributo 1: População\n");
                valor1_carta1 = populacao1;
                valor1_carta2 = populacao2;
                break;
            case 2:
                printf("Atributo 1: Área\n");
                valor1_carta1 = area1;
                valor1_carta2 = area2;
                break;
            case 3:
                printf("Atributo 1: PIB\n");
                valor1_carta1 = pib1;
                valor1_carta2 = pib2;
                break;
            case 4:
                printf("Atributo 1: Pontos Turísticos\n");
                valor1_carta1 = pontosTuristicos1;
                valor1_carta2 = pontosTuristicos2;
                break;
            case 5:
                printf("Atributo 1: Densidade Demográfica (vence o menor)\n");
                valor1_carta1 = densidade1;
                valor1_carta2 = densidade2;
                break;
            default:
                printf("Opção inválida!\n");
                continue;
        }

        // Segundo atributo
        switch (escolha2) {
            case 1:
                printf("Atributo 2: População\n");
                valor2_carta1 = populacao1;
                valor2_carta2 = populacao2;
                break;
            case 2:
                printf("Atributo 2: Área\n");
                valor2_carta1 = area1;
                valor2_carta2 = area2;
                break;
            case 3:
                printf("Atributo 2: PIB\n");
                valor2_carta1 = pib1;
                valor2_carta2 = pib2;
                break;
            case 4:
                printf("Atributo 2: Pontos Turísticos\n");
                valor2_carta1 = pontosTuristicos1;
                valor2_carta2 = pontosTuristicos2;
                break;
            case 5:
                printf("Atributo 2: Densidade Demográfica (vence o menor)\n");
                valor2_carta1 = densidade1;
                valor2_carta2 = densidade2;
                break;
            default:
                printf("Opção inválida!\n");
                continue;
        }

        // Exibir valores comparados
        printf("\nValores do atributo 1:\n");
        printf("%s: %.2f | %s: %.2f\n", nome1, valor1_carta1, nome2, valor1_carta2);
        printf("\nValores do atributo 2:\n");
        printf("%s: %.2f | %s: %.2f\n", nome1, valor2_carta1, nome2, valor2_carta2);

        // Aplicar regras de comparação (considerando densidade invertida)
        float resultado1 = (escolha1 == 5)
            ? (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta1 > valor1_carta2 ? -1 : 0))
            : (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta1 < valor1_carta2 ? -1 : 0));

        float resultado2 = (escolha2 == 5)
            ? (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta1 > valor2_carta2 ? -1 : 0))
            : (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta1 < valor2_carta2 ? -1 : 0));

        // Soma total (atributo1 + atributo2)
        soma1 = valor1_carta1 + valor2_carta1;
        soma2 = valor1_carta2 + valor2_carta2;

        printf("\n-------------------------------------------\n");
        printf("SOMA DOS ATRIBUTOS:\n");
        printf("%s: %.2f\n", nome1, soma1);
        printf("%s: %.2f\n", nome2, soma2);
        printf("-------------------------------------------\n");

        // Determinar vencedor final (usando operador ternário)
        (soma1 > soma2) ? printf("🏆 %s venceu a rodada!\n", nome1)
        : (soma2 > soma1) ? printf("🏆 %s venceu a rodada!\n", nome2)
        : printf("🤝 Empate!\n");

        printf("-------------------------------------------\n");
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
        printf("\n");

    } while (jogarNovamente == 'S' || jogarNovamente == 's');

    printf("Obrigado por jogar o Super Trunfo Final! 🌎\n");
    return 0;
}
