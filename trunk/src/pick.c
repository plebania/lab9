#include "pick.h"

int pick(Matrix* mat, Matrix* b, int nr_kolumny)
{
    double max = my_abs(mat->data[nr_kolumny][nr_kolumny]);
    int max_id = nr_kolumny;
    for (int j = nr_kolumny; j < mat->r; j++) {
        if (my_abs(mat->data[j][nr_kolumny]) > max) {
            max_id = j;
            max = my_abs(mat->data[j][nr_kolumny]);
        }
    }
    if (max_id != nr_kolumny) {
        switch_rows(mat, nr_kolumny, max_id);
        switch_rows(b, nr_kolumny, max_id);
    }
    return 0;
}

void switch_rows(Matrix* a, int r1, int r2)
{
    double tmp;
    for (int i = 0; i < a->c; i++) {
        tmp = a->data[r1][i];
        a->data[r1][i] = a->data[r2][i];
        a->data[r2][i] = tmp;
    }
}

double my_abs(double a)
{
    if (a > 0)
        return a;
    else
        return -a;
}