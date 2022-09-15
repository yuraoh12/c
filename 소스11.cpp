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

	// vector -> ������ �ִ� �������� ���� -> ����, ����(�ε���)�� ����
	// ��Ģ���� �ְ�, �ϰ�ó���� ���ϴ�
	// �������� ����ȭ �뵵�� ����ϱ⿡�� ����



	vector<int> p1;
	p1.push_back(20); // ����
	p1.push_back(177); // Ű height
	p1.push_back(67); // ������


	for (auto tmp : p1) {
		cout << tmp << endl;
	}

	// key - value -> �� : pair
	pair<string, int> pair1 = make_pair("����", 20);
	pair<string, int> pair2 = make_pair("Ű", 177);
	pair<string, int> pair3 = make_pair("������", 67);

	map<string, int> p2 = { pair1, pair2, pair3 };

	// ��ȸ
	cout << p2.at("������") << endl;
	cout << p2["������"] << endl;

	// �߰�
	p2.insert(make_pair("�ڻ�", 1000));

	cout << p2["�ڻ�"] << endl;

	// ����
	p2.at("�ڻ�") = 3000;
	cout << p2.at("�ڻ�") << endl;

	p2["�ڻ�"] = 2000;
	cout << p2["�ڻ�"] << endl;

	// ����
	//p2.erase(p2.find("�ڻ�"));
	cout << p2.at("�ڻ�") << endl;

	// ��ü��ȸ
  // iterator : �ݺ��� -> ������ -> �����̳�(�÷���)�� �ϰ��ǰ� �����ϴ� ���
	map<string, int>::iterator iter;

	for (iter = p2.begin(); iter != p2.end(); iter++) {
		cout << iter->first << " : " << iter->second << endl;
	}

	// ������� for���� auto�� ����ϸ� �� ���ϰ� ��� ����. ������ �������� �������Ƿ� �����ϰ� ����ؾ� ��.
	for (auto tmp : p2) {
		cout << tmp.first << " : " << tmp.second << endl;
	}
	// ================================================================================================
	// vector case
	vector<int> v1{ 1,2,3,4 };

	// vector ������� for
	for (auto tmp : v1) {
		cout << tmp << endl;
	}

	// vector�� iterator ���
	vector<int>::iterator iter2;

	for (iter2 = v1.begin(); iter2 != v1.end(); iter2++) {
		cout << *iter2 << endl;
	}



	return 0;
}