#include <stdio.h>

int main() {

	int a = 20;

	printf("=========�̱� ������ ======\n");
	int* p;
	p = &a;

	printf("========2�� ������=======");

	int** pp;//pp�� ����Ű�� ���� ������ int*�� ���´�. 
	pp = &p;
	printf("*pp : %d\n", (long)*pp);
	printf("p: %ld\n", (long)p);

	printf("**pp: %d\n", **pp);
	printf("a: %d\n", a);


	printf("========3�� ������=======");
	int*** ppp;
	ppp = &pp;
	printf("*ppp : %ld\n", (long)*ppp);
	printf("*pp : %ld\n", (long)pp);

	printf("**ppp: %ld\n", (long)**ppp);
	printf("a:%d\n", a);

	return 0;
}