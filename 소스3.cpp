#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cstdlib>

//접근 지정자 : public, protected, private

class Animal {
	/*public:*/ //누구든 접근 가능
	/*protected:*/  //외부에서 접근 불가능 대신 내부에서는 접근 가능 (상속받은 클래스는 접근 가능)
private: // 해당 클래스 내에서만 접근 가능 (상속받은 클래스도 접근 불가)
	int legs;
	char name[50];
public:
	Animal(int legs, const char* name) {
		printf("동물생성자 실행됨\n");
		this->legs = legs;
		strcpy(this->name, name);
	}

	void printInfo() {
		printf("다리의 갯수 : %d\n", legs);
		printf("이름 : %s\n", name);
	}
};

class Dog : public Animal {
public:
	Dog() : Animal(4, "개") {
		printf("Dog 생성자 실행됨\n");
	}
};

class Person : public Animal {
public:
	char regist_no[30];

	Person(const char* regist_no) : Animal(2, "사람") {
		printf("사람생성자 실행됨\n");
		strcpy(this->regist_no, regist_no);
		//legs = 2;
		//strcpy(name, "사람");
	}

	void printLegs() {
		printf("Person의 다리 : %d\n", this->legs);
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