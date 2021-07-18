#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  scanf("%d", &n);

  int arr[n], z[n];
  int temp2;

  for(int i=0;i<n;i++){
    scanf("%d", &temp2);
    arr[i] = temp2;
    z[i] = temp2;
  }

  long int max = INT_MIN;
  long int temp = 0;
    for(int i=0;i<n;i++){
      temp = temp + arr[i];
      if(temp > max){
        max = temp;
      }
      if(temp < 0){
        temp = 0;
      }
    }

    printf("%ld", max);
}
