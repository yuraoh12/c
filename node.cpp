// 문제 : 회원의 수를 미리 정하지 않고 한명씩 입력할 때마다 저장해주세요. 회원의 수를 알 수 없기 때문에 정적, 동적 배열 모두 사용할 수 없으며 서로 흩어진 회원 정보들을 앞선 3명의 사람 문제처럼 서로 연결해야합니다.

// 예시
/*
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 20[엔터]
이름을 입력해주세요 : 홍길동[엔터]
주소를 입력해주세요 : 대전[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 50[엔터]
이름을 입력해주세요 : 임꺽정[엔터]
주소를 입력해주세요 : 경기[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 1
나이를 입력해주세요 : 23[엔터]
이름을 입력해주세요 : 황진이[엔터]
주소를 입력해주세요 : 서울[엔터]
주소록이 추가되었습니다.
메뉴를 선택해주세요(1. 주소록 추가, 2. 주소록 조회, 3. 주소록 삭제, 4. 종료) : 2
== 전체 회원 리스트 ==
1번째 사람의 나이, 이름 : 20, 홍길동, 대전
2번째 사람의 나이, 이름 : 50, 임꺽정, 경기
3번째 사람의 나이, 이름 : 23, 황진이, 서울

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person {
	int age;
	char name[20];
	char address[20];

	struct Person* next;
};

int main(void) {
	
	int menu = 0;
	int count = 0;

	struct Person* first = NULL;  // 첫번째 사람
	struct Person* current = NULL; // 새로 생성된 사람
	struct Person* last = NULL; // 마지막 사람

	while (1) {
		printf("메뉴를 선택해주세요 (1. 주소록 추가, 2. 주소록 조회 3. 주소록 삭제, 4. 종료):");
		scanf("%d", &menu);

		if (menu == 1) {

			current = malloc(sizeof(struct Person));

			printf("나이를 입력해주세요 :");
			scanf("%d", &current->age);

			printf("이름을 입력해주세요 :");
			scanf("%s", current->name);

			printf("주소를 입력해주세요 :");
			scanf("%s", current->address);

			printf("주소록이 추가되었습니다.\n");

			if (count == 0) {
				first = current;
				last = current;
			}
			else {
				last->next = current;
				last = current;

			}

			count++;

		}
		else if (menu == 2) {
			printf("== 전체 회원 리스트 ==\n");
			/*for (int i = 0; i < count; i++) {
				printf("%d번째 사람의 나이, 이름, 주소 : %d, %s, %s\n", i + 1, people[i].age, people[i].name, people[i].address);
			}*/

			struct Person* target = first;
			for (int i = 0; i < count; ++i) {
				printf("%s\n", target->name);
				target = target->next;
			}

		}
		else if (menu == 3) {

			/*printf("== 전체 회원 리스트 ==\n");
			for (int i = 0; i < count; i++) {
				printf("%d번째 사람의 나이, 이름, 주소 : %d, %s, %s\n", i + 1, people[i].age, people[i].name, people[i].address);
			}

			int target;

			printf("몇번째 주소록을 삭제하시겠습니까? : ");
			scanf("%d", &target);

			for (int i = target - 1; i < count - 1; ++i) {
				people[i] = people[i + 1];
			}

			--count;

			printf("%d번째 주소록이 삭제되었습니다.\n", target);*/   

		}
		else if (menu == 4) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else {
			printf("알 수 없는 명령어입니다.\n");
		}
	}

	return 0;
}
