#include <stdio.h>

int main() {

	int a = 20;

	printf("=========싱글 포인터 ======\n");
	int* p;
	p = &a;

	printf("========2중 포인터=======");

	int** pp;//pp가 가리키는 곳을 가보면 int*가 나온다. 
	pp = &p;
	printf("*pp : %d\n", (long)*pp);
	printf("p: %ld\n", (long)p);

	printf("**pp: %d\n", **pp);
	printf("a: %d\n", a);


	printf("========3중 포인터=======");
	int*** ppp;
	ppp = &pp;
	printf("*ppp : %ld\n", (long)*ppp);
	printf("*pp : %ld\n", (long)pp);

	printf("**ppp: %ld\n", (long)**ppp);
	printf("a:%d\n", a);

	return 0;
}