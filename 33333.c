#include <stdio.h>

#define MAX 20

void wypisz(double M[MAX][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%.1f ", M[i][j]);
        }
        printf("\n");
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB) {
    int i, j, n;
    double suma;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            suma = 0.0;
            for (n = 0; n < kA; n++) {
                suma = suma + A[i][n] * B[n][j];
            }
            C[i][j] = suma;
        }
    }
}

int main(void) {
    double A[MAX][MAX] = {
        {1.1, 2.2},
        {3.3, 4.4}
    };
    int wA = 2, kA = 2;

    double B[MAX][MAX] = {
        {5.5, 6.6, 7.7},
        {8.8, 9.9, 1.0}
    };
    int wB = 2, kB = 3;

    double C[MAX][MAX];

    printf("Tabela A:\n");
    wypisz(A, wA, kA);

    printf("\nTabela B:\n");
    wypisz(B, wB, kB);
    printf("\n");

    if (kA == wB) {
        printf("Mozna pomnozyc! Wynik (A * B):\n");
        pomnoz(A, B, C, wA, kA, kB);
        wypisz(C, wA, kB);
    } else {
        printf("Blad: Nie da sie tego pomnozyc, wymiary nie pasuja!\n");
    }

    return 0;
}