#include <stdio.h>

#pragma warning (disable: 4996)

#define NAMES_COUNT 5 
int main(void) {

    char names[NAMES_COUNT][20];
    //20����Ʈ�� 10����
     //19����Ʈ��ŭ ����ȴ�.
    for (int i = 0; i < NAMES_COUNT; i++) {
        printf("%d��° ����� �̸��� �Է����ּ��� : ", i + 1);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < NAMES_COUNT; i++) {
        printf("%d��° ����� �̸�: %s\n", i + 1, names);

    }
    return 0;
}