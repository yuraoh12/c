#include<stdio.h>
int max(int*, int); // 최댓값 반환 
int min(int*, int); // 최소값 반환 
void sort(int*, int); // 오름차순 정렬
void print(int*, int); // 데이터 출력 
main() {
	int score[] = { 90, 88, 30, 32, 78, 74, 43, 57 };
	int cnt = sizeof(score) / sizeof(score[0]);
	int max1 = max(score, cnt);
	printf("MAX = %d\n", max1);
	int min1 = min(score, cnt);
	printf("MIN = %d\n", min1);
	sort(score, cnt);
	print(score, cnt);
}
void print(int* val, int cnt) {
	int val;
	int x;
	printf("Data: ");
	for (x = 0; x < cnt; x++) {
		printf("%5d", *(val + x));
	}
	printf("\n");
}
int max(int* val, int cnt) {
	int max = *val;
	int x;
	for (x = 1; x < cnt; x++) {
		if (max < *(val + x)) {
			max = *(val + x);
		}
	}
	return max;
}

int min(int* val, int cnt) {
	int x, y;
	for (x = 0; x < cnt - 1; x++) {
		for (y = x + 1; y < cnt; y++){
			if (*(val + x) > *(val + y)) {
				int temp = *(val + x);
				*(val + x) = *(val + y);
				*(val + y) = temp;
 			}
		}
	}
}

