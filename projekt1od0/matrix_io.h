#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "matrix.h"

int wczytaj_macierz(char nazwa_pliku[], double M[][MAX], int *w, int *k);
int zapisz_macierz(char nazwa_pliku[], double M[][MAX], int w, int k);

#endif
