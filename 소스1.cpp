#include <stdio.h>
#include <string.h>

int main(void) {

  char name[20] = "john";

  printf("%s\n", name);

  // name = "chris"; // 이렇게는 안됨.

  // 아래와 같이 문자 하나씩 복사해야함.
  // name[0] = "chris"[0];
  // name[1] = "chris"[1];
  // name[2] = "chris"[2];
  // name[3] = "chris"[3];
  // name[4] = "chris"[4];
  // name[5] = "chris"[5];

  // 그런데 하나씩 복사하기에 너무 번거로움. 
  // 그래서 문자열 복사 함수를 제공함. string.h 헤더를 include해야함.
  // strcpy(복사되어야하는 주소, 복사 대상 주소);
  
  strcpy(name, "chris"); // 이렇게 해야 함.


  printf("%s\n", name);

  
  return 0;
}
