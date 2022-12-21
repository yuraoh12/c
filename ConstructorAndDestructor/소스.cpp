#define _CRT_SECURE_NO_WARNINGS
//#pragma warning (disable: 4996)
//클래스 생성자 / 소멸자
#include <cstdio>
#include <cstring>
//struct Student {
//
//};

class Student {
public:
	int student_no;
	char* name;   //name[100]
	int gender; // 0-남 1-여

	Student(int StdNo, const char* n, int g) {  // 생성자: 생성되자마자 파라미터를 이용해서 값을 초기화해 넣어준다.
		this->student_no = StdNo;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		gender = g;
	}

	~Student() { // 소멸자 : 클래스 인스턴스가 파괴될 때 -> 메모리에서 해제될 때
		printf("소멸자 호출\n");
		delete[] name;
	}

	void printStudentInfo() {
		printf("학생번호 : %d\n", student_no);
		printf("학생이름 : %s\n", name);
		printf("성별 : %s\n", gender == 0 ? "남자" : "여자");  //인라인 조건절
															// <조건절> ? 값1 : 값2
	}
};

int main() {

	Student s = Student(1234, "홍길동", 0);

	s.printStudentInfo();


	Student* ps = new Student(5678,"임꺽정",0);

	ps->printStudentInfo();

	delete ps;

	//Student s1;
	//s1.student_no = 1234;
	//strcpy(s1.name, "홍길동");
	//s1.gender = 0;

	//s1.printStudentInfo();

	//Student s2;
	//s2.student_no = 4321;
	//strcpy(s2.name, "홍길순");
	//s2.gender = 1;

	//s2.printStudentInfo();

	return 0;
}

