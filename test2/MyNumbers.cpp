#include <iostream>
#include "MyNumbers.h"

using namespace std;

MyNumbers::MyNumbers(int no, int size) : mNo(no), mSize(size) {
    mArr = new int[mSize];
    for (int i = 0; i < mSize; i++) {
        mArr[i] = i + 1;
    }
    cout << no << "번 메모리 동적 할당 후 초기화 완료" << endl;
}

MyNumbers::~MyNumbers() {
    delete mArr;
    cout << mNo << "번 메모리 해제 완료" << endl;
}

int MyNumbers::getSum() {
    int sum = 0;
    for (int i = 0; i < mSize; i++) {
        sum += mArr[i];
    }

    return sum;
}