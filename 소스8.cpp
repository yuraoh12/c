#include <iostream>

using namespace  std;

class 핸드폰 {
private :
	int 가격;
	string 모델;


public :
	void 가격세팅(int a) {

		if (a < 0) {
			가격 = 0;
		}
		else {
			가격 = a;
		}
	}

int	가격가져오기() {
	return 가격;
	}
};

class 고양이 {
public : 
	string 품종;
	int 나이;
};

int main() {

	핸드폰 h1;
	h1.가격세팅(1200000);


	cout << h1.가격가져오기() << endl;

	핸드폰 h2;


int main() {
	//동적할당 -> 1.런타임때 할당, 2.힙에 할당 
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

