#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>
#include "team_generator.h"

// Return true if player 'x' goes before player 'y' in a sorted array of players.
bool goes_before(player x, player y);

void swap(player a[], uint i, uint j);

// Sort the array of players.
void sort(player a[], uint length);

#endif // _SORT_T
