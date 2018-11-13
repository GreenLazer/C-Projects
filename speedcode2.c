#include <stdio.h>

// 0 1 1 3 5 13 21
int fib(int n){
  if(n==0){
    return 0;
  }
  else if(n==1){
      return 1;
  }
  else{
    return fib(n-1)+fib(n-2);
  }

}

int main(){
  int n=0;
  printf("What is your number?\n");
  scanf("%d", n);
  int out;
  out=fib(n);
  printf("%d\n", out);

  return 0;
}
