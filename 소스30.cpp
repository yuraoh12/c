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
		cout << "생성자 실행" << endl;
	}

	~Test() {
		cout << "소멸자 실행" << endl;
	}
};

int main() {


	// 스마트 포인터 -> 유니크 포인터
	// 유니크의 의미는 하나의 유니크 포인터가 존재하면 해당 포인터는 다른 유니크 포인터에서는 사용할 수 없다. 


	//Test* t1 = new Test();

	// int* num = new int(10);
	// delete num;
	//int* pnum = &num;

	//unique_ptr<int> pnum2(&num);


	// int* num = new int(10);

	// num의 주소를 둘이 소유. 
	// unique_ptr<int> pnum(num);	
	// unique_ptr<int> pnum2(num);

	// 직접 주소를 사용하지 못하도록 동적할당도 대신 해줌.
	//unique_ptr<int> pnum = make_unique<int>(10);
	//unique_ptr<int> pnum2 = make_unique<int>(10);


	// 직접 동적할당 하고 delete를 하지 않았을 때.
	/*{
		int* pnum = new int(10);
		int* pnum2 = new int(10);
	}*/

	// 유니크 포인터로 동적할당 하고 delete 하지 않았을 때.
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