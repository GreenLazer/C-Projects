#include <stdio.h>

void loop(int i){
  if(i>1){
    printf("Hello\n");
    loop(i-1);
  }
  else{
    return ;
  }

}

int main(){

loop(5);

  return 0;
}
