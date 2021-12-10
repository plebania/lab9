#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{ 

	for(int i=1; i<mat->r; i++){
			for(int j=0; j<mat->c; j++){
					if(mat->data[j][j]==0)
							return 1; 
					double skalar= mat->data[i][j]/mat->data[j][j];
					for(int p=0; p<mat->c; p++)
							mat->data[i][p]-=mat->data[j][p]*skalar;
					b->data[i][0]-=b->data[j][0]*skalar;
			}
	}

	return 0;
}
