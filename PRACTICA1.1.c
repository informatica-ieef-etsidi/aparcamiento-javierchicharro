#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	while (1) {
		char opcion;
		int plaza1 = 1, plaza2 = 1;
		char matricula1[7], matricula2[7], matA[7];
		
		printf("Menu del aparcamiento:\n");
		printf("seleccione una de estas opciones:\n");
		printf("R-Reservar plaza\n");
		printf("A-Abandonar plaza\n");
		printf("E-Estado del aparcamiento\n");

		scanf("%c", &opcion);
		switch (opcion)
		{
		case'R':
			if (plaza1 == 1) {
				plaza1 = 0;
				printf("plaza libre\n");
				printf("introduzca el numero de matricula\n ");
				getchar();
				scanf("%s", matricula1);
				printf("su plaza ha sido ocupada\n");
				}
			else if (plaza2 == 1 && plaza1 != 1) {
				plaza2 = 0;
				printf("plaza libre\n");
				printf("introduzca el numero de matricula\n ");
				getchar();
				scanf("%s", matricula2);
				printf("su plaza ha sido ocupada\n");
				}
			else
				printf("las plazas estan ocupadas\n");
			break;

		case'A':
			printf("introduzca su numero de matricula\n");
			scanf("%s", matA);
			if (matA == matricula1) {
				plaza1 = 1;
			}
			else if (matA == matricula2) {
				plaza2 = 1;
			}
			else
				printf("su matricula no coincide"
					"registrese en nuestro aparcamiento\n");
			break;
		case'E':
			printf("este es el estado del aparcamiento\n");
			if (plaza1 == 0) {
				printf("Plaza1-ocupada-matricula: %s\n", matricula1);
			}
			if (plaza2 == 0) {
				printf("Plaza2-ocupada-matricula: %s\n", matricula2);
			}
			else {
				printf("Plaza1-Libre\n");
				printf("plaza2-Libre\n");
			}
			break;
		default:
			printf("opcion no valida\n");
			break;


		}
		printf("para acabar el programa pulse Ctrl c\n");
		
	}
}