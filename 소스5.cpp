#include <stdio.h>
#include<string.h>

int  factorial(int n) {

    if (n == 1) {
        return 1;
    }

    return n * factorial(n - 1);

}

/*
5 * factorial(5-1) :  = 120
4 * factorial(4-1)
3 * factorial(3-1)
2 * factorial(2-1)
return 1

- 즉, 실행이 되면서 바로 계산이 되는 것이 아니라 조건이 참이 되서 재귀함수를 끝내고 1을 반환 할 때,
- 그 값을 가지고 올라가면서 계산을 한다.
*/

int main() {

    int num;

    printf("숫자를 입력해 주세요 >> ");
    scanf_s("%d", &num);

    printf("%d! = %d", num, factorial(num));



        long long factorial(int n) {

        if (n == 1) {
            return 1;
        }

        return n * factorial(n - 1);

    }

    /*
    factorial(5) : 5 * 24  = 120
    factorial(5) : 4 * 6
    factorial(5) : 3 * 2
    factorial(5) : 2 * 1
    factorial(5) : return 1
    */

    int main() {

        long long num;

        printf("숫자를 입력해 주세요 >> ");
        scanf_s("%lld", &num);

        printf("%lld! = %lld", num, factorial(num));


        /*
        13! = 1932053504 // 출력결과
        13! = 6,227,020,800 // 실제 계산 결과
        int : -2,147,483,648 ~ 2,147,483,647
        */
        
