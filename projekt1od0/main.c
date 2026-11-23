#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "matrix_io.h"

int main(int argc, char *argv[]) {
    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];
    int wA, kA, wB, kB, wC = 0, kC = 0;
    char op[20];
    char plikA[100];
    char plikB[100];
    char plikOut[100];

    if (argc == 1) {
        /* Tryb menu (gdy program uruchomiony bez argumentow) */
        printf("Podaj operacje (add / sub / mul): ");
        if (scanf("%19s", op) != 1) {
            printf("Blad wczytywania operacji.\n");
            return 1;
        }
        printf("Podaj nazwe pliku z macierza A: ");
        if (scanf("%99s", plikA) != 1) {
            printf("Blad wczytywania nazwy pliku A.\n");
            return 1;
        }
        printf("Podaj nazwe pliku z macierza B: ");
        if (scanf("%99s", plikB) != 1) {
            printf("Blad wczytywania nazwy pliku B.\n");
            return 1;
        }
        printf("Podaj nazwe pliku wynikowego: ");
        if (scanf("%99s", plikOut) != 1) {
            printf("Blad wczytywania nazwy pliku wynikowego.\n");
            return 1;
        }
    } else if (argc == 5) {
        /* Tryb argumentow z linii polecen: ./kalkulator add a.txt b.txt wynik.txt */
        strcpy(op, argv[1]);
        strcpy(plikA, argv[2]);
        strcpy(plikB, argv[3]);
        strcpy(plikOut, argv[4]);
    } else {
        printf("Blad: zla liczba argumentow.\n");
        printf("Uzycie: %s [add|sub|mul plikA plikB plikWynik]\n", argv[0]);
        return 1;
    }

    if (strcmp(op, "add") != 0 && strcmp(op, "sub") != 0 && strcmp(op, "mul") != 0) {
        printf("Blad: nieznana operacja '%s'. Wpisz add, sub lub mul.\n", op);
        return 1;
    }

    if (!wczytaj_macierz(plikA, A, &wA, &kA)) {
        return 1;
    }

    if (!wczytaj_macierz(plikB, B, &wB, &kB)) {
        return 1;
    }

    if (strcmp(op, "add") == 0) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) {
            printf("Blad: macierze musza miec te same wymiary do dodawania.\n");
            return 1;
        }
        wC = wA;
        kC = kA;
        dodaj(A, B, C, wC, kC);
    } else if (strcmp(op, "sub") == 0) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) {
            printf("Blad: macierze musza miec te same wymiary do odejmowania.\n");
            return 1;
        }
        wC = wA;
        kC = kA;
        odejmij(A, B, C, wC, kC);
    } else if (strcmp(op, "mul") == 0) {
        if (!zgodne_do_mnozenia(kA, wB)) {
            printf("Blad: niezgodne wymiary do mnozenia (kolumny A != wiersze B).\n");
            return 1;
        }
        wC = wA;
        kC = kB;
        pomnoz(A, B, C, wA, kA, kB);
    }

    if (!zapisz_macierz(plikOut, C, wC, kC)) {
        return 1;
    }

    printf("Gotowe! Wynik zapisano w pliku %s.\n", plikOut);
    return 0;
}
