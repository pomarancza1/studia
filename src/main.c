#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	if( res == 1 ) {	// elminate(A,b) zwraca 1 dla macierzy osobliwej
		printf( "macierz osobliwa\n" );
		return 1;
	}
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);

		if( res == 1 ) {	// backsubst(x,A,b) zwraca 1, gdy na diagonali pojawi się 0
			printf( "Zero na diagonali (dzielenie przez zero)\n" );
			return 1;
		}
		if( res == 2 ) {	// backsubst(x,A,b) zwraca 2, gdy rozmiar macierzy jest zły
			printf( "Zły rozmiar macierzy\n" );
			return 1;
		}

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
