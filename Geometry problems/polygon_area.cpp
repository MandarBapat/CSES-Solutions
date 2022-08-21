#include <bits/stdc++.h>
 
using namespace std;
 
long long int cmp_mul(long long int x1, long long int y1, long long int x2, long long int y2){
    return x1*y2 + y1*x2;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    long long int area = 0;
 
    long long int prev_x, prev_y, sx, sy;
    cin >> prev_x >> prev_y;
    sx = prev_x;
    sy = prev_y;
 
    for(int i=1;i<n;i++){
        long long int x, y;
        cin >> x >> y;
 
        area += cmp_mul(prev_x, -prev_y, x, y);
 
        prev_x = x;
        prev_y = y;
    }
 
    area += cmp_mul(prev_x, -prev_y, sx, sy);
    cout << abs(area);
    return 0;
}
