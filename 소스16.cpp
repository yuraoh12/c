#include <stdio.h>

#pragma warning (disable: 4996)

int main(void) {

	int arr[6];

	int arr2[2][3];

	//arr[0~5]
	arr[4] = 10;
	arr2[1][1] = 10;
	printf("sizeof arr: %d\n", sizeof(arr));
	printf("sizeof arr2: %d\n", sizeof(arr2));

	printf("&arr[0] : %ld\n", &arr[0]);
	printf("&arr[0] : %ld\n", &arr[4]);


	printf("&arr[4] - &arr[0] : %d\n", (long)&arr[4] - (long)&arr[0]);

	printf("&arr2[0][0] : %ld\n", &arr2[0][0]);
	printf("&arr2[1][1] : %ld\n", &arr2[1][1]);

	printf("&arr2[1][1] - &arr2[0][0] : %d\n", (long)&arr2[1][1] - (long)&arr2[0][0]);

	printf("arr2[0] : %ld\n", arr2[0]);
	printf("arr2[1] : %ld\n", arr2[1]);


	/*
	sizeof arr: 24
	sizeof arr2: 24
	&arr[0] : 140735365928032
	&arr[0] : 140735365928048
	&arr[4] - &arr[0] : 16
	&arr2[0][0] : 140735365928000
	&arr2[1][1] : 140735365928016
	&arr2[1][1] - &arr2[0][0] : 16
	arr2[0] : 140735365928000
	arr2[1] : 140735365928012
	*/

	return 0;
}