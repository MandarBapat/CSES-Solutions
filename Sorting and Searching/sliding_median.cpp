#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
  int n,k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  ordered_set set1;

  int mid;
  if(k%2 == 0){
    mid = k/2-1;
  }
  else{
    mid = k/2;
  }

  for(int i=0;i<k;i++){
    set1.insert({arr[i],i});
  }
  printf("%d ", *(set1.find_by_order(mid)));
  int count = k;

  while(count<n){
    set1.erase(set1.find({arr[count-k],count-k}));
    set1.insert({arr[count],count});
    printf("%d ", *(set1.find_by_order(mid)));
    count++;
  }
}
