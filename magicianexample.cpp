#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class AttackBehavior1 {
public:
	void doAttack(string name, int attack) const {
		cout << name << "이 칼을 휘둘러 " << attack << "의 데미지를 입힙니다." << endl;
	}
};

class AttackBehavior2 {
public:
	void doAttack(string name, int attack) const {
		cout << name << "이 화염구를 던져 " << attack << "의 데미지를 입힙니다." << endl;
	}
};

class MoveBehavior {
public:
	void doMove(string name) const {
		cout << name << "이 움직입니다." << endl;
	}
};

class MoveBehavior2 {
public:
	void doMove(string name) const {
		cout << name << "이 하늘을 날아갑니다." << endl;
	}
};

class Magician {
private:
	string name;
	int attack;
	AttackBehavior2 attackBehavior; // 마법사에게는 공격행위2를 세팅
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
	AttackBehavior1 attackBehavior; // 전사에게는 공격행위1을 세팅
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

	Warrior c1("홍길동", 20);
	c1.doAttack(); // 홍길동이 칼을 휘둘러 20의 데미지를 입힙니다.
	c1.doMove(); // 홍길동이 움직입니다.

	Magician c2("홍길순", 15);
	c2.doAttack(); // 홍길순이 화염구를 던져 15의 데미지를 입힙니다.
	c2.doMove(); // 홍길순이 움직입니다.

	return 0;
}