#include <iostream>
#include <vector>

using namespace std;

int main() {

	// STL(Standard Template Library)
	// vector
	// map

	// 컨테이너, 컬렉션, 자료구조, 

	// 선언, 추가, 삭제, 수정, 조회

	// 선언
	vector<int> v1; // 길이 0인 벡터
	vector<string> v2{ "a", "b", "c", "d" }; // 1,2,3,4를 저장한 길이4 짜리 벡터

	// 사이즈 확인1
	cout << "v1 : " << v1.size() << endl;
	cout << "v2 : " << v2.size() << endl;

	// 추가
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back("e");

	// 사이즈 확인2
	cout << "v1 : " << v1.size() << endl;
	cout << "v2 : " << v2.size() << endl;

	// 조회 - at, []
	cout << v1.at(0) << endl;
	cout << v2.at(2) << endl;

	cout << v1[0] << endl;
	cout << v2[2] << endl;

	// 다건 조회
	// 반복문 돌리기1
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	// 반복문 돌리기2
	for (auto num : v1) {
		cout << num << endl;
	}

	// 이터레이터(반복자) -> 포인터
	// begin(), end() -> 이터레이터 반환
	// STL은 모두 이렇게 공통된 방식으로 사용 가능

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	// 수정
	v1[0] = 100;
	v1.at(1) = 200;

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	// 삭제
	v1.erase(v1.begin() + 2);

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}