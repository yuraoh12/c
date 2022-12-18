#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyUniquePtr {
	int* arr;

public:
	MyUniquePtr(int* arr) {
		this->arr = arr;
	}
	~MyUniquePtr() {
		delete arr;
	}
};

class Test {
private:
	int data;
public:
	Test() {
		cout << "������ ����" << endl;
	}

	~Test() {
		cout << "�Ҹ��� ����" << endl;
	}
};

int main() {


	// ����Ʈ ������ -> ����ũ ������
	// ����ũ�� �ǹ̴� �ϳ��� ����ũ �����Ͱ� �����ϸ� �ش� �����ʹ� �ٸ� ����ũ �����Ϳ����� ����� �� ����. 


	//Test* t1 = new Test();

	// int* num = new int(10);
	// delete num;
	//int* pnum = &num;

	//unique_ptr<int> pnum2(&num);


	// int* num = new int(10);

	// num�� �ּҸ� ���� ����. 
	// unique_ptr<int> pnum(num);	
	// unique_ptr<int> pnum2(num);

	// ���� �ּҸ� ������� ���ϵ��� �����Ҵ絵 ��� ����.
	//unique_ptr<int> pnum = make_unique<int>(10);
	//unique_ptr<int> pnum2 = make_unique<int>(10);


	// ���� �����Ҵ� �ϰ� delete�� ���� �ʾ��� ��.
	/*{
		int* pnum = new int(10);
		int* pnum2 = new int(10);
	}*/

	// ����ũ �����ͷ� �����Ҵ� �ϰ� delete ���� �ʾ��� ��.
	/*{
		unique_ptr<int> pnum = make_unique<int>(10);
		unique_ptr<int> pnum2 = make_unique<int>(10);
	}*/

	//delete pnum;

	//MyUniquePtr myPnum(new int(10));
	/*
	Test* t1 = new Test();
	Test* t2 = new Test();
	Test* t3 = new Test();
	*/
	unique_ptr<Test> t1 = make_unique<Test>();
	unique_ptr<Test> t2 = make_unique<Test>();
	unique_ptr<Test> t3 = make_unique<Test>();

	vector<unique_ptr<Test>> v1;

	v1.push_back(move(t1));
	v1.push_back(move(t2));
	v1.push_back(move(t3));

}