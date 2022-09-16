#include <iostream>
#include <vector>

using namespace std;

//문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 [sun, bed, car]이고 n이 1이면 각 단어의 인덱스 1의 문자 u, e, a로 strings를 정렬합니다.

// 정렬은 가장 쉬운 거품정렬을 이용하시면 편합니다.

// 예시1 ["sun", "bed", "car"] , n이 1이면, ["car", "bed", "sun"]
// 예시2 ["abce", "abcd", "cdx"] , n이 2이면, ["abcd", "abce", "cdx"]

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

    // 정답 : car bed sun

}