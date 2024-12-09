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

int main(void) {

	setlocale(LC_ALL, "Portuguese");

	FILE* fd;
	int escolha;

	printf("Escolha uma equipa inicial:\n\n1-Sporting CP\t2-Sl Benfica\t3-FC Porto\t\t4-SC Braga\t\t5-Santa Clara\t6-Vitória SC\n\n\
7-Casa Pia AC\t8-FC Famalicão\t9-Gil Vicente FC\t10-Moreirense FC\t11-Rio Ave FC\t12-SC Farense\n\n\
13-FC Arouca\t14-Boavista FC\t15-Est. Amadora\t\t16-Estoril Praia\t17-CD Nacional\t18-Avs Futenol SAD\nOpção: "); scanf("%d", &escolha);


	switch (escolha)
	{
	case 1:
		fd = fopen("Sporting.txt", "r");
		int sport;
		//Retorna o ponteiro NULL, em falha
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			//Lê um carácter por vez do ficheiro, parando em EOF, que indica o fim do ficheiro
			while ((sport = fgetc(fd)) != EOF)
			{
				printf("%c", sport);
			}
			fclose(fd);
		}
		break;

	case 2:
		fd = fopen("Benfica.txt", "r");
		int benf;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((benf = fgetc(fd)) != EOF)
			{
				printf("%c", benf);
			}
			fclose(fd);
		}
		break;

	case 3:
		fd = fopen("FC Porto.txt", "r");
		int port;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((port = fgetc(fd)) != EOF)
			{
				printf("%c", port);
			}
			fclose(fd);
		}
		break;

	case 4:
		fd = fopen("SC Braga.txt", "r");
		int brag;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((brag = fgetc(fd)) != EOF)
			{
				printf("%c", brag);
			}
			fclose(fd);
		}
		break;

	case 5:
		fd = fopen("Santa Clara.txt", "r");
		int sant;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((sant = fgetc(fd)) != EOF)
			{
				printf("%c", sant);
			}
			fclose(fd);
		}
		break;

	case 6:
		fd = fopen("Vitória SC.txt", "r");
		int vito;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((vito = fgetc(fd)) != EOF)
			{
				printf("%c", vito);
			}
			fclose(fd);
		}
		break;

	case 7:
		fd = fopen("Casa Pia AC.txt", "r");
		int caspia;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((caspia = fgetc(fd)) != EOF)
			{
				printf("%c", caspia);
			}
			fclose(fd);
		}
		break;

	case 8:
		fd = fopen("FC Famalicão.txt", "r");
		int famal;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((famal = fgetc(fd)) != EOF)
			{
				printf("%c", famal);
			}
			fclose(fd);
		}
		break;

	case 9:
		fd = fopen("Gil Vicente FC.txt", "r");
		int gilv;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((gilv = fgetc(fd)) != EOF)
			{
				printf("%c", gilv);
			}
			fclose(fd);
		}
		break;

	case 10:
		fd = fopen("Moreirense FC.txt", "r");
		int morei;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((morei = fgetc(fd)) != EOF)
			{
				printf("%c", morei);
			}
			fclose(fd);
		}
		break;

	case 11:
		fd = fopen("Rio Ave FC.txt", "r");
		int rioave;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((rioave = fgetc(fd)) != EOF)
			{
				printf("%c", rioave);
			}
			fclose(fd);
		}
		break;

	case 12:
		fd = fopen("SC Farense.txt", "r");
		int faren;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((faren = fgetc(fd)) != EOF)
			{
				printf("%c", faren);
			}
			fclose(fd);
		}
		break;

	case 13:
		fd = fopen("Arouca.txt", "r");
		int arouc;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((arouc = fgetc(fd)) != EOF)
			{
				printf("%c", arouc);
			}
			fclose(fd);
		}
		break;

	case 14:
		fd = fopen("Boavista.txt", "r");
		int boavi;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((boavi = fgetc(fd)) != EOF)
			{
				printf("%c", boavi);
			}
			fclose(fd);
		}
		break;

	case 15:
		fd = fopen("Est. Amadora.txt", "r");
		int amador;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((amador = fgetc(fd)) != EOF)
			{
				printf("%c", amador);
			}
			fclose(fd);
		}
		break;

	case 16:
		fd = fopen("Estoril Praia.txt", "r");
		int estprai;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((estprai = fgetc(fd)) != EOF)
			{
				printf("%c", estprai);
			}
			fclose(fd);
		}
		break;

	case 17:
		fd = fopen("Nacional.txt", "r");
		int nacio;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((nacio = fgetc(fd)) != EOF)
			{
				printf("%c", nacio);
			}
			fclose(fd);
		}
		break;

	case 18:
		fd = fopen("AFS.txt", "r");
		int afs;
		if (fd == NULL)
		{
			printf("Não foi possível abrir o ficheiro \n");
		}
		else
		{
			while ((afs = fgetc(fd)) != EOF)
			{
				printf("%c", afs);
			}
			fclose(fd);
		}
		break;
	}

	return 0;
}
