#include<stdio.h>

int main() {

	// 2차원 배열 포인터
	int  arr[2][3] = {
		{1,2,3},
		{4,5,6}

	};

	printf("%d\n", sizeof(arr)); //24 : 2차원 배열안에 있는 전체 정수의 크기
	printf("%d\n", sizeof(arr[0])); //12
	printf("%d\n", sizeof(arr[0][0])); //4

	printf("%d\n", &arr);
	printf("%d\n", &arr[0]);
	printf("%d\n", &arr[0][0]);


/*	int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	int(*ptr)[3] = arr;

	//2차원 배열안에 값을 모두 출력하는 중첩 fort문을 만들어주세요,

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
		printf("%d" , (*ptr_row)[i]);//ptr_row가 가리키는 배열의 i번째 칸
	}
	
	int arr[4] = { 1,2,3,4 };
	int* ptr = arr;
	printf("%d\n", ptr[1][2]); //arr[1]

	for (int(*ptr)[4] = arr; ptr < arr + 3; ptr_row++)
		for (int* ptr_col = *ptr_row; ptr_col < *ptr_row + 4; ptr_col++) {
			printf("%4d", *ptr_col);

		}
	printf("\n");

	//위의 결과가 2차원 배열에서도 동일하게 적용
	//ptr은 arr의 0번 행을 가리키고있는 배열포인터여야 한다. 

	
}