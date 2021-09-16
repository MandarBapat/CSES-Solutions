#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  long int q;
  scanf("%d %ld", &n, &q);

  int arr[n][n];
  string s;
  for(int i=0;i<n;i++){
    cin >> s;
    for(int j=0;j<n;j++){
      if(s[j]=='*'){
        if(j==0){
          arr[i][j]=1;
        }
        else{
          arr[i][j] = arr[i][j-1] + 1;
        }
      }
      else{
        if(j==0){
          arr[i][j]=0;
        }
        else{
          arr[i][j] = arr[i][j-1];
        }
      }
    }
  }

  int x1,x2,y1,y2;

  for(long int i=1;i<=q;i++){
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    long int sum = 0;
    for(int j=(y1-1);j<=(y2-1);j++){
      if(x1==1){
        sum = sum + arr[j][x2-1];
      }
      else{
        sum = sum + arr[j][x2-1] - arr[j][x1-2];
      }
    }
    printf("%ld\n",sum);
  }
}
