#include<stdio.h>

int main(void) {

	char a;

	printf("%p\n", &a);
	printf("%p\n", &a + 11);

	printf("%x\n", 100000);
	printf("%x\n", 100000 + 1);

	printf("%d\n", 0x186a0);
	printf("%ld\n", &a);
 

	int b = 10.1;
	printf("%d\n", (long)b);
	printf("%ld\n", (long)&a + 1);
	printf("%ld\n", (long)&a + 10);
	printf("%ld\n", (long)&a + 100);
	printf("========================\n");
	printf("%d\n", (long)&b);
	printf("%ld\n", (long)(& b + 1));
	printf("%ld\n", (long)(&b + 10));
	printf("%ld\n", (long)(&b + 100));
	printf("========================\n");
	printf("%d\n", (long)&b);
	printf("%ld\n", (long)&b + 1);
	printf("%ld\n", (long)&b + 10);
	printf("%ld\n", (long)&b + 100);


	return 0;
}

