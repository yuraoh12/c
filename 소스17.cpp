#include <stdio.h>

#pragma warning (disable: 4996)

#define NAMES_COUNT 5 
int main(void) {

    char names[NAMES_COUNT][20];
    //20바이트씩 10묶음
     //19바이트만큼 저장된다.
    for (int i = 0; i < NAMES_COUNT; i++) {
        printf("%d번째 사람의 이름을 입력해주세요 : ", i + 1);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < NAMES_COUNT; i++) {
        printf("%d번째 사람의 이름: %s\n", i + 1, names);

    }
    return 0;
}