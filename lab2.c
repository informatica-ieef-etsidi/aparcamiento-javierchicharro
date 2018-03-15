#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main(){

		char opcion, opc1;
		int plaza1 = 1, plaza2 = 1, plaza3 = 1, plaza4 = 1;
	
		char matricula1[8], matricula2[8], mat3[8],mat4[8], matA[8], matB[8];

		do {
			printf("Menu del aparcamiento:\n");
			printf("seleccione una de estas opciones:\n");

			printf("R-Reservar plaza\n");
			printf("A-Abandonar plaza\n");
			printf("E-Estado del aparcamiento\n");
			printf("B-Buscar un vehiculo por matricula\n");
			printf("S-Salir el programa\n");
			scanf(" %c", &opcion);
			getchar();
			switch (opcion)
			{
			
			case 'R':
				printf("introduzca el tipo de vehiculo\n");
				printf("C-coche\n");
				printf("M-moto\n");
				scanf(" %c", &opc1);
				getchar();
				switch (opc1) {
				case 'C':
					if (plaza1 == 1) {
						plaza1 = 0;
						printf("plaza libre\n");
						printf("introduzca el numero de matricula\n ");
						scanf("%s", matricula1);
						printf("su plaza ha sido ocupada\n");
						break;
					}
					if (plaza2 == 1 && plaza1 != 1) {
						plaza2 = 0;
						printf("plaza libre\n");
						printf("introduzca el numero de matricula\n ");
						scanf("%s", matricula2);
						printf("su plaza ha sido ocupada\n");
						break;
					}
					else
						printf("las plazas estan ocupadas\n");
					printf("\n");
					break;
				case 'M':
					if (plaza3 == 1) {
						plaza3 = 0;
						printf("plaza libre\n");
						printf("introduzca el numero de matricula\n ");
						scanf("%s", mat3);
						printf("su plaza ha sido ocupada\n");
						break;
					}
					if (plaza4 == 1 && plaza3 != 1) {
						plaza4 = 0;
						printf("plaza libre\n");
						printf("introduzca el numero de matricula\n ");
						scanf("%s", mat4);
						printf("su plaza ha sido ocupada\n");
						break;
					}
					else
						printf("las plazas estan ocupadas\n");
					printf("\n");
					break;
				default:
					printf("opcion no valida\n");
					printf("\n");
				
				}
				
				break;

			case 'A': 
				printf("introduzca su numero de matricula\n");
				scanf("%s", matA);
				if (matA == matricula1)
					plaza1 = 1;
				else if (matA == matricula2)
					plaza2 = 1;
				else if (matA == mat3)
					plaza3 = 1;
				else if (matA == mat4)
					plaza4 = 1;
				else
					printf("su matricula no coincide"
						"registrese en nuestro aparcamiento\n");
				printf("\n");
				break;
			
			case 'E':
				printf("este es el estado del aparcamiento\n");
				printf("plazas de coche:\n");
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
				printf("plazas de moto:\n");
				if (plaza3 == 0) {
					printf("Plaza3 -ocupada-matricula: %s\n", mat3);
				}
				if (plaza4 == 0) {
					printf("Plaza4-ocupada-matricula: %s\n", mat4);
				}
				else {
					printf("Plaza3-Libre\n");
					printf("plaza4-Libre\n");
				}
				printf("\n");
				break;
			case 'B':
				printf("introduzca el numero de matricula\n");
				scanf("%s", matB);
				if (matB == matricula1)
					printf("su coche esta aparcado en la plaza1:\n");
				else if (matB == matricula2)
					printf("su coche esta aparcado en la plaza2:\n");
				else if (matB == mat3)
					printf("su moto esta aparcado en la plaza3:\n");
				else if (matB == mat4)
					printf("su moto esta aparcado en la plaza4:\n");
				else
					printf("su matricula no coincide\n");
				break;
			case 'S':
				printf("gracias por su visita\n");
				break;

			default:
				printf("opcion no valida\n");
			}
		} while (opcion != 'S');
	
}