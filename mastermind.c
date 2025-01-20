#include"mastermind.h"

int main(){
  mastermind();
}

void mastermind(){
  int arr[5] = {-1, -1, -1, -1 -1};
  srand(time(NULL));
  for(int i = 0; i < 5; i++){
    int num = random()%10;
    while(check_repeats(num, arr))
      num = random()%10;
    arr[i] = num;
    printf("arr[%d]: %d\n", i, arr[i]);
  }
}


int check_repeats(int n, int arr[]){
  for(int i = 0; i < 5; i++)
    if(n == arr[i])
      return 1;
  return 0;
}
