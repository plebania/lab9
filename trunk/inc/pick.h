#ifndef _PICK_H
#define _PICK_H

#include "mat_io.h"
void switch_rows(Matrix *a, int r1, int r2);
double my_abs(double a);

int pick(Matrix *mat, Matrix *b, int kol);

#endif
