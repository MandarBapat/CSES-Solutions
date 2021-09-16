#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);

  for(int i=1;i<=t;i++){
    int n;
    scanf("%d", &n);

    int temp;
    long int sum = 0;
    for(int j=0;j<n;j++){
      scanf("%d", &temp);
      sum = sum ^ temp;
    }

    if(sum == 0){
      printf("second\n");
    }
    else{
      printf("first\n");
    }
  }
}
