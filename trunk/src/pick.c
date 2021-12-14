#include "pick.h"

void row_up(Matrix *mat, Matrix *b, int r)
{
	double pom;
	for (int x = 0; x < mat->r; x++)
	{
		pom = mat->data[0][x];
		mat->data[0][x] = mat->data[r][x];
		mat->data[r][x] = pom;
	}
	pom = b->data[0][0];
	b->data[0][0] = b->data[r][0];
	b->data[r][0] = pom;
}

int pick(Matrix *mat, Matrix *b, int kol)
{
	double max = mat->data[kol][0];
	int nr_max = 0;
	for (int x = 0; x < mat->r; x++)
	{
		if (mat->data[kol][x] > max)
		{
			max = mat->data[kol][x];
			nr_max = x;
		}
	}
	row_up(mat, b, nr_max);
	return nr_max;
}

//git test