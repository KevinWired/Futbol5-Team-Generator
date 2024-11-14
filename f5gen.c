/******************************************************************************

            date: Nov 14, 2024
            
            autor: Kevin Santillan
            
            file: f5gen.c
            
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_PLAYERS 10
#define TEAM_SIZE 5
#define NAME_LEN 32

typedef struct {
    unsigned int id;
    char username[NAME_LEN];
} player;

void swap(player *a, player *b) {
    player temp = *a;
    *a = *b;
    *b = temp;
}

int partition(player arr[], int low, int high) {
    unsigned int pivot = arr[high].id;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j].id <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(player arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void create_teams(player players[], player team1[], player team2[]) {
    for (unsigned int i = 0; i < TEAM_SIZE; i++) {
        team1[i] = players[i];
        team2[i] = players[i + TEAM_SIZE];
    }
}

void print_team(const char *team_name, player team[]) {
    printf("\n%s:\n", team_name);
    for (unsigned int i = 0; i < TEAM_SIZE; i++) {
        printf("Jugador %d: %s\n", i + 1, team[i].username);
    }
}

int main() {
    player players[TOTAL_PLAYERS];
    player team1[TEAM_SIZE], team2[TEAM_SIZE];

    srand(time(NULL));

    for (unsigned int i = 0; i < TOTAL_PLAYERS; i++) {
        printf("Ingrese el nombre del jugador %d: ", i + 1);
        fgets(players[i].username, NAME_LEN, stdin);
        trim_newline(players[i].username);

        players[i].id = rand() % 101;
    }

    quicksort(players, 0, TOTAL_PLAYERS - 1);
    create_teams(players, team1, team2);

    print_team("Equipo 1", team1);
    print_team("Equipo 2", team2);

    return 0;
}

