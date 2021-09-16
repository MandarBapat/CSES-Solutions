#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  scanf("%d",&n);

  complex<long long int> p[n+1];

  long long int temp1,temp2;

  for(int i=0;i<n;i++){
    scanf("%lld %lld", &temp1, &temp2);
    p[i] = {temp1, temp2};
  }
  p[n] = p[0];

  long long int area = 0;

  for(int i=0;i<n;i++){
    area = area + (conj(p[i])*p[i+1]).imag();
  }

  printf("%lld", abs(area));
}
