#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,q;
  scanf("%d %d", &n, &q);

  long int arr[n];
  long int temp;
  unordered_set<long long int> set1;

  for(int i =0;i<n;i++){
    scanf("%ld", &temp);
    set1.insert(temp);
    arr[i] = set1.size();
  }

  int a,b;

  for(int i=1;i<=q;i++){
    scanf("%d %d", &a, &b);
    if(a==1){
      printf("%ld\n", arr[b-1]);
    }
    else{
      if(arr[a-2] == arr[b-1]){
        printf("1\n");
      }
      else{
        printf("%ld\n", arr[b-1] - arr[a-2]);
      }
    }
  }
}
