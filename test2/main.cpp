#include <iostream>
#include "MyNumbers.h"

using namespace std;

int main() {
	MyNumbers myNum1(1, 10);
	// 1�� �޸� ���� �Ҵ� �� �ʱ�ȭ �Ϸ�

	int rst1 = myNum1.getSum();
	cout << rst1 << endl; // 55

	MyNumbers myNum2(2, 100);
	int rst2 = myNum2.getSum();
	// 2�� �޸� ���� �Ҵ� �� �ʱ�ȭ �Ϸ�

	cout << rst2 << endl; // 5050

	// 2�� �޸� ���� �Ϸ�
	// 1�� �޸� ���� �Ϸ�
}