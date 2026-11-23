#include "matrix.h"

int wymiary_poprawne(int w, int k) {
    return w >= 1 && w <= MAX &&
           k >= 1 && k <= MAX;
}

int zgodne_do_sumy(int wA, int kA, int wB, int kB) {
    return wA == wB && kA == kB;
}

int zgodne_do_mnozenia(int kA, int wB) {
    return kA == wB;
}

void dodaj(double A[][MAX], double B[][MAX],
           double C[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void odejmij(double A[][MAX], double B[][MAX],
             double C[][MAX], int w, int k) {
    int i, j;

    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void pomnoz(double A[][MAX], double B[][MAX],
            double C[][MAX], int wA, int kA, int kB) {
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
