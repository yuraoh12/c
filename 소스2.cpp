#include <stdio.h>

struct Person {
  int age;  
  char name[20];
};

int main(void) {

  struct Person p1 = {20, "홍길동"};
  struct Person p2 = {22, "이순신"};
  struct Person p3 = {23, "황진이"};

  printf("%s\n", p1.name);
  printf("%s\n", p2.name);
  printf("%s\n", p3.name);


  // 구조체가 많아지면, 구조체를 일괄적으로 다루기 위해 배열이 필요.
  // 구조체 배열 사용.
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int arr[4] = {a,b,c,d};

  struct Person people[3] = {p1, p2, p3};

  printf("%s\n", people[0].name) ;// p1.name; 
  printf("%s\n", people[1].name) ;// p2.name; 
  printf("%s\n", people[2].name) ;// p3.name; 

  for(int i = 0; i < 3; i++) {
    printf("%s\n", people[i].name) ;// p3.name; 
  }
  printf("=============================================================\n");

  struct Person people2[3]; // 3명의 사람이 존재.
  
  // 배열은 수정이 불가능.하므로 strcpy를 이용해서 문자열 복사하기.
  // people2[0].name = "이순신"; // 이렇게는 안됨.
  strcpy(people2[0].name, "이순신");

  scanf("%s", people2[0].name); // scanf를 이용해 입력값을 저장하려면 char* 변수는 안되고 꼭 배열로 해야함.
  
  printf("%s\n", people2[0].name);
  

  
    
  return 0;
}
