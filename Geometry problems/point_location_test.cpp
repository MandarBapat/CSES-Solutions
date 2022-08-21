#include <bits/stdc++.h>

using namespace std;


long long int cmp_mul(long long int x1, long long int y1, long long int x2, long long int y2){
    return x1*y2 + y1*x2;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        long long int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        long long int prod = cmp_mul(x2-x1, -(y2-y1), x3-x1, y3-y1);
        if(prod > 0){
            cout << "LEFT\n";
        }
        else if(prod < 0){
            cout << "RIGHT\n";
        }
        else{
            cout << "TOUCH\n";
        }
    }
}