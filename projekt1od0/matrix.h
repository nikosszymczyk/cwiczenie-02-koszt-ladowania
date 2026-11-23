#ifndef MATRIX_H
#define MATRIX_H

#define MAX 20

int wymiary_poprawne(int w, int k);
int zgodne_do_sumy(int wA, int kA, int wB, int kB);
int zgodne_do_mnozenia(int kA, int wB);

void dodaj(double A[][MAX], double B[][MAX],
           double C[][MAX], int w, int k);

void odejmij(double A[][MAX], double B[][MAX],
             double C[][MAX], int w, int k);

void pomnoz(double A[][MAX], double B[][MAX],
            double C[][MAX], int wA, int kA, int kB);

#endif
