#include "pick.h"

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
	return nr_max;
}