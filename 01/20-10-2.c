#include <stdio.h>

#define MAX 10 

int main() {
    
    int wA = 2, kA = 3, wB = 2, kB = 3;
    int i, j;
    double A[MAX][MAX] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    double B[MAX][MAX] = {{7.0, 8.0, 9.0}, {10.0, 11.0, 12.0}};
    double C[MAX][MAX];

    if (wA < 1 || wA > MAX || kA < 1 || kA > MAX ||
        wB < 1 || wB > MAX || kB < 1 || kB > MAX) {
        printf("Blad: nieprawidlowe wymiary macierzy.\n");
        return 1;
    }
    
    if (wA != wB || kA != kB) {
        printf("Blad: macierze musza miec te same wymiary.\n");
        return 1;
    }

  
    printf("Suma macierzy A i B:\n");
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kA; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%8.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}