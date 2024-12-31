#define _CRT_SECURE_NO_WARNINGS
#define NUM_EQUIPAS 18
#define NUM_JOGADORES 20
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
int mostrarEquipas(char treinador[NUM_EQUIPAS][15], dadosdasequipas equipasEDados[NUM_EQUIPAS], jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES], int equipaCount) {
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
        return -1; // Retorna -1 para indicar erro
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

    return SelecionaIndice; // Retorna o índice da equipa selecionada
}


// Função para atualizar os fundos
void atualizarFundos(int equipaIndex, dadosdasequipas equipasEDados[NUM_EQUIPAS], jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES]) {
    float totalVencimentos = 0.0;

    // Calcular o total de vencimentos dos jogadores
    for (int i = 0; i < NUM_JOGADORES; i++) {
        totalVencimentos += jogadoresPorEquipa[equipaIndex][i].vencimento;
    }

    // Adicionar as despesas mensais
    float despesasTotais = totalVencimentos + equipasEDados[equipaIndex].despesasMensaisdeManutençaodoEstadio;

    // Subtrair do fundo do clube
    if (equipasEDados[equipaIndex].fundosdoclube >= despesasTotais) {
        equipasEDados[equipaIndex].fundosdoclube -= despesasTotais;
        printf("Os fundos da equipa %s foram atualizados. Fundos restantes: %.2f\n", equipasEDados[equipaIndex].equipa, equipasEDados[equipaIndex].fundosdoclube);
    }
    else {
        printf("A equipa %s não tem fundos suficientes para cobrir as despesas. Fundos atuais: %.2f\n", equipasEDados[equipaIndex].equipa, equipasEDados[equipaIndex].fundosdoclube);

        // condição de fim de jogo
        if (equipasEDados[equipaIndex].fundosdoclube <= 0) {
            printf("Game Over! A equipa %s ficou sem fundos.\n", equipasEDados[equipaIndex].equipa);
            exit(0); // Sai do programa
        }
    }
}

void atualizarFundosPorResultado(int equipaIndex, dadosdasequipas equipasEDados[NUM_EQUIPAS], int resultado) {
    float ganho;

    // Definir os ganhos com base no resultado
    if (resultado == 1) { // Vitória
        ganho = 500000; // Ganho por vitória
        printf("A equipa %s ganhou! Recebeu %.2f.\n", equipasEDados[equipaIndex].equipa, ganho);
    }
    else if (resultado == 0) { // Empate
        ganho = 250000; // Ganho por empate
        printf("A equipa %s empatou! Recebeu %.2f.\n", equipasEDados[equipaIndex].equipa, ganho);
    }
    else { // Derrota
        ganho = 100000; // Ganho por derrota
        printf("A equipa %s perdeu! Recebeu %.2f.\n", equipasEDados[equipaIndex].equipa, ganho);
    }

    // Atualiza os fundos da equipa
    equipasEDados[equipaIndex].fundosdoclube += ganho;
}

