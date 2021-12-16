#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"

int test(Matrix* x, Matrix* mat, Matrix* b) { //zwraca 1 jesli uklad nie zostal rozwiazany prawidlowo,
                                            //zwraca 0 w przeciwnym wypadku

    printf("test rozwiazania: \n");
    for (int i = 0; i < mat->r; i++) {
        double suma = 0;
        printf("%d rownanie: ", i + 1);
        for (int j = 0; j < mat->c; j++) {
            suma += mat->data[i][j] * x->data[j][0];
            printf("%.2lf * %.2lf + ", mat->data[i][j], x->data[j][0]);
        }
        if (suma == b->data[i][0])
            printf("= %.2lf, powinno byc %.2lf - jest okej\n", suma, b->data[i][0]);
        else {
            printf("= %.2lf, powinno byc %.2lf - NIE ZGADZA SIE!\n", suma, b->data[i][0]);
            return 1;
        }
    }
    return 0;
}