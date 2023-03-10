#include <stdio.h>

void print_arr(int* arr, int size) {
  for(int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {

  // 배열의 삭제 구현
  int arr[100] = {1,2,3,4,5}; // arr 배열 데이터
  int arr_len = 5; // arr이 저장하고 있는 실제 데이터의 개수
  int del_idx = 3; // 삭제하고 싶은 대상 index

  printf("삭제 전 : ");
  print_arr(arr, arr_len); // 1 2 3 4 5
  
  // ===========================================
  // 삭제 구현

  // v1. 
  for(int i = 0; i < arr_len - 1 - del_idx ; i++) {
    arr[del_idx + i] = arr[del_idx + i + 1];    
  }
  arr_len--;


  // v2.
  // for(int i = del_idx; i < arr_len - 1; i++) {
  //   arr[i] = arr[i + 1];    
  // }
  // arr_len--;
  
  // ===========================================

  
  printf("삭제 후 : ");
  print_arr(arr, arr_len); // 1 2 3 5
   
  
  return 0;
}
