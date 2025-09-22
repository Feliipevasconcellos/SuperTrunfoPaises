#include <stdio.h>

//Estrutura para criação das cartas~
struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    unsigned int pontosTuristicos;
    float densidadePopulacao, pibPerCapita, superPoder;
};

struct CartaSuperTrunfo carta1, carta2;  // Definição da quantidade de cartas

// Função para preencher as cartas evitando repetições
void preencherCarta(struct CartaSuperTrunfo *carta, const char *nomeCarta) {
    printf("\n===== Preenchendo %s =====\n", nomeCarta);

    printf("Escolha uma letra entre 'A' e 'H' para representar um dos oito estados: ");
    scanf(" %c", &carta->estado);

    printf("Escolha um número de 1 a 4 para o código da carta: ");
    int numeroCodigo;
    scanf(" %d", &numeroCodigo);
    sprintf(carta->codigo, "%c%02d", carta->estado, numeroCodigo);

    getchar();  // Limpa o buffer antes de ler a próxima string
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Área da Cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite a Quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacao = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita;

    printf(" %s registrada com sucesso!\n", nomeCarta);
}

int main(void) {
    // Mensagem de boas-vindas
    printf("****  Bem-vindo ao Super Trunfo - Cidades!  ****\n");
    printf("** Nesta versão, jogaremos com duas cartas. **\n");
    printf("** Escolha um atributo para comparar e veja quem vence! **\n\n");

    // Preenchendo as cartas
    preencherCarta(&carta1, "Carta 1");
    preencherCarta(&carta2, "Carta 2");

    

    return 0;
}