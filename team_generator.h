#ifndef TEAM_GENERATOR
#define TEAM_GENERATOR

#define NAME_MAX_SIZE 32
#define LIMIT_RANGE 101 

typedef unsigned int uint;

typedef struct player_t {
    uint id;
    char username[NAME_MAX_SIZE];
} player;

// Genera un numero psudo-aleatorio dentro del rango [0 100].
uint pseudo_random_number_generator();

void line_spacing();

void trim_newline(char *str);

void to_uppercase(char *str);

#endif // TEAM_GENERATOR
