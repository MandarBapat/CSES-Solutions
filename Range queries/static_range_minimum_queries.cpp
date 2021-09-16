#include <bits/stdc++.h>

using namespace std;


void build_tree(int arr[], int tree[], int l, int r, int index, int len){
  if(index < len){
    if(l==r){
      tree[index] = arr[l];
    }
    else{
      int mid = l + (r-l)/2;
      build_tree(arr, tree, l, mid, 2*index+1,len);
      build_tree(arr, tree, mid+1, r, 2*index+2, len);
      tree[index] = min(tree[2*index+1], tree[2*index+2]);
    }
  }
}

int min_query(int tree[], int l, int r, int index, int ql, int qr, int len){
  if(index < len){
    if( (ql<=l && l<=qr) && (ql<=r && r<=qr) ){
      return tree[index];
    }
    else if( r < ql || l > qr ){
      return INT_MAX;
    }
    else{
      int mid = l + (r-l)/2;
      return min(min_query(tree,l,mid,2*index+1,ql,qr,len),min_query(tree,mid+1,r,2*index+2,ql,qr,len));
    }
  }
  else{
    return INT_MAX;
  }
}

int main(){
  int n,q;
  scanf("%d %d", &n, &q);

  int arr[n];
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  int len = ceil(log2(n));
  len = 2*(int)pow(2,len) - 1;
  int tree[len];
  int l = 0;
  int r = n-1;
  int index = 0;

  build_tree(arr, tree, l, r, index, len);

  for(int i=1;i<=q;i++){
    int a,b;
    scanf("%d %d", &a, &b);

    printf("%d\n", min_query(tree,l,r,index,a-1,b-1,len));
  }
}
