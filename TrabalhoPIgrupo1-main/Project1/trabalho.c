#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

#define PI 3.141592f
#define TRUE  1
#define FALSE  0

/*typedef struct
{
	char equipa[15];
	char estadio[30];
	int capacidadeDoEstadio;
	int numerodesocios;
	float fundosdoclube;
	float despesasMensaisdeManutençaodoEstadio;
	struct tabeladeResultados {
		int numerodeJogos;
		int numerodeVitorias;
		int numerodeEmpates;
		int numerodeDerrotas;
		int numerodeGolos;
		int numerodeGolosSofridos;
	};
	struct treinadoreJogadores {
		char treinador[20];
		struct jogadores {
			char nome[30];
			float vencimento;
			int datadoIniciodoContrato[3];
			int anosdoContrato;
			int forçadoJogador[4];
		};
	};
} dados;*/

/*int main(void) {

	setlocale(LC_ALL, "Portuguese");

	FILE* fd;

	dados equipasEDados[18]; 

	int x;

	fd = fopen("Vitória SC.txt", "r");
	if (fd == NULL)
	{
		printf("Não foi possível abrir o ficheiro \n");
	}
	else
	{
		while ((x = fgetc(fd)) != EOF)
		{
			printf("%c", x);
		}
		fclose(fd);
	}


	return 0;
}*/