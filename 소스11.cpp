#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Person {

	int age;
	int height;
	int weight;

};

int main() {

	// vector -> 순서가 있는 데이터의 나열 -> 순번, 순서(인덱스)로 관리
	// 규칙성이 있고, 일괄처리에 편하다
	// 데이터의 구조화 용도로 사용하기에는 불편



	vector<int> p1;
	p1.push_back(20); // 나이
	p1.push_back(177); // 키 height
	p1.push_back(67); // 몸무게


	for (auto tmp : p1) {
		cout << tmp << endl;
	}

	// key - value -> 쌍 : pair
	pair<string, int> pair1 = make_pair("나이", 20);
	pair<string, int> pair2 = make_pair("키", 177);
	pair<string, int> pair3 = make_pair("몸무게", 67);

	map<string, int> p2 = { pair1, pair2, pair3 };

	// 조회
	cout << p2.at("몸무게") << endl;
	cout << p2["몸무게"] << endl;

	// 추가
	p2.insert(make_pair("자산", 1000));

	cout << p2["자산"] << endl;

	// 수정
	p2.at("자산") = 3000;
	cout << p2.at("자산") << endl;

	p2["자산"] = 2000;
	cout << p2["자산"] << endl;

	// 삭제
	//p2.erase(p2.find("자산"));
	cout << p2.at("자산") << endl;

	// 전체조회
  // iterator : 반복자 -> 포인터 -> 컨테이너(컬렉션)를 일관되게 제어하는 방법
	map<string, int>::iterator iter;

	for (iter = p2.begin(); iter != p2.end(); iter++) {
		cout << iter->first << " : " << iter->second << endl;
	}

	// 범위기반 for문과 auto를 사용하면 훨 편하게 사용 가능. 하지만 가독성이 안좋으므로 신중하게 사용해야 함.
	for (auto tmp : p2) {
		cout << tmp.first << " : " << tmp.second << endl;
	}
	// ================================================================================================
	// vector case
	vector<int> v1{ 1,2,3,4 };

	// vector 범위기반 for
	for (auto tmp : v1) {
		cout << tmp << endl;
	}

	// vector의 iterator 사용
	vector<int>::iterator iter2;

	for (iter2 = v1.begin(); iter2 != v1.end(); iter2++) {
		cout << *iter2 << endl;
	}



	return 0;
}