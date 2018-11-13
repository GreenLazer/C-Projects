#include <stdio.h>

int sum(int k){
    if(k>0){
      return(k+sum(k-1));
    }
    else{
      return 0;

    }

}

int main(){
  int x;
  x=sum(6);
  printf("%d\n", x);
  return 0;

}
