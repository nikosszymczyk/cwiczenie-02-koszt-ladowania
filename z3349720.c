#include <stdio.h>
#define PI 3.14

double przelicz_omega_na_czest(double omega, int pokaz)
{	double wynik = omega / (2 * PI);
	if( pokaz) 
	{	printf("\nprzelicz_omega_na_cz dla omega=%lf, cz=%lf", omega, wynik);
	}
	return wynik;
}

double przelicz_czest_na_omega(double f, int pokaz)
{	double wynik = 2 * PI * f;
	// tutaj obliczamy wynik
	
	if( pokaz) 
	{	printf("\nprzelicz_czes_na_omega dla f=%lf, omega=%lf", f, wynik);
	}
	return wynik; // zwracamy wynik
}

#define F_OD 50
#define F_DO 100
#define F_KROK 10

int main(void)
{
	int f = 50;
	double omega = przelicz_czest_na_omega(f,1);
	przelicz_omega_na_czest(omega, 1);
	
	omega = przelicz_czest_na_omega(100,1);
	przelicz_omega_na_czest(omega, 1);
	
	// a teraz test petli od 50 do 100 z krokiem co 10
	printf("\n\n\ntest petli od=%d do=%d z krokiem %d", F_OD, F_DO, F_KROK);
	
	for(f=F_OD /*wart pocz*/; f<=F_DO /*dopoki prawda*/; f=f+F_KROK /*zwieksz krok*/)
	{	omega = przelicz_czest_na_omega(f,1);
		przelicz_omega_na_czest(omega, 1);
	}
	return 0;
}

