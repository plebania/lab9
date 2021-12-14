#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "pick.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//printf("test1");
	int res;
	Matrix *A = readFromFile(argc > 1 ? argv[1] : "./dane/A.txt");
	Matrix *b = readFromFile(argc > 2 ? argv[2] : "./dane/B.txt");
	Matrix *x;

	if (A == NULL)
		return -1;
	if (b == NULL)
		return -2;
	printToScreen(A);
	printToScreen(b);

	printf("%d", pick(A, b, 2));

	printToScreen(A);
	printToScreen(b);

	res = eliminate(A, b);
	printToScreen(A);
	printToScreen(b);
	x = createMatrix(b->r, 1);

	if (x != NULL)
	{
		res = backsubst(x, A, b);
		printf("%d", res);
		printToScreen(x);
		freeMatrix(x);
	}
	else
	{
		fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}