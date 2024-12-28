#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char equipa[15];
    char estadio[30];
    int capacidadeDoEstadio;
    int numerodesocios;
    float fundosdoclube;
    float despesasMensaisdeManutençaodoEstadio;
} dadosdasequipas;

typedef struct {
    char nome[30];
    int numero;
    float vencimento;
    int datadoIniciodoContrato[3];
    int anosdoContrato;
    char posicaojogador[15];
    int forca;
} jogadores;

//Função para escolher e mostrar a equipa
void mostrarEquipas(char treinador[NUM_EQUIPAS][15], dadosdasequipas equipasEDados[NUM_EQUIPAS], jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES], int equipaCount) {
    // Mostra a Lista das Equipas
    printf("Selecione uma equipa:\n");
    for (int i = 0; i < equipaCount; i++) {
        printf("%d. %s\n", i + 1, equipasEDados[i].equipa);
    }

    // Pede ao utilizador para escolher
    int escolha;
    printf("Digite o número da equipa que deseja selecionar: ");
    scanf("%d", &escolha);

    // Valida a seleção
    if (escolha < 1 || escolha > equipaCount) {
        printf("Seleção inválida.\n");
        return;
    }

    // Mostra a equipa que o utilizador escolheu
    int SelecionaIndice = escolha - 1; // Ajustar para indice baseado em zero
    printf("\nDetalhes da equipa selecionada:\n");
    printf("Treinador: %s\n", treinador[SelecionaIndice]);
    printf("Equipa: %s\n", equipasEDados[SelecionaIndice].equipa);
    printf("\nJogadores:\n");
    printf("%-30s %-10s %-15s\n", "Nome", "Número", "Posição"); // cabeçalho
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf("%-30s %-10d %-15s\n", jogadoresPorEquipa[SelecionaIndice][i].nome, jogadoresPorEquipa[SelecionaIndice][i].numero, jogadoresPorEquipa[SelecionaIndice][i].posicaojogador);
    }
}

//Funçoes utilizadas durante um jogo
int calcularPoderAtaque(jogadores equipa[NUM_JOGADORES])
{

    int poderAtaque = 0;
    for (int i = 0; i < NUM_JOGADORES; i++) {
        if (strcmp(equipa[i].posicaojogador, "Avancado") == 0 ||
            strcmp(equipa[i].posicaojogador, "Meio-campo") == 0) {
            poderAtaque += equipa[i].forca;
        }
    }
    return poderAtaque;
}

int calcularPoderDefesa(jogadores equipa[NUM_JOGADORES])
{
    int poderDefesa = 0;
    for (int i = 0; i < NUM_JOGADORES; i++) {
        if (strcmp(equipa[i].posicaojogador, "Defesa") == 0 ||
            strcmp(equipa[i].posicaojogador, "Guarda-redes") == 0) {
            poderDefesa += equipa[i].forca;
        }
    }
    return poderDefesa;
}

float gerarFatorAleatorio()
{
    srand(time(NULL));
    return (rand() % 1001) / 1000.0; // Gera um número entre 0.0 e 1.0
}

const char* determinarLocalPerdaBola()
{
    int random = rand() % 3;
    switch (random) {
    case 0:
        return "Defesa";
    case 1:
        return "Meio-campo";
    case 2:
        return "Ataque";
    default:
        return "Desconhecido";
    }
}

void gerirAtaque(jogadores equipa[NUM_JOGADORES], jogadores adversarios[NUM_JOGADORES], int tempoRestante)
{
    int poderAtaque = calcularPoderAtaque(equipa);
    int poderDefesaAdversaria = calcularPoderDefesa(adversarios);
    float fatorAleatorio = gerarFatorAleatorio();

    printf("Poder de Ataque: %d\n", poderAtaque);
    printf("Poder de Defesa do Adversário: %d\n", poderDefesaAdversaria);
    printf("Fator Aleatório: %.2f\n", fatorAleatorio);

    int resultado = (poderAtaque * fatorAleatorio) - poderDefesaAdversaria;

    if (resultado > 0) {
        printf("Ataque bem-sucedido! Gol marcado.\n");
    }
    else {
        const char* localPerda = determinarLocalPerdaBola();
        printf("Ataque falhou. Perda de bola na zona: %s.\n", localPerda);
    }

    printf("Tempo restante do jogo: %d minutos.\n", tempoRestante);
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    // cria treinadores para cada equipa
    char treinador[NUM_EQUIPAS][15];
    // cria dados para 18 equipas e jogadores para cada
    dadosdasequipas equipasEDados[NUM_EQUIPAS];
    jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES]; // 20 jogadores por equipa

    // Abre o ficheiro "Equipas.txt"
    FILE* equipas = fopen("Equipas.txt", "r");
    if (equipas == NULL) {
        printf("Não foi possível abrir o ficheiro.\n");
        return 1;
    }

    // Lê as linhas do arquivo e guarda no local correto
    int equipaCount = 0;
    char line[50];

    // Ler treinador e equipa
    while (equipaCount < NUM_EQUIPAS && fgets(line, sizeof(line), equipas) != NULL) {
        sscanf(line, "%[^\n]", treinador[equipaCount]);

        if (fgets(line, sizeof(line), equipas) != NULL) {
            sscanf(line, "%[^\n]", equipasEDados[equipaCount].equipa);
        }

        // Ler 20 jogadores
        for (int j = 0; j < NUM_JOGADORES; j++) {
            if (fgets(line, sizeof(line), equipas) != NULL) {
                sscanf(line, "%[^;];%d;%[^;];%d", jogadoresPorEquipa[equipaCount][j].nome, &jogadoresPorEquipa[equipaCount][j].numero, jogadoresPorEquipa[equipaCount][j].posicaojogador, &jogadoresPorEquipa[equipaCount][j].forca);
            }
        }
        equipaCount++;
    }
    fclose(equipas);

    // Chama a função para mostrar as equipas
    mostrarEquipas(treinador, equipasEDados, jogadoresPorEquipa, equipaCount);

    return 0;
}
