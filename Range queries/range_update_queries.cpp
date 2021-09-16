#include <bits/stdc++.h>

using namespace std;

void update_query(long long int tree[], int l, int r, int index, int ql, int qr, int val, int len){
  if(index < len){
    if((ql <= l && l <= qr) && (ql<=r && r<=qr)){
      tree[index] += val;
    }
    else if(r < ql || l > qr){
      return;
    }
    else{
      int mid = l + (r-l)/2;
      update_query(tree, l, mid, 2*index+1, ql, qr, val, len);
      update_query(tree, mid+1, r, 2*index+2, ql, qr, val, len);
    }
  }
}

long long int val_query(long long int tree[], int l, int r, int index1, int index2, int len){
  if(index1 < len){
    if(l<= index2 && index2 <= r){
      int mid = l + (r-l)/2;
      return tree[index1] + val_query(tree,l,mid, 2*index1+1,index2, len) + val_query(tree,mid+1,r, 2*index1+2,index2, len);
    }
    else if(index2 < l || index2 > r){
      return 0;
    }
  }
  else{
    return 0;
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

  long long int tree[len] = {0};
  int l =0;
  int r= n-1;
  int index = 0;

  for(int i=1;i<=q;i++){
    int temp;
    scanf("%d", &temp);

    if(temp == 1){
      int a,b,u;
      scanf("%d %d %d", &a, &b, &u);

      update_query(tree,l,r,index,a-1,b-1,u,len);
    }
    else{
      int k;
      scanf("%d",&k);

      long long int final = val_query(tree, l, r, index, k-1, len);
      printf("%lld\n", final + arr[k-1]);
    }
  }
}
