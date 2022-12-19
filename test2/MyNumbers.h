#pragma once

class MyNumbers {
public:
	MyNumbers(int no, int size);
	~MyNumbers();
	int getSum();
private:
	int mNo;
	int mSize;
	int* mArr;
}; 
