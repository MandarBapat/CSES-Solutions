#include <bits/stdc++.h>

using namespace std;

void build_tree(long long int arr[], long long int tree[], int l, int r, int index, int len){
  if(index < len){
    if(l==0){
      tree[index] = arr[r];
    }
    else{
      tree[index] = arr[r] -arr[l-1];
    }
    int mid = l + (r-l)/2;
    build_tree(arr, tree, l,mid, 2*index+1, len);
    build_tree(arr, tree, mid+1, r, 2*index+2, len);
  }
}


long long int sum_query(long long int tree[], int l, int r, int index, int ql, int qr, int len){
  if(index < len){
    int mid = l + (r-l)/2;
    if( (ql<=l && l<=qr) && (ql <= r && r <= qr) ){
      return tree[index];
    }
    else if( r < ql || l > qr ){
      return 0;
    }
    else{
      return sum_query(tree, l,mid, 2*index+1, ql, qr, len) + sum_query(tree, mid+1,r, 2*index+2, ql, qr, len);
    }
  }
  else{
    return 0;
  }
}

void update(long long int tree[], int l, int r, int index1, int index2, int diff, int  len){
  if(index1 < len ){
    if(index2 >=l && index2 <=r){
      tree[index1] += diff;
      int mid = l + (r-l)/2;
      update(tree, l, mid, 2*index1+1,index2,diff, len);
      update(tree, mid+1, r, 2*index1+2,index2,diff, len);
    }
  }
}

int main(){
  int n,q;
  scanf("%d %d", &n, &q);

  int arr[n];
  long long int p[n];
  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
    if(i==0){
      p[i] = arr[i];
    }
    else{
      p[i] = p[i-1] + arr[i];
    }
  }

  int len = ceil(log2(n));
  len = 2*(int)pow(2, len) - 1;
  long long int tree[len];
  int l = 0;
  int r = n-1;
  int index = 0;

  build_tree(p, tree, l, r, index, len);

  for(int i=1;i<=q;i++){
    int temp, a, b;
    scanf("%d %d %d", &temp, &a, &b);

    if(temp == 1){
      update(tree,l,r,index,a-1,b-arr[a-1], len);
      arr[a-1] = b;
    }
    else{
      printf("%lld\n", sum_query(tree, l, r, index, a-1, b-1, len));
    }
  }
}
