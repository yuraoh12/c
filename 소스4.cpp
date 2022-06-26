#include<stdio.h>

int main() {

	typedef unsigned long long pactorial_t;

	pactorial_t e; //unsigned long long e;
	/*
 - typedef을 사용하면 아래와 같이 긴자료형이나 자주 쓰는 자료형을 별칭을 줘서 새로운 자료형을 정의 할 수 있다.
 unsigned long long a;
 unsigned long long b;
 unsigned long long c;
 unsigned long long d;

 unsigned long long test;

 // typedef 원래 자료형 별칭;
 typedef unsigned long long pactorial_t;

 pactorial_t e; // unsigned long long e;
	
	*/

	//배열

	int arr[4] = { 1,2,3,4 };
	typedef int arr_type[4];
	arr_type arrA = { 5,6,7,8 }; //int arrA[4] = {5,6,7,8};

	//arr_type의 배열도 만들 수 있다.
	arr_type arrB[5]; //int arrB[5][4]

	//포인터
	const char* name = "yura";

	// char name[]
	// const char * => 상수형 char를 가리키는 포인터

	//char *
	//char a[10] = "Heeloo\0";
	//char *b = "hello";


	const char* b = "hello";
	printf("%s\n", b);

	typedef const char* string;
	string name = "yuraoh";
	string abc[3] = { "a", "b", "c" }; // char *abc = {"a", "b", "c"};


	struct { int x, y; } rectangle;

	rectangle.x = 6;
	rectangle.y = 2;

	printf("가로: %d, 세로: %d", rectangle.x, rectangle.y);


	// 구조체 변수의 멤버에 접근 할 때에는 .를 사용하고,
	//구조체 포인터가 가리키는 구조체의 멤버에 접근할 때에는 ->를 사용한다. 

#include<stdio.h>

	int main() {
		/*
		// 구조체
		// 가로(x) 6, 세로(y) 2인 직사각형
		typedef int rectangle[2];
		rectangle rec_a = { 6, 2 };
		printf("%d %d\n", rec_a[0], rec_a[1]);

		// rec_a.x , rec_a.y
		*/

		/*
		// 여러 변수를 한꺼번에 묶어서 새로운 자료형을 만든다.
		struct { int x, y; } rectangle;

		rectangle.x = 6;
		rectangle.y = 2;

		printf("가로 : %d, 세로 : %d", rectangle.x, rectangle.y);
		*/

		/*
		typedef struct { int x, y; } rectangle;

		rectangle rec_a = {6, 2};
		struct test { int x, y; };

		typedef struct { int x, y; } a;
		a a_test = {2, 4}; // 앞에 struct이 없음

		struct b { int x, y; };
		struct b b_test; // 앞에 struct이 붙어야함
		*/
		/*
		struct example {
			int a, b;
			char c[100];
			int* d;
		};
		*/

		// 학생 정보 저장 구조체
		// 이름100, 학년, 점수score

		struct studentInfo {
			char name[100];
			int grade;
			int score;
			int* a;
		};
		/*
		// 초기화
		struct studentInfo student_a = {"오유라", 4, 85};

		printf("학생 이름 : %s\n", student_a.name);
		printf("학생 학년 : %d\n", student_a.grade);
		printf("학생 점수 : %d\n", student_a.score);

		struct studentInfo student_b = student_a;

		printf("b학생 이름 : %s", student_b.name);
		printf("b학생 학년 : %d", student_b.grade);
		printf("b학생 점수 : %d", student_b.score);
		*/
		int num = 4;
		studentInfo student_c = { "a", 3, 100, &num };
		studentInfo* ptr_student = &student_c;
		printf("c학생 점수 : %d\n", (*ptr_student).score);
		printf("c학생 점수 : %d\n", ptr_student->score);
		printf("c학생 포인터 : %d\n", *student_c.a);

		// 구조체 변수의 멤버에 접근 할 때에는 . 를 사용하고,
		// 구조체 포인터가 가리키는 구조체의 멤버에 접근할 때에는 -> 를 사용한다.
	}
}
