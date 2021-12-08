#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	if (mat->r != x->r || mat->r != b->r || mat->r != mat->c || x->c != 1 || b->c != 1)
		return 2;
	for (int x = 0; x < mat->r; x++)
		if (!mat->data[x][x])
			return 1;
	for (int y = mat->c - 1; y >= 0; y--)
	{
		x->data[y][0] = 0;
		for (int i = mat->r - 1; i > y; i--)
		{
			//printf("i=%d y=%d\nmat[y][i]=%lf x[i][0]=%lf\n", i, y, mat->data[y][i], x->data[i][0]);
			x->data[y][0] -= mat->data[y][i] * x->data[i][0];
		}
		x->data[y][0] += b->data[y][0];
		x->data[y][0] /= mat->data[y][mat->r - 1];
		//printf("x[y][0]=%lf\n", mat->data[y][0]);
	}
	return 0;
}
