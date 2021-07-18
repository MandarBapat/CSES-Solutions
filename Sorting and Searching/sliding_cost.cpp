#include <iostream>


using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>


int main(){
  int n,k;
  scanf("%d %d", &n, &k);

  int mid;
  int median;
  if(k%2 ==0){
    mid = k/2 - 1;
  }
  else{
    mid = k/2;
  }

  ordered_set set1;
  int arr[n];

  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  long int cost = 0;

  for(int i=0;i<k;i++){
    set1.insert({arr[i],i});
  }
  auto itr2 = set1.begin();
  auto itr3 = set1.end();
  advance(itr3,-1);
  while(itr3->first >= itr2->first && itr2 != set1.end() && itr3 != set1.begin()){
      cost = cost - itr2->first + itr3->first;
    advance(itr2,1);
    advance(itr3,-1);
  }
  printf("%ld ", cost);

  int count = k;
  while(count < n){
    cost = 0;
    set1.erase(set1.find({arr[count-k],count-k}));
    set1.insert({arr[count],count});
    itr2 = set1.begin();
    itr3 = set1.end();
    advance(itr3,-1);
    while((itr3->first) >= (itr2->first) && itr2 != set1.end() && itr3 != set1.begin()){
        cost = cost - (itr2->first) + (itr3->first);
      advance(itr2,1);
      advance(itr3,-1);
    }
    printf("%ld ", cost);
    count++;
  }
}
