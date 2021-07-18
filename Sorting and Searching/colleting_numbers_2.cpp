#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  scanf("%d %d", &n, &m);

  int arr[n+1] = {0};
  int p[n+2] = {0};
  p[n+1] = n+1;
  int temp;
  for(int i=1;i<=n;i++){
    scanf("%d", &temp);
    arr[i] = temp;
    p[temp] = i;
  }

  int count = 1;
  for(int i=1;i<n;i++){
    if(p[i] > p[i+1]){
      count++;
    }
  }

  int a,b;
  for(int i=0;i<m;i++){
    scanf("%d %d", &a, &b);

    if(p[arr[a]-1] < p[arr[a]] && b <= p[arr[a]-1]){
      count++;
    }
    else if(p[arr[a]-1] > p[arr[a]] && b >= p[arr[a]-1]){
      count--;
    }
    if(p[arr[a]+1] > p[arr[a]] && b >= p[arr[a]+1]){
      count++;
    }
    else if(p[arr[a]+1] < p[arr[a]] && b <= p[arr[a]+1]){
      count--;
    }

    if(p[arr[b]-1] < p[arr[b]] && a <= p[arr[b]-1]){
      count++;
    }
    else if(p[arr[b]-1] > p[arr[b]] && a >= p[arr[b]-1]){
      count--;
    }
    if(p[arr[b]+1] > p[arr[b]] && a >= p[arr[b]+1]){
      count++;
    }
    else if(p[arr[b]+1] < p[arr[b]] && a <= p[arr[b]+1]){
      count--;
    }

    printf("%d\n",count);

    p[arr[a]] = b;
    p[arr[b]] = a;

    int temp2 = arr[a];
    arr[a] = arr[b];
    arr[b] = temp2;
  }
}
