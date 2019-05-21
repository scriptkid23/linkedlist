#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(int argc, char const *argv[]) {

  int **a;
  a = (int**)malloc(3*sizeof(int));
  for(int i = 0 ; i <3 ; i++){
    a[i] = (int*)malloc(5*sizeof(int));


  }
  for(int i = 0 ; i <3 ;i++){
    for(int j = 0; j <5;j++){
      printf("%p\n",&a[i][j]);
    }
  }

  return 0;
}
