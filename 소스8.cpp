//비트와이즈	
//기계의 근본연산
/*
Bitwise or  |
Bitwise and  &
shift  <<  >>
*/
#include <cstdio>

void foo(int params) {
	int category1 = 1;
	int category2 = 1 << 1; //2
	int category3 = 1 << 2; //4

	if ((category1 & params) != 0) {
		printf("카테고리 1에 포함\n");
	}
	if ((category2 & params) != 0) {
		printf("카테고리 2에 포함\n");
	}
	if ((category3 & params) != 0) {
		printf("카테고리 3에 포함\n");
	}
}

int main() {
	int v1 = 1;
	int v2 = 2;

	int bitwise_or = v1 | v2;
	printf("%d\n", bitwise_or);

	int bitwise_and = v1 & v2;
	printf("%d\n", bitwise_and);

	int bitwise_xor = v1 ^ v2;
	printf("%d\n", bitwise_xor);

	int shift_left = v2 << 1; //2,4,8 단위로 곱하기
	printf("%d\n", shift_left);

	int shift_right = v2 >> 1; //2,4,8, 단위로 나누기
	printf("%d\n", shift_right);

	int mario_category = 8 + 4 + 2 + 1; // 비트연산해서 마리오와 지형지물이 겹치면 true반환
	int ememy_category = 0 + 4 + 2 + 1;
	int turtle_category = 0 + 0 + 2 + 1;
	int terrian_category = 0 + 4 + 0 + 0;

	foo(1 | 2);
	return 0;
}