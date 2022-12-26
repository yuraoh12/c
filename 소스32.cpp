#include <stdio.h>
#include <stdlib.h>

//int배열 동적할당

#define true 1
#define false 0

typedef int bool;

int main(void) {
    int* arr; // 8
    int size; // 4

    printf("관리해야 하는 숫자를 입력해주세요 : ");
    scanf("%d", &size); // 100

    arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        printf("%d번째 숫자를 입력해주세요 : ", i);
        scanf("%d", arr + i);
    }

    printf("== 숫자 출력 ==\n");
    for (int i = 0; i < size; i++) {
        printf("%d번째 숫자 : %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

/*
//int배열 정적할당 
#include <stdio.h>

#define MAX_SIZE 600
#define true 1
#define false 0

typedef int bool;

int main(void) {
    int arr[MAX_SIZE];
    int size;

    while (true) {
        printf("관리하실 숫자를 입력해주세요 : ");
        scanf("%d", &size);

        if (size > MAX_SIZE) {
            printf("== %d 이하로 입력해주세요.==\n", MAX_SIZE);
        }
        else {
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d번째 숫자를 입력해주세요 : ", i);
        scanf("%d", arr + i);
    }

    printf("== 숫자 출력 ==\n");
    for (int i = 0; i < size; i++) {
        printf("%d번째 숫자 : %d\n", i, arr[i]);
    }

    return 0;
}
*/