// Função para gerar um calendário de jogos
int criarCalendario(dadosdasequipas equipasEDados[NUM_EQUIPAS], jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES], int equipaSelecionada) {
    int jogosGerados = 0;
    bool jogos[NUM_EQUIPAS][NUM_EQUIPAS] = { false }; // Matriz para verificar se um jogo já foi gerado

    printf("\nCalendário de Jogos:\n");
    while (jogosGerados < 9) {
        int equipa1 = rand() % NUM_EQUIPAS;
        int equipa2 = rand() % NUM_EQUIPAS;

        // Garantir que não joguem contra si mesmas e que o jogo não tenha sido gerado antes
        if (equipa1 != equipa2 && !jogos[equipa1][equipa2]) {
            jogos[equipa1][equipa2] = true; // Marcar o jogo como gerado
            jogos[equipa2][equipa1] = true; // Marcar o jogo como gerado na outra direção
            printf("Jogo %d: %s vs %s\n", jogosGerados + 1, equipasEDados[equipa1].equipa, equipasEDados[equipa2].equipa);
            jogosGerados++;
        }
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

int gerirAtaque(jogadores equipa[NUM_JOGADORES], jogadores adversarios[NUM_JOGADORES], int tempoRestante) {
    int poderAtaque = calcularPoderAtaque(equipa);
    int poderDefesaAdversaria = calcularPoderDefesa(adversarios);
    float fatorAleatorio = gerarFatorAleatorio();

    printf("Poder de Ataque: %d\n", poderAtaque);
    printf("Poder de Defesa do Adversário: %d\n", poderDefesaAdversaria);
    printf("Fator Aleatório: %.2f\n", fatorAleatorio);

    int resultado = (poderAtaque * fatorAleatorio) - poderDefesaAdversaria;

    if (resultado > 0) {
        printf("Ataque bem-sucedido! Golo marcado.\n");
        return 1; // Ataque bem-sucedido
    }
    else {
        const char* localPerda = determinarLocalPerdaBola();
        printf("Ataque falhou. Perda de bola na zona: %s.\n", localPerda);
        return 0; // Ataque falhou
    }

    printf("Tempo restante do jogo: %d minutos.\n", tempoRestante);
}

void simularJogo(dadosdasequipas equipasEDados[NUM_EQUIPAS], jogadores jogadoresPorEquipa[NUM_EQUIPAS][NUM_JOGADORES], int equipaSelecionada) {
    // Escolher um adversário aleatório que não seja a equipa selecionada
    int equipaAdversaria;
    do {
        equipaAdversaria = rand() % NUM_EQUIPAS;
    } while (equipaAdversaria == equipaSelecionada);

    printf("\nSimulando jogo entre %s e %s...\n", equipasEDados[equipaSelecionada].equipa, equipasEDados[equipaAdversaria].equipa);

    int golosEquipa = 0;
    int golosAdversario = 0;

    // Simulação de 90 minutos de jogo
    for (int tempo = 0; tempo <= 90; tempo += 15) { // Simula em intervalos de 15 minutos
        printf("\nMinuto: %d\n", tempo);
        int resultadoAtaque = gerirAtaque(jogadoresPorEquipa[equipaSelecionada], jogadoresPorEquipa[equipaAdversaria], 90 - tempo);

        // Se o ataque for bem-sucedido, incrementa os gols
        if (resultadoAtaque > 0) {
            golosEquipa++;
        }
        else {
            // Se o ataque falhar, o adversário pode ter uma chance de ataque
            int resultadoDefesa = gerirAtaque(jogadoresPorEquipa[equipaAdversaria], jogadoresPorEquipa[equipaSelecionada], 90 - tempo);
            if (resultadoDefesa > 0) {
                golosAdversario++;
            }
        }

        // Verifica se é minuto 45 para entrar em intervalo
        if (tempo == 45) {
            printf("\nIntervalo! Pressione Enter para continuar o jogo...\n");
            getchar(); // Espera pelo input do utilizador
            getchar(); // Captura o Enter
        }
    }

    printf("\nResultado Final: %s %d - %d %s\n", equipasEDados[equipaSelecionada].equipa, golosEquipa, golosAdversario, equipasEDados[equipaAdversaria].equipa);

    // Determinar vencedor e atualizar fundos
    int resultado;
    if (golosEquipa > golosAdversario) {
        printf("A equipa %s venceu!\n", equipasEDados[equipaSelecionada].equipa);
        resultado = 1; // Vitória
    }
    else if (golosEquipa < golosAdversario) {
        printf("A equipa %s venceu!\n", equipasEDados[equipaAdversaria].equipa);
        resultado = -1; // Derrota
    }
    else {
        printf("O jogo terminou em empate!\n");
        resultado = 0; // Empate
    }

    // Atualiza os fundos da equipa com base no resultado
    atualizarFundosPorResultado(equipaSelecionada, equipasEDados, resultado);
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

        equipasEDados[equipaCount].fundosdoclube = 100000000.0; // 100 milhões
        equipasEDados[equipaCount].despesasMensaisdeManutençaodoEstadio = 100000.0; // 100 mil

        // Ler 20 jogadores
        for (int j = 0; j < NUM_JOGADORES; j++) {
            if (fgets(line, sizeof(line), equipas) != NULL) {
                sscanf(line, "%[^;];%d;%[^;];%d", jogadoresPorEquipa[equipaCount][j].nome, &jogadoresPorEquipa[equipaCount][j].numero, jogadoresPorEquipa[equipaCount][j].posicaojogador, &jogadoresPorEquipa[equipaCount][j].forca);
                
                //gera um valor aleatorio para o vencimento de cada jogador
                jogadoresPorEquipa[equipaCount][j].vencimento = (rand() % (3000000 - 700000 + 1)) + 700000; // Um valor random entre 700000 e 3000000
            }
        }
        equipaCount++;
    }

    fclose(equipas);

    // Chama a função para mostrar as equipas e captura o índice da equipa selecionada
    int equipaSelecionada = mostrarEquipas(treinador, equipasEDados, jogadoresPorEquipa, equipaCount);


    char continuar;
    do {
        criarCalendario(equipasEDados, jogadoresPorEquipa, equipaSelecionada);

        // Simula o jogo da equipa
        printf("\nSimular o jogo da tua equipa %s? (s/n): ", equipasEDados[equipaSelecionada].equipa);
        scanf(" %c", &continuar);
        if (continuar == 's' || continuar == 'S') {
            simularJogo(equipasEDados, jogadoresPorEquipa, equipaSelecionada);
        }

        printf("\nDeseja gerar um novo calendário? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
