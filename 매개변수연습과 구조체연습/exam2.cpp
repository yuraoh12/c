#include <stdio.h>
#include <string.h>

struct Person {
	int age;
	char name[20];
	char home[20];
};

//����ü = call by value
void intro(struct Person p) {
	printf("%d�� %s�� ��� %s�Դϴ�.\n", p.age, p.home, p.name);
}


int main(void) {

	int arr[3] = { 1,2,3 };
	arr[0] = 20;
	/*

	  int age = 20;
	  char name[20] = "ȫ�浿";
	  char home[20] = "����";

	  int age2 = 24;
	  char name2[20] = "ȫ�浿";
	  char home2[20] = "����";

	*/
	struct Person p1 = { 20, "ȫ�浿", "����" };
	struct Person p2;
	p2.age = 40;
	strcpy(p2.name, "�̼���"); //name�� �迭�̶� stycpy����Ѵ�.  
	strcpy(p2.home, "����");

	printf("%d\n", p1.age);
	printf("%d\n", p2.age);


	intro(p1);
	intro(p2);

	return 0;
}