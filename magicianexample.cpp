#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class AttackBehavior1 {
public:
	void doAttack(string name, int attack) const {
		cout << name << "�� Į�� �ֵѷ� " << attack << "�� �������� �����ϴ�." << endl;
	}
};

class AttackBehavior2 {
public:
	void doAttack(string name, int attack) const {
		cout << name << "�� ȭ������ ���� " << attack << "�� �������� �����ϴ�." << endl;
	}
};

class MoveBehavior {
public:
	void doMove(string name) const {
		cout << name << "�� �����Դϴ�." << endl;
	}
};

class MoveBehavior2 {
public:
	void doMove(string name) const {
		cout << name << "�� �ϴ��� ���ư��ϴ�." << endl;
	}
};

class Magician {
private:
	string name;
	int attack;
	AttackBehavior2 attackBehavior; // �����翡�Դ� ��������2�� ����
	MoveBehavior moveBehavior;

public:

	Magician(string name, int attack) :
		name(name),
		attack(attack)
	{}

	void doAttack() const {
		attackBehavior.doAttack(name, attack);
	}

	void doMove() const {
		moveBehavior.doMove(name);
	}

};

class Warrior {
private:
	string name;
	int attack;
	AttackBehavior1 attackBehavior; // ���翡�Դ� ��������1�� ����
	MoveBehavior moveBehavior;

public:
	Warrior(string name, int attack) :
		name(name),
		attack(attack)
	{}

	void doAttack() const {
		attackBehavior.doAttack(name, attack);
	}

	void doMove() const {
		moveBehavior.doMove(name);
	}

};

int main() {

	Warrior c1("ȫ�浿", 20);
	c1.doAttack(); // ȫ�浿�� Į�� �ֵѷ� 20�� �������� �����ϴ�.
	c1.doMove(); // ȫ�浿�� �����Դϴ�.

	Magician c2("ȫ���", 15);
	c2.doAttack(); // ȫ����� ȭ������ ���� 15�� �������� �����ϴ�.
	c2.doMove(); // ȫ����� �����Դϴ�.

	return 0;
}