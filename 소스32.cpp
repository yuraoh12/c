#include <stdio.h>
#include <stdlib.h>

//int�迭 �����Ҵ�

#define true 1
#define false 0

typedef int bool;

int main(void) {
    int* arr; // 8
    int size; // 4

    printf("�����ؾ� �ϴ� ���ڸ� �Է����ּ��� : ");
    scanf("%d", &size); // 100

    arr = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        printf("%d��° ���ڸ� �Է����ּ��� : ", i);
        scanf("%d", arr + i);
    }

    printf("== ���� ��� ==\n");
    for (int i = 0; i < size; i++) {
        printf("%d��° ���� : %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

/*
//int�迭 �����Ҵ� 
#include <stdio.h>

#define MAX_SIZE 600
#define true 1
#define false 0

typedef int bool;

int main(void) {
    int arr[MAX_SIZE];
    int size;

    while (true) {
        printf("�����Ͻ� ���ڸ� �Է����ּ��� : ");
        scanf("%d", &size);

        if (size > MAX_SIZE) {
            printf("== %d ���Ϸ� �Է����ּ���.==\n", MAX_SIZE);
        }
        else {
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d��° ���ڸ� �Է����ּ��� : ", i);
        scanf("%d", arr + i);
    }

    printf("== ���� ��� ==\n");
    for (int i = 0; i < size; i++) {
        printf("%d��° ���� : %d\n", i, arr[i]);
    }

    return 0;
}
*/