#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;

	int bindex;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("=================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("=================\n");
}

int main() {
	SparseMatrix m = {
		{ {0, 4, 9}, {1, 1, 8}, {2, 0, 4}, {2, 3, 2}, {3, 5, 5}, {4, 2, 2}},
		5,
		6,
		6
	};
	SparseMatrix result;

	result = matrix_transpose2(m);
	printf("원래 행렬 \n");
	printf("rows : %d, cols : %d, terms : %d \n", m.rows, m.cols, m.terms);
	matrix_print(m);
	printf("전치 행렬 \n");
	printf("rows : %d, cols : %d, terms : %d \n", result.rows, result.cols, result.terms);
	matrix_print(result);
	
	return 0;
}