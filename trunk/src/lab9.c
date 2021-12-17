#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include "pick.h"
#include "testy_marcin.h"
#include "test_rozwiazania.h"
#include <stdlib.h>
#include <stdio.h>
//#define TEST 1
int main(int argc, char **argv)
{
#ifdef TEST
	printf("\nTEST 1: ");
	test_1();
	printf("\nTEST 2: ");
	testy();
#else
	int res;
	Matrix *A = readFromFile(argc > 1 ? argv[1] : "./dane/A.txt");
	Matrix *b = readFromFile(argc > 2 ? argv[2] : "./dane/B.txt");
	Matrix *x;

	if (A == NULL)
		return -1;
	if (b == NULL)
		return -2;
	printf("Macierz A:\n");
	printToScreen(A);
	printf("Macierz b:\n");
	printToScreen(b);

	res = eliminate(A, b);
	if (res)
	{
		printf("błąd: wczytano macierz osobliwą");
		return 1;
	}
	x = createMatrix(b->r, 1);

	if (x != NULL)
	{
		res = backsubst(x, A, b);
		if (res == 2)
		{
			printf("błąd: wczytano macierz o błędnych wymiarach");
			return 1;
		}
		else if (res)
		{
			printf("błąd: wczytano macierz osobliwą");
			return 1;
		}
		printf("Macierz x:\n");
		printToScreen(x);
		freeMatrix(x);
	}
	else
	{
		fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);
#endif

	return 0;
}