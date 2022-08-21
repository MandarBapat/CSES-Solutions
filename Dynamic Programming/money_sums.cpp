#include <bits/stdc++.h>

using namespace std;

#define M ((int)(1e6))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int c[n];

    for(int i=0;i<n;i++){
        cin >> c[i];
    }

    bitset<M> b;

    for(int i=n-1;i>=0;i--){
        if(i == n-1){
            b.set(c[i], 1);
        }
        else{
            b = b | (b << c[i]);
            b.set(c[i], 1);
        }
    }

    cout << b.count() << "\n";

    for(int i=1;i<=((int)(1e5));i++){
        if(b[i] == 1){
            cout << i << " ";
        }
    }

}