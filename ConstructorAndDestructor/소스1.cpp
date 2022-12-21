#include "헤더.h"

int main() {

	Employee* employee[100]; // 사원 명부
	int count = 0;	//현재 사원 숫자 저장

	while (true) {
		printf("명령어를 입력하세요\n");
		printf("1.사원보기\n");
		printf("2.사원추가\n");
		printf("3.사원삭제\n");
		printf("4.프로그램종료\n");

		fseek(stdin, 0, SEEK_END);
		int input;
		scanf("%d", &input);

		if (input == 1) {
			//사원보기
			printf("==사원보기==\n");
			for (int i = 0; i < count; i++) {
				employee[i]->printInfo();
			}
		}
		else if (input == 2) {
			//사원추가
			printf("==사원추가==\n");

			char* name = getString("사원명을 입력해주세요 : ");
			int gender = getInt("성별을 입력해주세요(0남성, 1여성) : ");
			char* rank = getString("직급을 입력해주세요 : ");

			Employee* e = new Employee(name, gender, rank); // 조립
			delete[] name;
			delete[] rank;

			employee[count] = e; // 사원 명부에 등록
			count++;	// 다음 줄에 기록
		}
		else if (input == 3) {
			//사원삭제
			printf("==사원삭제==\n");
			int number = getInt("사원번호를 입력해주세요 : ");
			int deletedIndex = -1;

			for (int i = 0; i < count; i++) {	//배열을 순회하는 반복문
				if (number == employee[i]->no) {	//사용자가 방금 입력한 사원번호와 배열 안의 어떤 사원번호가 일치한다면
					delete employee[i];	//사원 삭제
					deletedIndex = i;	//일치하는 사원이 있다면 해당 인덱스 부여
					break;
				}
			}
			if (deletedIndex >= 0) {	// 삭제가 됐나?
				for (int i = deletedIndex; i < count - 1; i++) { //현재 삭제된 인덱스부터 배열 끝까지
					employee[i] = employee[i + 1];	//덮어쓰기
				}
			}
			count--;
			printf("삭제 완료!\n");
		}
		else if (input == 4) {
			//프로그램종료
			printf("==프로그램종료==\n");
			break;
		}
		else {
			printf("존재하지 않는 명령어 입니다.\n");
		}
	}

	return 0;
}

int getInt(const char* prompt) {  // 사용자에게 숫자를 입력받는다.
	int input;
	printf("%s", prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);

	return input;
}  // 입력받은 값을 출력

char* getString(const char* prompt) {	// 사용자에게 문자열을 입력받는다.
	//char input[100]; // 배열의 주소만 리턴하고 실질적인 배열은 사라지므로 동적할당 해야함
	char* input = new char[100]; // 힙에 생기므로 위와 같은 문제가 발생하지 않는다.
	printf("%s", prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input); //99개 문자를 받아서 스트링으로 input에 저장

	return input;
}