#include <iostream>

using namespace  std;

class �ڵ��� {
private :
	int ����;
	string ��;


public :
	void ���ݼ���(int a) {

		if (a < 0) {
			���� = 0;
		}
		else {
			���� = a;
		}
	}

int	���ݰ�������() {
	return ����;
	}
};

class ����� {
public : 
	string ǰ��;
	int ����;
};

int main() {

	�ڵ��� h1;
	h1.���ݼ���(1200000);


	cout << h1.���ݰ�������() << endl;

	�ڵ��� h2;


int main() {
	//�����Ҵ� -> 1.��Ÿ�Ӷ� �Ҵ�, 2.���� �Ҵ� 
/*
* int* a = (int*)malloc(sizof(int) * 3);
person* p = (person*) malloc(sizeof(person));
free(p);
*/
int* a = (int*)malloc(sizof(int) * 3);
person* p = (person*) malloc(sizeof(person));
free(p);


p->age = 100;

a[0] = 100;
a[1] = 200;
a[2] = 300;
 
 cout << a[0] << "," <<a[1] << "," <<a[2] << endl;

 int* b = new int[3];
 Person* p2 = new Person();

 delete p2;
 p2->age = 30;

 b[0] = 400;
 b[1] = 500;
 b[2] = 600;

cout << b[0] << "," << b[1] << "," << b[2] << endl;

cout << p2->age << endl;

return 0;
}

