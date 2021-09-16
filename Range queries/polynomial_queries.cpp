#include <bits/stdc++.h>

using namespace std;

void build_tree(int arr[], long long int tree[], int l, int r, int index, int len){
  if(index < len){
    if(l==r){
      tree[index] = arr[l];
    }
    else{
      int mid = l + (r-l)/2;
      build_tree(arr, tree, l, mid, 2*index+1, len);
      build_tree(arr, tree, mid+1, r, 2*index+2, len);
      tree[index] = tree[2*index+1] + tree[2*index+2];
    }
  }
}

long long int val_query(long long int tree[], int l, int r, int index, int ql, int qr, int len){
  if(index < len){
    if((ql<=l && l<=qr) && (ql<=r && r<=qr)){
      return tree[index];
    }
    else if(r < ql || l > qr){
      return 0;
    }
    else{
      int mid = l + (r-l)/2;
      return val_query(tree,l,mid,2*index+1,ql,qr,len) + val_query(tree,mid+1,r,2*index+2,ql,qr,len);
    }
  }
  else{
    return 0;
  }
}

void update_query(long long int tree[], int l, int r, int index, int ql, int qr, int len){
  if(index < len){
    if((ql<=l && l<=qr) && (ql<=r && r<=qr)){
      long long int sum1 = ((r-ql+1)*(r-ql+2))/2;
      long long int sum2 = (((l-1)-ql+1)*((l-1)-ql+2))/2;
      tree[index] = tree[index] + sum1 - sum2;
      int mid = l + (r-l)/2;
      update_query(tree, l, mid, 2*index+1, ql, qr, len);
      update_query(tree, mid+1, r, 2*index+2, ql, qr, len);
    }
    else if(r < ql || l > qr){
      return;
    }
    else{
      int mid = l + (r-l)/2;
      update_query(tree, l, mid, 2*index+1, ql, qr, len);
      update_query(tree, mid+1, r, 2*index+2, ql, qr, len);
    }
  }
  else{
    return;
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

  int l = 0;
  int r = n-1;
  int index = 0;
  long long int tree[len];

  build_tree(arr, tree,l, r, index, len);

  for(int i=1;i<=q;i++){
    int temp,a,b;
    scanf("%d %d %d", &temp, &a, &b);

    if(temp == 1){
      update_query(tree, l, r, index, a-1,b-1,len);
    }
    else{
      printf("%lld\n", val_query(tree, l, r, index, a-1, b-1, len));
    }
  }
}
