#include 
#include 

int main() {

	// ������ �迭
	// �����͵� ������ �����̱� ������ �޸� �ּ�
	// �������� �޸� �ּҴ� �Ϲ������� �����Ϳ� ������ ���� ����,
	// ���� �����Ϳ� ���� �ؾ��Ѵ�.
	/*
	int a = 1;
	int* ptr = &a;
	int** ptr_p = &ptr;
	*/

	int size;
	printf("�迭�� ����� �Է��� �ּ��� : ");
	scanf_s("%d", &size);

	// size��ŭ �迭�� �� �����Ҵ�
	int** arr = (int**)malloc(sizeof(int*) * size);

	// size��ŭ �迭�� ĭ �����Ҵ�
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	// ���� �ֱ� ���� �ݺ���
	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
			arr[j][k] = j + k;
		}
	}

	// ����� ���� �ݺ���
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			printf("arr[%d][%d] : %d ", a, b, arr[a][b]);
		}
		printf("\n");
	}

	// �޸� ������ ���� �ݺ���
	for (int c = 0; c < size; c++) {
		free(arr[c]);
	}
	free(arr);

}