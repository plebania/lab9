#include "testy_marcin.h"
#define ILE_TESTOW 2
void testy()
{
    int res;
    char nazwa_pliku[50];
    int bledy = 0;
    for (int nr_testu = 1; nr_testu <= ILE_TESTOW; nr_testu++)
    {
        sprintf(nazwa_pliku, "./dane/testy/test%c_A.txt", nr_testu + '0');
        Matrix *A = readFromFile(nazwa_pliku);
        sprintf(nazwa_pliku, "./dane/testy/test%c_B.txt", nr_testu + '0');
        Matrix *b = readFromFile(nazwa_pliku);
        sprintf(nazwa_pliku, "./dane/testy/test%c_out.txt", nr_testu + '0');
        Matrix *out = readFromFile(nazwa_pliku);
        Matrix *x;
        if (A == NULL)
        {
            printf("nie udało się wczytać macierzy A testu test%d\n", nr_testu);
            goto _continue;
        }
        if (b == NULL)
        {
            printf("nie udało się wczytać macierzy b testu test%d\n", nr_testu);
            goto _continue;
        }
        if (out == NULL)
        {
            printf("nie udało się wczytać macierzy out testu test%d\n", nr_testu);
            goto _continue;
        }
        res = eliminate(A, b);
        if (res)
        {
            printf("błąd test%d: wczytano macierz osobliwą\n", nr_testu);
            bledy = 1;
            goto _continue;
        }
        x = createMatrix(b->r, 1);
        if (x != NULL)
        {
            res = backsubst(x, A, b);
            if (res == 2)
            {
                printf("błąd test%d: wczytano macierz o błędnych wymiarach\n", nr_testu);
                bledy = 1;
                goto _continue;
            }
            else if (res)
            {
                printf("błąd test%d: wczytano macierz osobliwą\n", nr_testu);
                bledy = 1;
                goto _continue;
            }
            if (!comp_matrix(x, out))
            {
                bledy = 1;
                printf("błąd test%d: wynik nie zgodny z przewidywanym\n", nr_testu);
                printf("macierz x:\n");
                printToScreen(x);
                printf("macierz out:\n");
                printToScreen(out);
            }
        }
        else
        {
            fprintf(stderr, "Błąd test%d: Nie mogłem utworzyć wektora wynikowego x.\n", nr_testu);
        }
    _continue:
        freeMatrix(A);
        freeMatrix(b);
        freeMatrix(x);
    }
    if (!bledy)
        printf("testy zakończone, błędów nie wykryto, zadanie oceniono na maksymalną ilość punktów :)\n");
}