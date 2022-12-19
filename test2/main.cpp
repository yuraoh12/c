#include <iostream>
#include "MyNumbers.h"

using namespace std;

int main() {
	MyNumbers myNum1(1, 10);
	// 1번 메모리 동적 할당 후 초기화 완료

	int rst1 = myNum1.getSum();
	cout << rst1 << endl; // 55

	MyNumbers myNum2(2, 100);
	int rst2 = myNum2.getSum();
	// 2번 메모리 동적 할당 후 초기화 완료

	cout << rst2 << endl; // 5050

	// 2번 메모리 해제 완료
	// 1번 메모리 해제 완료
}