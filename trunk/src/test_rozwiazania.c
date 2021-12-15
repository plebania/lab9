#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"

void test(Matrix* x, Matrix* mat, Matrix* b) {
    for (int i = 0; i < mat->r; i++) {
        double suma = 0;
        printf("%d rownanie: ", i + 1);
        for (int j = 0; j < mat->c; j++) {
            suma += mat->data[i][j] * x->data[j][0];
            printf("%.2lf * %.2lf + ", mat->data[i][j], x->data[j][0]);
        }
        printf("= %.2lf, powinno byc %.2lf\n", suma, b->data[i][0]);
    }
}