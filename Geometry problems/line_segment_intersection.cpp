#include <bits/stdc++.h>


using namespace std;

int main(){
  int t;
  scanf("%d", &t);

  for(int i=1;i<=t;i++){
    complex<long long> p1,p2,p3,p4;
    long long int a,b;

    scanf("%lld %lld", &a, &b);
    p1 = {a,b};

    scanf("%lld %lld", &a, &b);
    p2 = {a,b};

    scanf("%lld %lld", &a, &b);
    p3 = {a,b};

    scanf("%lld %lld", &a, &b);
    p4 = {a,b};

    if((p2==p3) || (p2==p4) || (p1==p3) || (p1==p4)){
      printf("YES\n");
    }
    else if(((conj(p3-p1)*(p2-p1)).imag())==0  && ((conj(p4-p1)*(p2-p1)).imag())==0){
      long long int max1 = max(p1.real(),p2.real());
      long long int min1 = min(p1.real(),p2.real());

      long long int max2 = max(p1.imag(),p2.imag());
      long long int min2 = min(p1.imag(),p2.imag());

      long long int max3 = max(p3.real(),p4.real());
      long long int min3 = min(p3.real(),p4.real());

      long long int max4 = max(p4.imag(),p3.imag());
      long long int min4 = min(p4.imag(),p3.imag());

      bool var1 = (p3.real() <= max1) && (p3.real() >= min1) && (p3.imag() <= max2) && (p3.imag() >= min2);
      bool var2 = (p4.real() <= max1) && (p4.real() >= min1) && (p4.imag() <= max2) && (p4.imag() >= min2);
      bool var3 = (p1.real() <= max3) && (p1.real() >= min3) && (p1.imag() <= max4) && (p1.imag() >= min4);
      bool var4 = (p2.real() <= max3) && (p2.real() >= min3) && (p2.imag() <= max4) && (p2.imag() >= min4);

      if(var1 || var2 || var3 || var4){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    else{
      long long int l1,l2,r1,r2;
      l1 = (conj(p2-p1)*(p3-p1)).imag();
      r1 = (conj(p2-p1)*(p4-p1)).imag();
      l2 = (conj(p4-p3)*(p1-p3)).imag();
      r2 = (conj(p4-p3)*(p2-p3)).imag();
      bool var1 = (l1 <= 0) && (r1 >= 0);
      bool var2 = (l1 >= 0) && (r1 <= 0);
      bool var3 = (l2 <= 0) && (r2 >= 0);
      bool var4 = (l2 >= 0) && (r2 <= 0);
      if( (var1 || var2) && (var3 || var4) ){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
  }
}
