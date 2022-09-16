#include <iostream>
#include <vector>

using namespace std;

//���ڿ��� ������ ����Ʈ strings��, ���� n�� �־����� ��, �� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. ���� ��� strings�� [sun, bed, car]�̰� n�� 1�̸� �� �ܾ��� �ε��� 1�� ���� u, e, a�� strings�� �����մϴ�.

// ������ ���� ���� ��ǰ������ �̿��Ͻø� ���մϴ�.

// ����1 ["sun", "bed", "car"] , n�� 1�̸�, ["car", "bed", "sun"]
// ����2 ["abce", "abcd", "cdx"] , n�� 2�̸�, ["abcd", "abce", "cdx"]

void swap(string& str1, string& str2) {
    string tmp = str1;
    str1 = str2;
    str2 = tmp;
}

vector<string> solution(vector<string> strings, int n) {

    for (int i = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings.size() - 1; j++) {
            if (strings[j][n] > strings[j + 1][n]) {
                swap(strings[j], strings[j + 1]);
            }
            else if (strings[j][n] == strings[j + 1][n]) {
                if (0 < strings[j].compare(strings[j + 1])) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }

    return strings;
}

int main() {
    vector<string> strings;
    strings.push_back("sun");
    strings.push_back("bed");
    strings.push_back("car");

    int n = 1;

    vector<string> result = solution(strings, n);

    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }

    // ���� : car bed sun

}