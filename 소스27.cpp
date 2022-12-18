#include <iostream>
using namespace std;

// 구현시작
class 무기 {
public:
    virtual void 사용() {

    }
};

class 활 : public 무기 {
public:
    void 사용() {
        cout << "활로 공격합니다." << endl;
    }
};

class 칼 : public 무기 {
public:
    void 사용() {
        cout << "칼로 공격합니다." << endl;
    }
};

class 전사 {
public:
    int 나이;
    string 이름;
    무기* a무기;

    void 자기소개() {
        cout << "안녕하세요 저는" << 나이 << "살 " << 이름 << "입니다." << endl;
    }

    void 공격() {
        cout << 이름 << "(이)가 ";
        a무기->사용();
    }

};
// 구현끝

int main() {
    전사* a전사 = new 전사();

    string 이름 = "홍길동";
    a전사->이름 = 이름;
    a전사->나이 = 27;
    a전사->자기소개();
    // 출력 : 안녕하세요 저는 27살 홍길동입니다.


    a전사->a무기 = new 활();
    a전사->공격();
    // 출력 : 홍길동(이)가 활(으)로 공격합니다.

    delete a전사->a무기;

    a전사->이름 = "홍길순";
    a전사->a무기 = new 칼();
    a전사->공격();

    // 출력 : 홍길순(이)가 칼(으)로 공격합니다.

    delete a전사->a무기;

    delete a전사;
}