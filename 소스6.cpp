#include <iostream>
#include <vector>

using namespace std;

int main() {

	// STL(Standard Template Library)
	// vector
	// map

	// �����̳�, �÷���, �ڷᱸ��, 

	// ����, �߰�, ����, ����, ��ȸ

	// ����
	vector<int> v1; // ���� 0�� ����
	vector<string> v2{ "a", "b", "c", "d" }; // 1,2,3,4�� ������ ����4 ¥�� ����

	// ������ Ȯ��1
	cout << "v1 : " << v1.size() << endl;
	cout << "v2 : " << v2.size() << endl;

	// �߰�
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back("e");

	// ������ Ȯ��2
	cout << "v1 : " << v1.size() << endl;
	cout << "v2 : " << v2.size() << endl;

	// ��ȸ - at, []
	cout << v1.at(0) << endl;
	cout << v2.at(2) << endl;

	cout << v1[0] << endl;
	cout << v2[2] << endl;

	// �ٰ� ��ȸ
	// �ݺ��� ������1
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	// �ݺ��� ������2
	for (auto num : v1) {
		cout << num << endl;
	}

	// ���ͷ�����(�ݺ���) -> ������
	// begin(), end() -> ���ͷ����� ��ȯ
	// STL�� ��� �̷��� ����� ������� ��� ����

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	// ����
	v1[0] = 100;
	v1.at(1) = 200;

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	// ����
	v1.erase(v1.begin() + 2);

	for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}