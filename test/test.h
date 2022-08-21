#pragma once
class Test
{
private:
	int no;
	char str[20];
	int* arr;

public:
	Test();
	Test(int age, const char* str);
	Test(const Test& copyTarget);
	~Test();
	void printNo() const;
	void printStr() const;
	void printArr() const;
	void setStr(const char* str);
	void setNo(int no);
	void setArr(int arr);
};

