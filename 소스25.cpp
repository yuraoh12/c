#include<stdio.h>
void dataPrint(int[][6], int);
void pointerPrint(int *val[6], int); 

main() {
	int score[][6] = { {1,90,80,90},
					{5, 95, 84,30},
					{33, 35, 34,31},
					{51, 95, 84,30},
					{50, 45, 14,10} };

	int row = sizeof(score) / sizeof(score[0]);
	int col = sizeof(score[0] / sizeof(score[0][0]));
	int x, y;
	int row;
	printf("a\t b\t c\t f\t");
	for (x = 0; x < row; x++) {
		printf("%d\t", score[x][0]);
		printf("%s\t", *name + x);
		for (y = 1; y < col - 2; < y++) {
			printf("%d"\t, score[x][y]);
		}
	}
	pointerPrint(score, row);
	}
}
void dataPrint(int val[][6], int r) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < 6 - 2; j++) {
			printf("%d\t", val[i][j]);
		}
		printf("\n");
	}
}

void pointerPrint(int* val[6], int r) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 6 - 2; j++) {
			printf("%d\t", *val[i] + j);
		}
		printf("\t");
	}
}


