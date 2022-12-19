#include <iostream>
#include "MyNumbers.h"

using namespace std;

MyNumbers::MyNumbers(int no, int size) : mNo(no), mSize(size) {
    mArr = new int[mSize];
    for (int i = 0; i < mSize; i++) {
        mArr[i] = i + 1;
    }
    cout << no << "�� �޸� ���� �Ҵ� �� �ʱ�ȭ �Ϸ�" << endl;
}

MyNumbers::~MyNumbers() {
    delete mArr;
    cout << mNo << "�� �޸� ���� �Ϸ�" << endl;
}

int MyNumbers::getSum() {
    int sum = 0;
    for (int i = 0; i < mSize; i++) {
        sum += mArr[i];
    }

    return sum;
}