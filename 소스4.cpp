#include<stdio.h>

int main() {

	typedef unsigned long long pactorial_t;

	pactorial_t e; //unsigned long long e;
	/*
 - typedef�� ����ϸ� �Ʒ��� ���� ���ڷ����̳� ���� ���� �ڷ����� ��Ī�� �༭ ���ο� �ڷ����� ���� �� �� �ִ�.
 unsigned long long a;
 unsigned long long b;
 unsigned long long c;
 unsigned long long d;

 unsigned long long test;

 // typedef ���� �ڷ��� ��Ī;
 typedef unsigned long long pactorial_t;

 pactorial_t e; // unsigned long long e;
	
	*/

	//�迭

	int arr[4] = { 1,2,3,4 };
	typedef int arr_type[4];
	arr_type arrA = { 5,6,7,8 }; //int arrA[4] = {5,6,7,8};

	//arr_type�� �迭�� ���� �� �ִ�.
	arr_type arrB[5]; //int arrB[5][4]

	//������
	const char* name = "yura";

	// char name[]
	// const char * => ����� char�� ����Ű�� ������

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

	printf("����: %d, ����: %d", rectangle.x, rectangle.y);


	// ����ü ������ ����� ���� �� ������ .�� ����ϰ�,
	//����ü �����Ͱ� ����Ű�� ����ü�� ����� ������ ������ ->�� ����Ѵ�. 

#include<stdio.h>

	int main() {
		/*
		// ����ü
		// ����(x) 6, ����(y) 2�� ���簢��
		typedef int rectangle[2];
		rectangle rec_a = { 6, 2 };
		printf("%d %d\n", rec_a[0], rec_a[1]);

		// rec_a.x , rec_a.y
		*/

		/*
		// ���� ������ �Ѳ����� ��� ���ο� �ڷ����� �����.
		struct { int x, y; } rectangle;

		rectangle.x = 6;
		rectangle.y = 2;

		printf("���� : %d, ���� : %d", rectangle.x, rectangle.y);
		*/

		/*
		typedef struct { int x, y; } rectangle;

		rectangle rec_a = {6, 2};
		struct test { int x, y; };

		typedef struct { int x, y; } a;
		a a_test = {2, 4}; // �տ� struct�� ����

		struct b { int x, y; };
		struct b b_test; // �տ� struct�� �پ����
		*/
		/*
		struct example {
			int a, b;
			char c[100];
			int* d;
		};
		*/

		// �л� ���� ���� ����ü
		// �̸�100, �г�, ����score

		struct studentInfo {
			char name[100];
			int grade;
			int score;
			int* a;
		};
		/*
		// �ʱ�ȭ
		struct studentInfo student_a = {"������", 4, 85};

		printf("�л� �̸� : %s\n", student_a.name);
		printf("�л� �г� : %d\n", student_a.grade);
		printf("�л� ���� : %d\n", student_a.score);

		struct studentInfo student_b = student_a;

		printf("b�л� �̸� : %s", student_b.name);
		printf("b�л� �г� : %d", student_b.grade);
		printf("b�л� ���� : %d", student_b.score);
		*/
		int num = 4;
		studentInfo student_c = { "a", 3, 100, &num };
		studentInfo* ptr_student = &student_c;
		printf("c�л� ���� : %d\n", (*ptr_student).score);
		printf("c�л� ���� : %d\n", ptr_student->score);
		printf("c�л� ������ : %d\n", *student_c.a);

		// ����ü ������ ����� ���� �� ������ . �� ����ϰ�,
		// ����ü �����Ͱ� ����Ű�� ����ü�� ����� ������ ������ -> �� ����Ѵ�.
	}
}
