#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cstdlib>

//���� ������ : public, protected, private

class Animal {
	/*public:*/ //������ ���� ����
	/*protected:*/  //�ܺο��� ���� �Ұ��� ��� ���ο����� ���� ���� (��ӹ��� Ŭ������ ���� ����)
private: // �ش� Ŭ���� �������� ���� ���� (��ӹ��� Ŭ������ ���� �Ұ�)
	int legs;
	char name[50];
public:
	Animal(int legs, const char* name) {
		printf("���������� �����\n");
		this->legs = legs;
		strcpy(this->name, name);
	}

	void printInfo() {
		printf("�ٸ��� ���� : %d\n", legs);
		printf("�̸� : %s\n", name);
	}
};

class Dog : public Animal {
public:
	Dog() : Animal(4, "��") {
		printf("Dog ������ �����\n");
	}
};

class Person : public Animal {
public:
	char regist_no[30];

	Person(const char* regist_no) : Animal(2, "���") {
		printf("��������� �����\n");
		strcpy(this->regist_no, regist_no);
		//legs = 2;
		//strcpy(name, "���");
	}

	void printLegs() {
		printf("Person�� �ٸ� : %d\n", this->legs);
	}
};

int main() {

	Animal* animal;

	Person* person = new Person("1234-9999");

	printf("person->legs : %d\n", person->legs);

	//person->printInfo();

	//Dog* dog = new Dog();
	//dog->printInfo();

	//animal = person;

	//person = (Person*)dog;

	//person = (Person*)animal;

	/*person = (Person*)dog;
	person->printInfo();*/


	return 0;
}