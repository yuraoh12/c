#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

    int menu = 0; // 메뉴 선택 변수
    int targetBurger = -1; // 버거 선택할 때 사용할 변수
    int burgerCount = 0; // 버거 몇개 시켰는지 기억

    string burgerNames[10] = {"한우불고기버거", "치즈버거", "치킨버거", "새우버거"}; // 버거 이름 배열
    int burgerPrices[10] = {6000, 3000, 3500, 3200}; // 버거 가격 배열
    int burgerCart[10]; // 버거 장바구니

    while (true) {
        cout << endl;
        cout << "== 햄버거 키오스크 v1 ==" << endl;
        cout << "1. 햄버거 선택 " << endl;
        cout << "2. 사이드 선택 " << endl;
        cout << "3. 음료수 선택 " << endl;
        cout << "4. 메뉴 취소 " << endl;
        cout << "5. 주문 하기 " << endl;
        cout << "====== 주문 목록 =====" << endl;
        

        // 장바구니에 있는 내용을 일괄 출력
        cout << "버거: [";
        for (int i = 0; i < burgerCount; ++i) {
            int target = burgerCart[i];
            cout << burgerNames[target] << " ";
        }
        cout <<"]" << endl;



        cout << "사이드: []" << endl;
        cout << "음료수: []" << endl;

        int totalPrice = 0;

        for (int i = 0; i < burgerCount; ++i) {
          int target = burgerCart[i];
          totalPrice += burgerPrices[target];
        }

        cout << "총금액: " << totalPrice << endl;
        cout << "무엇을 하시겠습니까 : ";
        cin >> menu;

        if (menu == 1) {
            cout << "=== 햄버거 목록 ===" << endl;
            cout << " 1. 한우불고기버거 6000" << endl;
            cout << " 2. 치즈버거 3000" << endl;
            cout << " 3. 치킨버거 3500" << endl;
            cout << " 4. 새우버거 3200" << endl;
            cout << "어떤 버거를 고르시겠습니까 :";
            cin >> targetBurger;

            // 주문한 버거를 장바구니에 일단 담기
            burgerCart[burgerCount++] = targetBurger - 1;

        }
        else {
            cout << "아직 구현되지 않았습니다." << endl;
        }
    }


	return 0;
}
