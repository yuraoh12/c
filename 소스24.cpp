#include<stdio.h>
int scoreMax(int a[]);//�ִ밪�� ã�Ƽ� �����ϴ� �Լ�
void printScore(int a[]);//�迭�� ������ ����ϴ� �Լ�
void sortScore(int a[]); //������������ �����ϴ� �Լ�

void scoreSort(int score[], int cnt) {
	int x, y;
	for (x = 0; x < cnt - 1; x++) {
		for (y = x + 1; y < cnt; y++) {
			if (score[x] > score[y]) {
				int temp = score[x];
				score[x] = score[y];
				score[y] = temp;
			}
		}
	}
}
void printScore(int score) {
	int cnt = sizeof(score) / sizeof(score[int]);
	printf("data: ", cnt);
	int x;
	for (x = 0; x < cnt; x++) {
		printf("%5d", score[x]);
	}
	printf("\n");
}
main() {
	int score[8] = { 70,50,40,30,20,10,33,55 };
	int cnt = sizeof(score) / sizeof(score[0]);
	printf("%d, cnt");
	scoreMax(score);  
	printScore(score, cnt); 
	sortScore(score);  
}
