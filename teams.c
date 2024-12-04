/******************************************************************************

            date: Nov 14, 2024

            Last update: Dec 3, 2024

            Autor: Kevin Santillan

            File: teams.c

*******************************************************************************/

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>
#include <time.h>
#include "team_generator.h"


int main() {
    line_spacing();
	printf("Team Generator\n");
	line_spacing();
	uint total;
	printf("Ingresa la cantidad TOTAL de jugadores:\n");
	if (scanf("%u", &total) != 1) {
         printf("Error: La entrada no es un número. Abortando programa.\n");
         exit(EXIT_FAILURE);
    }
	getchar();
	while(total % 2 != 0) {
		printf("Tamano de los equipos invalido. Volve a ingresarlo: \n");
		scanf("%u", &total);
		getchar();
	}

	printf("Ingresa el nombre de cada uno de los jugadores\n");
	player array[total];
	for (uint i = 0; i < total; i++) {
		printf("Nombre del jugador #%d: ", i + 1);
		if (fgets(array[i].username, NAME_MAX_SIZE, stdin)) {
			trim_newline(array[i].username);
			to_uppercase(array[i].username);
			array[i].id = pseudo_random_number_generator();
		} else {
			fprintf(stderr, "Error al leer el nombre del jugador %d\n", i + 1);
			return 1;
		}
	}

	// Ordenar el arreglo segC:n el id aleatorio.
	sort(array, total);
	player team_1[total / 2], team_2[total / 2];

	// Dividir jugadores en dos equipos.
	for (uint k = 0; k < total; k++) {
		if (k < total / 2) {
			team_1[k] = array[k];
		} else {
			team_2[k - total / 2] = array[k];
		}
	}

	// Imprimir los equipos.
    line_spacing();
	printf("<TEAM 1>\n");
	for (uint i = 0; i < total / 2; i++) {
		printf("-%s.\n", team_1[i].username);
	}

	printf("\n<TEAM 2>\n");
	for (uint i = 0; i < total / 2; i++) {
		printf("-%s.\n", team_2[i].username);
	}

	return 0;
}
