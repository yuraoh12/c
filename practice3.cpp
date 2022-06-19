#include<stdio.h>

int main() {

	// 2���� �迭 ������
	int  arr[2][3] = {
		{1,2,3},
		{4,5,6}

	};

	printf("%d\n", sizeof(arr)); //24 : 2���� �迭�ȿ� �ִ� ��ü ������ ũ��
	printf("%d\n", sizeof(arr[0])); //12
	printf("%d\n", sizeof(arr[0][0])); //4

	printf("%d\n", &arr);
	printf("%d\n", &arr[0]);
	printf("%d\n", &arr[0][0]);


/*	int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	int(*ptr)[3] = arr;

	//2���� �迭�ȿ� ���� ��� ����ϴ� ��ø fort���� ������ּ���,

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", ptr[i][j]);
		}
		printf("\n");
	}

	*/
	int arr[2][3] = { {1,2,3}, {4,5,6} };
	for (int(*row)[3] = arr; row < arr + 2; row++) {
		for (int* col = *row; col < *row + 3; col++) {
			printf("%d", *col);
		}
		printf("\n");

	}
	// &(*row)[0] == *row == &arr[0] == arr
	// &row[0] => {1,2,3}


	int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int(*ptr_row)[4] = &arr[1];

	for (int i = 0; i < 4; i++) {
		printf("%d" , (*ptr_row)[i]);//ptr_row�� ����Ű�� �迭�� i��° ĭ
	}
	
	int arr[4] = { 1,2,3,4 };
	int* ptr = arr;
	printf("%d\n", ptr[1][2]); //arr[1]

	for (int(*ptr)[4] = arr; ptr < arr + 3; ptr_row++)
		for (int* ptr_col = *ptr_row; ptr_col < *ptr_row + 4; ptr_col++) {
			printf("%4d", *ptr_col);

		}
	printf("\n");

	//���� ����� 2���� �迭������ �����ϰ� ����
	//ptr�� arr�� 0�� ���� ����Ű���ִ� �迭�����Ϳ��� �Ѵ�. 

	
}