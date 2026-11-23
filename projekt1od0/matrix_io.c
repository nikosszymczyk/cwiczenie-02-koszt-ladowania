#include <stdio.h>
#include "matrix_io.h"

int wczytaj_macierz(char nazwa_pliku[], double M[][MAX], int *w, int *k) {
    FILE *plik;
    int i, j;
    double nadmiar;

    plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        printf("Blad: nie mozna otworzyc pliku %s.\n", nazwa_pliku);
        return 0;
    }

    if (fscanf(plik, "%d %d", w, k) != 2) {
        printf("Blad: nieprawidlowe wymiary w pliku %s.\n", nazwa_pliku);
        fclose(plik);
        return 0;
    }

    if (!wymiary_poprawne(*w, *k)) {
        printf("Blad: wymiary macierzy w %s musza byc od 1 do %d.\n", nazwa_pliku, MAX);
        fclose(plik);
        return 0;
    }

    for (i = 0; i < *w; i++) {
        for (j = 0; j < *k; j++) {
            if (fscanf(plik, "%lf", &M[i][j]) != 1) {
                printf("Blad: brakujace lub bledne dane w pliku %s.\n", nazwa_pliku);
                fclose(plik);
                return 0;
            }
        }
    }

    if (fscanf(plik, "%lf", &nadmiar) == 1) {
        printf("Blad: za duzo elementow w pliku %s.\n", nazwa_pliku);
        fclose(plik);
        return 0;
    }

    fclose(plik);
    return 1;
}

int zapisz_macierz(char nazwa_pliku[], double M[][MAX], int w, int k) {
    FILE *plik;
    int i, j;

    plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        printf("Blad: nie mozna zapisac do pliku %s.\n", nazwa_pliku);
        return 0;
    }

    fprintf(plik, "%d %d\n", w, k);

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            fprintf(plik, "%.2f", M[i][j]);
            if (j < k - 1) {
                fprintf(plik, " ");
            }
        }
        fprintf(plik, "\n");
    }

    fclose(plik);
    return 1;
}
