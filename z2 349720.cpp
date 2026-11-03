// z2 NIKODEM SZYMCZYK 349720
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
{	double wynik = 2 * PI * f ;
	// tutaj obliczamy wynik
	
	if( pokaz ) 
	{	printf("\nprzelicz_czes_na_omega dla f=%lf, omega=%lf", f, wynik);
	}
	return wynik; // zwracamy wynik
}


int main(void)
{
	double omega = przelicz_czest_na_omega(50,1);
	przelicz_omega_na_czest(omega, 1);
	
	omega = przelicz_czest_na_omega(100,1);
	przelicz_omega_na_czest(omega, 1);
	
	return 0;
}

/*

przelicz_czes_na_omega dla f=50.000000, omega=314.000000
przelicz_omega_na_cz dla omega=314.000000, cz=50.000000
przelicz_czes_na_omega dla f=100.000000, omega=628.000000
przelicz_omega_na_cz dla omega=628.000000, cz=100.000000
--------------------------------
Process exited after 0.1272 seconds with return value 0
Press any key to continue . . .

*/

