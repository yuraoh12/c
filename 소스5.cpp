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

- ��, ������ �Ǹ鼭 �ٷ� ����� �Ǵ� ���� �ƴ϶� ������ ���� �Ǽ� ����Լ��� ������ 1�� ��ȯ �� ��,
- �� ���� ������ �ö󰡸鼭 ����� �Ѵ�.
*/

int main() {

    int num;

    printf("���ڸ� �Է��� �ּ��� >> ");
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

        printf("���ڸ� �Է��� �ּ��� >> ");
        scanf_s("%lld", &num);

        printf("%lld! = %lld", num, factorial(num));


        /*
        13! = 1932053504 // ��°��
        13! = 6,227,020,800 // ���� ��� ���
        int : -2,147,483,648 ~ 2,147,483,647
        */
        
