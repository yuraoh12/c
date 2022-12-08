#include<stdio.h>
int scoreMax(int a[]);//최대값을 찾아서 리턴하는 함수
void printScore(int a[]);//배열의 내용을 출력하는 함수
void sortScore(int a[]); //오름차순으로 정렬하는 함수

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
