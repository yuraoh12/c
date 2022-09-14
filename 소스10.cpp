#include 
#include 

int main() {

	// 이차원 배열
	// 포인터도 실제로 변수이기 때문에 메모리 주소
	// 포인터의 메모리 주소는 일반적으로 포인터에 저장할 수가 없고,
	// 이중 포인터에 저장 해야한다.
	/*
	int a = 1;
	int* ptr = &a;
	int** ptr_p = &ptr;
	*/

	int size;
	printf("배열의 사이즈를 입력해 주세요 : ");
	scanf_s("%d", &size);

	// size만큼 배열의 행 동적할당
	int** arr = (int**)malloc(sizeof(int*) * size);

	// size만큼 배열의 칸 동적할당
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	// 값을 주기 위한 반복문
	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
			arr[j][k] = j + k;
		}
	}

	// 출력을 위한 반복문
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			printf("arr[%d][%d] : %d ", a, b, arr[a][b]);
		}
		printf("\n");
	}

	// 메모리 해제를 위한 반복문
	for (int c = 0; c < size; c++) {
		free(arr[c]);
	}
	free(arr);

}