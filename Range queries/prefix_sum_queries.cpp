#include <bits/stdc++.h>

using namespace std;

void build_tree(int arr[], long long int tree[], int l, int r, int index, int len){
  if(index < len){
    if(l==r){
      tree[index] = arr[l];
    }
    else{
      int mid = l + (r-l)/2;
      build_tree(arr,tree,l,mid,2*index+1,len);
      build_tree(arr,tree,mid+1,r,2*index+2,len);
      tree[index] = 
    }
  }
}

int main(){
  int n,q;
  scanf("%d %d", &n, &q);

  int arr[n];

  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  int len = (int)ceil(log2(n));
  len = 2*(int)pow(2,len) - 1;

  long long int tree[len];
  int l = 0;
  int r = n-1;
  int index = 0;
  build_tree(arr,tree,l,r,index,len);
}
