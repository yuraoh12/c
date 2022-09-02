
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctime>

enum class Time
{
	Morning, Afternoon, Night
};

class Animal {
public:
	char name[50];
	Animal(const char* name) {
		strcpy(this->name, name);
	}

	virtual int getLegs() = 0; //������ִ� �ְ� ���������Լ��̱� ������ ��ü�� ��������ߵ� �ʼ���!!
	//���� ����ϰԵǸ� ��ӹ��� �ֵ��� �������ϴ� ���̹Ƿ� ���� ���ٰ� �� �� ����.

	void printInfo() {
		printf("�̸� : %s, �ٸ� : %d\n", name, getLegs());
	}
};
class Person : public Animal {
private:
	Time time = Time::Morning;
public:
	Person(const char* name) :Animal(name) {}
	virtual int getLegs() {
		switch (time) {
		case Time::Morning:return 4;
		case Time::Afternoon:return 2;
		case Time::Night:return 3;
		}
		return 2;
	}
	void setTime(Time t) {
		this->time = t;
	}
};
class Dog : public Animal {
public:
	Dog() :Animal("��") {}
	virtual int getLegs() {
		return 4;
	}
};

int main() {
	// Animal* animal = new Animal("abcd");
	Person* person = new Person("�浿");
	person->setTime(Time::Afternoon);
	person->printInfo();

	Dog* dog = new Dog;
	dog->printInfo();

	return 0;

}