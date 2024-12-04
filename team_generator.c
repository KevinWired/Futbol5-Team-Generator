#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>
#include <time.h>
#include "team_generator.h"


uint pseudo_random_number_generator() {
    srand(time(NULL)); // Seed.
    return rand() % LIMIT_RANGE;
}

void line_spacing() {
    printf("\n\n");
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
