#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Test.h"

using namespace std;

Test::Test() : Test(0, "")
{}

Test::Test(int no, const char* str) : no(no) {

	arr = new int(10); // malloc(sizeof(int))
	setStr(str);
}

// 복사생성자
Test::Test(const Test& copyTarget) {
	this->no = copyTarget.no;
	strcpy(str, copyTarget.str);
	arr = new int(0);
	*(this->arr) = *(copyTarget.arr);
}


Test::~Test()
{
	delete arr;
}

void Test::setStr(const char* str) {
	strcpy(this->str, str);
}

void Test::setNo(int no) {
	this->no = no;
}

void Test::setArr(int arr) {
	*(this->arr) = arr;
}

void Test::printNo() const {
	cout << this->no << endl;
}

void Test::printStr() const {
	cout << this->str << endl;
}

void Test::printArr() const {
	cout << *(this->arr) << endl;
}