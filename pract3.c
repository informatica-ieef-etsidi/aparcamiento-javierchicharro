#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct plaza {
	int estado; //0-libre / 1-ocupada
	char matricula[8]; //formato NNNNLLL
	char tipo;
};

void main() {

	struct plaza plaza1 = { 0,'C' }, plaza2 = { 0,'M'};
	char opcion;
	char matricula[8], usuario[20]="Admin", password[20]="1234";
	char usuario2[20], passw2[20];
	int coche, moto, i, contador = 0, aux = 0;

	while (1) {

		for (i = 0; i < 3; i++) {
			printf("introduzca su usuario:\n");
			gets(usuario2);
			printf("introduzca su contraseña:\n");
			gets(passw2);

			if (strcmp(usuario2, usuario) == 0 && strcmp(passw2, password) == 0) {
				printf("log in correcto\n");
				aux = 1;
				break;
			}
			else if (strcmp(usuario2, usuario) == 1 || strcmp(passw2, password) == 1) {
				printf("log in incorrecto, el usuario"
					"o la contraseña son erroneos\n"
					"intentelo otra vez\n");
				contador++;

			}
		}

		if (contador == 3) {
			printf("ha introducido mal los datos 3 veces\n");
			break;
		}
	}
	while (aux == 1) {
		do {
			printf("Menu del aparcamiento:\n");
			printf("seleccione una de estas opciones:\n");

			printf("R-Reservar plaza\n");
			printf("A-Abandonar plaza\n");
			printf("E-Estado del aparcamiento\n");
			printf("B-Buscar un vehiculo por matricula\n");
			printf("S-Salir el programa\n");
			scanf(" %c", &opcion);
			getchar();//
			switch (opcion)
			{

			case 'R':
				if (plaza1.estado == 1 && plaza2.estado == 1)
					printf("todas las plazas estan ocupadas\n");
				else if (plaza1.estado == 0 && plaza2.estado == 1) {
					printf("plaza1 esta libre\n"
						"escriba C si es coche o M si moto\n");
					getchar();//
					scanf("%c", &plaza1.tipo);
					if (plaza1.tipo == 'C')
						coche = 1;
					else if (plaza1.tipo == 'M')
						moto = 1;
					else
						printf("tipo de vehiculo no admitido\n");
					printf("introduce tu matricula\n");
					//getchar();
					gets(plaza1.matricula);
					plaza1.estado = 1;
				}
				else if (plaza1.estado == 1 && plaza2.estado == 0) {
					printf("plaza2 esta libre\n"
						"escriba C si es coche o M si moto\n");
					getchar();//
					scanf("%c", &plaza2.tipo);
					if (plaza2.tipo == 'C')
						coche = 1;
					else if (plaza2.tipo == 'M')
						moto = 1;
					else
						printf("tipo de vehiculo no admitido\n");
					printf("introduce tu matricula\n");
					//getchar();
					gets(plaza2.matricula);
					plaza2.estado = 1;
				}
				else if (plaza1.estado == 0 && plaza2.estado == 0) {
					printf("ambas plazas estan libres\n"
						"se le asigna la plaza1\n"
						"escriba C si es coche o M si moto\n");
					getchar();//
					scanf("%c", &plaza1.tipo);
					if (plaza1.tipo == 'C')
						coche = 1;
					else if (plaza1.tipo == 'M')
						moto = 1;
					else
						printf("tipo de vehiculo no admitido\n");
					printf("introduce tu matricula\n");
					//getchar();
					gets(plaza1.matricula);
					plaza1.estado = 1;
				}

			case 'A':
				if (plaza1.estado == 0 && plaza2.estado == 0)
					printf("el aparcamiento esta vacio\n");
				else {
					printf("introduce tu matricula\n");
					getchar();//
					gets(matricula);
					if (strcmp(matricula, plaza1.matricula) == 1) {
						printf("Ha abandonado la plaza1\n");
						plaza1.estado = 0;
					}
					else if (strcmp(matricula, plaza2.matricula) == 1) {
						printf("Ha abandonado la plaza2\n");
						plaza2.estado = 0;
					}
					else
						printf("tu matricula no coincide con ninguna del aparcamiento\n");
					break;
				}

			case 'E':
				printf("este es el estado del aparcamiento\n");

				if (plaza1.estado == 1) {
					if (coche == 1)
						printf("Plaza1-ocupada-coche-matricula: %s\n", plaza1.matricula);
					else if (moto == 1)
						printf("Plaza1-ocupada-moto-matricula: %s\n", plaza1.matricula);
				}
				if (plaza2.estado == 1) {
					if (coche == 1)
						printf("Plaza2-ocupada-coche-matricula: %s\n", plaza2.matricula);
					else if (moto == 1)
						printf("Plaza2-ocupada-moto-matricula: %s\n", plaza2.matricula);
				}

				else {
					printf("Plaza1-Libre\n");
					printf("plaza2-Libre\n");
				}
				break;

			case 'B':
				printf("introduzca el numero de matricula\n");
				getchar();//
				gets(matricula);
				if (strcmp(matricula, plaza1.matricula) == 1)
					printf("su vehiculo esta aparcado en la plaza1:\n");
				else if (strcmp(matricula, plaza2.matricula) == 1)
					printf("su vehiculo esta aparcado en la plaza2:\n");
				else
					printf("su matricula no coincide\n");
				break;
			case 'S':
				printf("gracias por su visita\n");
				aux = 0;
				break;

			default:
				printf("opcion no valida\n");
			}

		} while (opcion != 'S');
	}
}