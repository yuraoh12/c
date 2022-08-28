#include <stdio.h>
#include <string.h>

struct Person {
	int age;
	char name[20];
	char home[20];
};

//구조체 = call by value
void intro(struct Person p) {
	printf("%d살 %s에 사는 %s입니다.\n", p.age, p.home, p.name);
}


int main(void) {

	int arr[3] = { 1,2,3 };
	arr[0] = 20;
	/*

	  int age = 20;
	  char name[20] = "홍길동";
	  char home[20] = "대전";

	  int age2 = 24;
	  char name2[20] = "홍길동";
	  char home2[20] = "대전";

	*/
	struct Person p1 = { 20, "홍길동", "대전" };
	struct Person p2;
	p2.age = 40;
	strcpy(p2.name, "이순신"); //name은 배열이라서 stycpy써야한다.  
	strcpy(p2.home, "서울");

	printf("%d\n", p1.age);
	printf("%d\n", p2.age);


	intro(p1);
	intro(p2);

	return 0;
}