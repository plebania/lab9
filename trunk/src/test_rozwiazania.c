#include "test_rozwiazania.h"
#define ilosc_testow 2

void test_1() {

    char nazwa_pliku[50];
    int bledy = 0;

    for (int nr = 1; nr <= ilosc_testow ; nr++)
    {
        sprintf(nazwa_pliku, "./dane/testy/test%c_A.txt", nr + '0');
        Matrix* A = readFromFile(nazwa_pliku);
        sprintf(nazwa_pliku, "./dane/testy/test%c_B.txt", nr + '0');
        Matrix* b = readFromFile(nazwa_pliku);
        sprintf(nazwa_pliku, "./dane/testy/test%c_out.txt", nr + '0');
        Matrix* out = readFromFile(nazwa_pliku);
        if (A == NULL || b == NULL || out == NULL) {
            printf("Nie udalo sie wczytac jednego z macierzy\n");
            freeMatrix(A);
            freeMatrix(b);
            freeMatrix(out);
            bledy++; 
            continue;
            
        }
        int result_eliminate = eliminate(A, b);

        if (result_eliminate != 0) {
            printf("Nie udalo sie utowrzyc macierzy schodkowej\n");
            freeMatrix(A);
            freeMatrix(b);
            freeMatrix(out);
            bledy++;
            continue;
        }

        Matrix* x = createMatrix(A->r, 1);
        if (x != NULL) {

            int result_backsubst = backsubst(x, A, b);
            if (result_backsubst == 2) {
                printf("Wczytano macierz o blednych wymiarach\n");
                freeMatrix(A);
                freeMatrix(b);
                freeMatrix(out);
                freeMatrix(x);
                bledy++;
                continue;
            }
            if (result_backsubst == 1) {
                printf("Wczytano macierz osobliwa \n");
                freeMatrix(A);
                freeMatrix(b);
                freeMatrix(out);
                freeMatrix(x);
                bledy++;
                continue;
            }
            if (comp_matrix(x, out) == 0) {
                printf("Wynik rozny od przeiwdywanego:\n");
                printf("Oczekiwany macierz z pliku _out:\n");
                printToScreen(out);
                printf("Macierz wynikowa x:\n");
                printToScreen(x);
                freeMatrix(A);
                freeMatrix(b);
                freeMatrix(out);
                freeMatrix(x);
                bledy++;
                continue;
            }
        }
        else {
            printf("Nie mozna utworzyc macierza z wynikami\n");
            freeMatrix(A);
            freeMatrix(b);
            freeMatrix(out);
            bledy++;
            continue;
        }
    }
    if (bledy == 0) {
        printf("Sprawdzanie przebieglo pomyslnie, nie wykryto bledow \n");
    }
}