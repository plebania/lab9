#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

#define DUZO 999999

int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	if (mat->r != x->r || mat->r != b->r || mat->r != mat->c || x->c != 1 || b->c != 1)
		return 2;
	for (int x = 0; x < mat->r; x++)
		if (mat->data[x][x] * DUZO < 1 && mat->data[x][x] * DUZO > -1)
			return 1;
	//printToScreen(b);
	for (int y = mat->c - 1; y >= 0; y--)
	{
		x->data[y][0] = 0;
		for (int i = mat->r - 1; i > y; i--)
		{
			x->data[y][0] -= mat->data[y][i] * x->data[i][0];
		}
		x->data[y][0] += b->data[y][0];
		x->data[y][0] /= mat->data[y][y];
	}
	return 0;
}
