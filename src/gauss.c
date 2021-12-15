#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
	int w, k, i;
	double q;
 	

	for( k=0; k < mat->c-1; k++ ) {
		for( w=k+1; w < mat->r; w++ ){
			if( mat->data[k][k] == 0 )
				return 1;
			q = mat->data[w][k] / mat->data[k][k];
			for( i=k; i < mat->c; i++ ) {
				mat->data[w][i] -= mat->data[k][i] * q;
			}
			b->data[w][0] -= b->data[k][0] * q;
		}
	}

		return 0;
}

